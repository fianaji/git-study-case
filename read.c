/*Source Code V 1.0*/
#include<string.h>/*strcmp*/
#include<stdio.h>/*for input output :D */
#include<errno.h>/*errno, perror*/
int main(int x,char*y[])
{
    FILE*p,*Q,*R;
    char var[1024],var2[1024],l;
    int a,er,n,xx=0;
    register int b;
    long double cc;/*please perfecting my code :(*/
    for(a=1;a<x;a++)
    {

        if(strcmp(y[a],"-c")==0)
        {
            p=fopen(y[a+1],"r");
            if(p==NULL)printf("%s\n",strerror(errno));
            else
            {
                while(!feof(p))
                {
                    b=fgetc(p);
                    printf("%c",b);
                }
                fclose(p);
            }
        }
        else if(strcmp(y[a],"-s")==0)
        {
            p=fopen(y[a+1],"r");
            if(p==NULL)printf("%s\n",strerror(errno));
            else
            {
                while(!feof(p))
                {
                    fscanf(p,"%s",var);
                    printf("%s",var);
                }
                fclose(p);
            }
        }
        else if(strcmp(y[a],"-l")==0)
        {
            p=fopen(y[a+1],"r");
            if(p==NULL)printf("%s\n",strerror(errno));
            else while(!feof(p))
            {
                fgets(var2,1024,p);
                printf("%s",var2);
            }
            fclose(p);
        }
        else if(strcmp(y[a],"ren")==0)
        {
            if(y[a+2]=='\0')printf("argumen 2 is empty\n");
            else
            {
                er=rename(y[a+1],y[a+2]);
                if(er!=0)printf("%s\n",strerror(errno));
                else printf("File renamed successfully.\n");
            }
        }
        else if(strcmp(y[a],"-cb")==0)
        {
            p=fopen(y[a+1],"rb");
            if(p==NULL)printf("%s\n",strerror(errno));
            else
            {
                while(!feof(p))
                {
                    b=fgetc(p);
                    printf("%c",b);
                }
                fclose(p);
            }
        }
        else if(strcmp(y[a],"-sb")==0)
        {
            p=fopen(y[a+1],"rb");
            if(p==NULL)printf("%s\n",strerror(errno));
            else
            {
                while(!feof(p))
                {
                    fscanf(p,"%s",var);
                    printf("%s",var);
                }
                fclose(p);
            }
        }
        else if(strcmp(y[a],"-lb")==0)
        {
            p=fopen(y[a+1],"rb");
            if(p==NULL)printf("%s\n",strerror(errno));
            else while(!feof(p))
            {
                fgets(var2,1024,p);
                printf("%s",var2);
            }
            fclose(p);
        }
        else if(strcmp(y[a],"size")==0)
        {
            p=fopen(y[a+1],"rb");
            if(p==NULL)
            {
                printf("%s\n",strerror(errno));
                return 0;
            }
            fseek(p,SEEK_SET,SEEK_END);
            cc=(int)ftell(p);/*please perfecting my code :(*/
            if(cc>1)printf("Size of (%s) is %ld bytes.\n",y[2],(int)cc);/*please perfecting my code :(*/
            else printf("Size is not detected.\n");/*please perfecting my code*/
            fclose(p);
        }

        else if(strcmp(y[a],"-h")==0||strcmp(y[a],"help")==0||strcmp(y[a],"/?")==0)
        {
            printf("Text file reader V 1.1\n");
            printf("for usage :read [option] [[drive:][path][filename]]\n");
            printf("           read [command] [[drive:][path][filename]]\n");
            printf("           read [command2] [[drive:][path][OldName]] [[drive:][path][NewName]]\n");
            printf("\tOption\t : \n");
            printf("\t -c  : read per character\n");
            printf("\t -s  : read per string\n");
            printf("\t -l  : read per line\n");
            printf("\t -cb : read per character and binary mode\n");
            printf("\t -sb : read per string and binary mode\n");
            printf("\t -lb : read per line and binary mode\n");
            printf("\t -h  : help \n");
            printf("\n\tCommand :\n");
            printf("\t rm  : remove\n");
            printf("\t size: size of file\n\n");
            printf("\tCommand2:\n");
            printf("\t ren : rename file\n");
            printf("\t copy: copy file\n\n");
            printf("\texample : read -s C:\\example.txt\n");
            printf("                  read ren \"D:\\my folder\\example.txt\" \"D:\\my folder\\ex2.txt\"\n");
            printf("                  read rm example.txt\n");
        }
        else if(strcmp(y[a],"rm")==0)
        {
            n=remove(y[a+1]);
            if(n!=0)printf("%s\n",strerror(errno));
            else printf("File removed successfully.\n");
        }
        else if(strcmp(y[a],"copy")==0)
        {
            p=fopen(y[a+1],"rb");
            if(p==NULL)
            {
                printf("%s\n",strerror(errno));
                return 0;
            }
            if(!y[a+2])
            {
                printf("syntax error, type \"read -h\" to help.\n");
                return 0;
            }
            else
            {
                R=fopen(y[a+2],"rb");
                if(R!=NULL)
                {
                    printf("File is exist, do you want replace it (y/n) ? ");
                    scanf("%c",&l);
                    if(l=='y'||l=='Y')
                    {
                        Q=fopen(y[a+2],"wb");

                        while(1)
                        {
                            b=fgetc(p);
                            xx++;
                            if(xx%18500000==0)
                            {
                                printf(".");
                            }
                            if(feof(p))break;
                            fputc(b,Q);
                        }
                        fclose(Q);
                        printf("\nFile copied successfully.\n");
                        return 0;
                    }

                    if(l!='y'||l!='Y')
                    {

                        printf("Copy is aborted.");
                        return 0;
                    }
                    fclose(R);
                }
                else
                {
                    Q=fopen(y[a+2],"wb");
                    while(1)
                    {
                        b=fgetc(p);
                        xx++;
                        if(xx%18500000==0)
                        {
                            printf(".");
                        }
                        if(feof(p))break;
                        fputc(b,Q);
                    }
                    fclose(Q);
                    printf("\nFile copied successfully.\n");
                }
            }

        }
    }
       return 0;
}

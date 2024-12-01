//mybash.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <wait.h>
#include <pwd.h>
#define  ARG_MAX  10
#define PATH_BIN "/home/stu/quzijie/test15/mybin/"
void  printf_info()
{
    char *user_str="$";
    int user_id=getuid();
    if(user_id==0)
    {
        user_str="#";
    }

    struct passwd *ptr=getpwuid(user_id);
    if(ptr==NULL)
    {
        printf("mybash1.0>>  ");
        fflush(stdout);
        return ;
    }
    char hostname[128]={0};
    if(gethostname(hostname,128)==-1)
    {
        printf("mybash1.0>>  ");
        fflush(stdout);
        return ;
    }
    char dir[256]={0};
    if(getcwd(dir,256)==NULL)
    {
        printf("mybash1.0>>  ");
        fflush(stdout);
        return ;
    }

    printf("\033[1;32m%s@%s\033[0m  \033[1;34m %s\033[0m%s ",ptr->pw_name,hostname,dir,user_str);
    fflush(stdout);
}
char *get_cmd(char *buff,char *myargv[])
{
    if(buff==NULL||myargv==NULL)
    {
        return NULL;
    }

    int i=0;
    char *s=strtok(buff," ");
    while(s!=NULL)
    {
        myargv[i++]=s;
        s=strtok(NULL," ");
    }

    return myargv[0];
}


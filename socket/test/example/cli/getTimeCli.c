#include"../../../include/socket.h"

#define MAXLINE 10
int main(int argc,char* argv[])
{
    int     socketfd,n;
    char    reciveline[MAXLINE+1];
    struct sockaddr_in servaddr;

    if(argc !=2)
    {
        perror("ip address\n");
    }
    if(socket(AF_INET,SOCK_STREAM,0)<0)
    {
        perror("socker erro\n");
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13); //daytime server

    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<0)
    {
        perror("inet_pton error\n");
    }

    if(connect(socketfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
    {
        perror("connect error\n");
    }

    while((n=read(socketfd,reciveline,MAXLINE))>0)
    {
        reciveline[n] =0;
        if(fputs(reciveline,stdout)==EOF)
        {
            perror("FPUTS ERROR");
        }
    }
    if(n<0)
    {
        perror("read error");
    }
    exit(0);
}
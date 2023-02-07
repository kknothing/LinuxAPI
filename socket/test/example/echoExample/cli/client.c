#include"../../../../include/socket.h"

#define MAXLINE 1024

/*
*
*str_cli:完成客户端循环处理，从标准输入读入一行文本，写到服务器上，
*        读回服务器对该行回射，并把回射行写到标准输出上
*/
void str_cli(FILE *fp,int sockfd)
{
    char sendline[MAXLINE],recvline[MAXLINE];
    while(fgets(sendline,MAXLINE,fp))
    {
        write(sockfd,sendline,strlen(sendline));
        if(read(sockfd,recvline,strlen(recvline))<0)
        {
            perror("READ ERROR");
            exit(1);
        }
        fputs(recvline,stdout);
    }
}

int main(int argc,char *argv[])
{
    int sockfd;
    struct sockaddr_in cliAddr;
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket error:");
        exit(1);
    }
    bzero(&cliAddr,sizeof(cliAddr));
    cliAddr.sin_addr.s_addr = inet_addr(argv[1]);
    cliAddr.sin_port = htons(atoi(argv[2]));
    cliAddr.sin_family = AF_INET;
     if(connect(sockfd,(struct sockaddr*)&cliAddr,sizeof(cliAddr))<0)
     {
        perror("connect error");
        exit(1);
     }
    str_cli(stdin,sockfd);
}
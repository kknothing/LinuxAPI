#include"../../../../include/socket.h"
#define MAXLINE 1024
/**
 * str_echo:从客户读入数据，并把他们回射客户
 * 
*/
void str_echo(int sockfd)
{
    size_t n;
    char buf[MAXLINE];
again:
    while((n=read(sockfd,buf,strlen(buf)))>0)
    {
        write(sockfd,buf,n);
    }
    if(n<0&&errno==EINTR)
    {
        goto again;
    }else if(n<0)
    {
        perror("str_echo : read error");
    }
}

int main(int argc,char *argv[])
{
    int lisentFd,conFd;
    int optval = 1;
    struct sockaddr_in serAddr;
    bzero(&serAddr,sizeof(serAddr));
    if((lisentFd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket error");
        exit(1);
    }
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    if(setsockopt(lisentFd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int))<0)
    {
        perror("reuse sockaddr error:");
        exit(1);
    }

    if(bind(lisentFd,(struct sockaddr*)&serAddr,sizeof(serAddr))<0)
    {
        perror("bind error:");
        exit(1);
    }
    if(listen(lisentFd,1024)<0)
    {
        perror("listen error");
        exit(1);
    }
    if((conFd=accept(lisentFd,NULL,NULL))<0)
    {
        perror("accept error:");
        exit(1);
    }
    //sleep(10000);
    str_echo(conFd);

}
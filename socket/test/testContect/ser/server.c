#include"../../../include/socket.h"

int main(int argc,char*argv[])
{
    int sendFd;
    int listenFd = socket(AF_INET,SOCK_STREAM,0);

    int optval = 1;
    int ret = setsockopt(listenFd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval));

    struct sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(atoi(argv[2]));
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);

    ret=bind(listenFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ret=listen(listenFd,1024);
    while(1){

    char buf[4096];
    sendFd=accept(listenFd,NULL,NULL);
    if(sendFd<0)
    {
        perror("accept error:");
        exit(1);
    }
    write(sendFd,"accept success",13);

    time_t tickets=time(NULL);
    bzero(buf,sizeof(buf));
    snprintf(buf,sizeof(buf),"%.24s\r\n",ctime(&tickets));
    write(sendFd,buf,strlen(buf));
    }
    close(sendFd);
    close(listenFd);
    return 0;

 


}
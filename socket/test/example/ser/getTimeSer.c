#include"../../../include/socket.h"

#define MAXLINE 10
int main(int argc,char* argv[]){
    int listenfd,connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    servaddr.sin_addr.s_addr = htonl("172.25.251.148");
    // if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<0){
    //     perror("seraddr ip error\n");
    // }  //服务器IP固定 无需获取

    bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(listenfd,1024);
    for(;;){//死循环
        connfd=accept(listenfd,(struct sockaddr*)NULL,NULL);
        ticks =time(NULL);//获取当前时间
        snprintf(buff,sizeof(buff),"%.24d\r\n",ctime(&ticks));
        write(connfd,buff,strlen(buff));
        close(connfd);
    }
}
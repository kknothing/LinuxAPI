#include"../../../include/socket.h"

int main(int argc,char* argv[]){
    int cliFd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in cliAddr;
    cliAddr.sin_family = AF_INET;
    cliAddr.sin_addr.s_addr = inet_addr(argv[1]);
    cliAddr.sin_port = htons(atoi(argv[2]));

    int ret= connect(cliFd,(struct sockaddr*)&cliAddr,sizeof(cliAddr));
    if(ret<0)
    {
        perror("connect error");
        exit(1);
    }
    char buf[1024];
    while(read(cliFd,buf,sizeof(buf))>0)
    {
        printf("%s\n",buf);
    }
    
    close(cliFd);
    return 0 ;

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> //数据转换及read，write函数
//常用头文件
#include<dirent.h> //目录项
#include<fcntl.h> //文件控制
#include<netdb.h>   //网络数据库操作
#include<pwd.h> //口令文件
#include<errno.h> //错误处理
#include<time.h> //时间函数

// #include<socket.h>
#include<sys/time.h>
#include<sys/socket.h>
#include<sys/types.h>   //bind函数
#include<sys/select.h>
#include<sys/epoll.h>
#include<sys/unistd.h>

#include<netinet/in.h>
#include<arpa/inet.h>

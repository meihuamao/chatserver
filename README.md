# chatserver
工作在nginx、tcp负载均衡环境中的集群聊天服务器和客户端源码，基于muduo、redis、mysql实现

## 环境搭建
此源码是运行在Linux系统下的，在使用build.sh编译前，需要安装必要的环境，包括muduo、redis、MySQL、nginx
### 安装muduo
可以参考[muduo安装](https://blog.csdn.net/m0_72740458/article/details/149244766?spm=1001.2014.3001.5501)
### 安装redis
sudo apt-get install redis-server
### 安装MySQL
sudo apt-get install mysql-server  
sudo apt-get install libmysqlclient-dev
### 安装nginx
去官网[nginx](https://nginx.org/en/download.html)下载压缩包  
unzip nginx-x.x.x.tar.gz
cd nginx-x.x.x  
./configure --with-stream  
make && sudo make install  
编译完成后，nginx库会默认安装在/usr/local/nginx目录下

# Clog
c语言实现的log日志记录工具


执行实例：

hh@hh-PC:~/Desktop/code/test$ ./Clog

[2019-4-30 22:5:0]init log compelte.(0x20190501)


接口API:

void log_init(void); log模块的总初始化函数

void log_display(void)； 打印日志内容

void log_write(unsigned char* fmt, ...)； 记录一条日志信息

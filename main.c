
/* log日志模块 */
#include "stdarg.h"
#include <time.h>

#include "log.h"

LOG_BUFF_S *g_logbuff = NULL;

void log_init(void)
{
	g_logbuff = malloc(sizeof(LOG_BUFF_S));
	if(NULL == g_logbuff)
	{
		printf("\r\nlog module init fail.(no buffer)");
		return ;
	}
	memset(g_logbuff, 0, sizeof(LOG_BUFF_S));
	g_logbuff->bufftail = 0;
	g_logbuff->magicword = 0x20190501;
}

void log_write(unsigned char* fmt, ...)
{
	unsigned char *tmp = NULL;
	int len = 0;
	time_t t = time(NULL) ;
	struct tm* t_tm = localtime(&t);    
	va_list args;

	if(NULL == g_logbuff)
	{
		printf("\r\nlog module not init.");
		return;
	}
	tmp = g_logbuff->szBuff[g_logbuff->bufftail];
	memset(tmp, 0, LOG_LENGTH );
	
	memset(&args, 0, sizeof(va_list));
	va_start(args, fmt);
	len = sprintf(tmp, "\r\n[%d-%d-%d %d:%d:%d]", t_tm->tm_year+1900,   
t_tm->tm_mon+1, t_tm->tm_mday, t_tm->tm_hour, t_tm->tm_min, t_tm->tm_sec);
	vsnprintf(tmp+len, LOG_LENGTH, fmt, args);
	va_end(args);

	g_logbuff->bufftail = (g_logbuff->bufftail + 1) % LOG_ITEM;

}

void log_display(void)
{
	unsigned char *tmp = NULL; 
	int tail = g_logbuff->bufftail;
	if(NULL == g_logbuff)
	{
		printf("\r\nlog module not init.");
		return;
	}
	if(tail == 0)
	{
		printf("\r\nno log.");
		return ;
	}
	tmp = g_logbuff->szBuff[tail];
	while(tail != 0)
	{

		printf("%s", g_logbuff->szBuff[tail]);
		tail --;
	}
	printf("%s\r\n", g_logbuff->szBuff[0]);
}

void main(int argc, char* argv[])
{
	log_init();
	log_write("init log compelte.(%d %#x)",0x20190501, 0x20190501);
	
	log_display();
	return ;
}


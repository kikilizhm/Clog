
#include "log.h"

void main(int argc, char* argv[])
{
	log_init();
	log_write("init log compelte.");

	log_display();
	return ;
}


#include "apue.h"

int main(void)
{
	int count = 0;
	int c;
	
	while( (c = getc(stdin)) != EOF ){
		count++;
		if(putc(c,stdout) == EOF)
			err_sys("output error");
	}
	if(ferror(stdin))
		err_sys("input error");
	printf("count is %d\n",count);
	exit(0);
}


#include "apue.h"

int main(void)
{
	int count = 0;
	char buf[MAXLINE];
	setvbuf(stdin, buf,_IOFBF, MAXLINE);
	while( (fgets(buf,MAXLINE,stdin)) != NULL ){
		count++;
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
	}
	if(ferror(stdin))
		err_sys("input error");
	printf("count is %d\n",count);
	exit(0);
}


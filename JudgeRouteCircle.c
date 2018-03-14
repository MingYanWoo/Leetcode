#include <stdio.h>
#include <stdlib.h>

int judgeCircle(char* moves)
{
	int record[] = {0,0,0,0};		//记录数组，分别代表左右上下的次数
	while(*moves != '\0')
	{
		if(*moves == 'L')		++record[0];
		else if(*moves == 'R')	++record[1];
		else if(*moves == 'U')	++record[2];
		else if(*moves == 'D')	++record[3];
		moves++;
	}
	if(record[0] == record[1] && record[2] == record[3])	return 1;
	else return 0;
}

int main(int argc, char *argv[])
{
	printf("%d\n", judgeCircle("UD"));
	return 0;
}

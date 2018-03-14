#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y)
{
	int count = 0;
	while(x || y)
	{
		if(x%2 != y%2)		//逐位比较
			count++;
		x /= 2;
		y /= 2;
	}
	return count;
}

int main(int argc, char *argv[])
{
	printf("%d\n", hammingDistance(2, 4));
	return 0;
}

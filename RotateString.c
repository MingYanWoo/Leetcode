#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveOneWord(char a[])
{
	char first = a[0];
	for(int i = 0; i < strlen(a)-1; ++i)
	{
		a[i] = a[i+1];
	}
	a[strlen(a)-1] = first;
}
int rotateString(char A[], char B[]) {
	if(strlen(A) != strlen(B)) return 0;    //字符串长度不等，返回错误
	int tag = 0;
	for(int i = 0; i < strlen(B); ++i)
	{
		if(tag == 1)
			break;
		moveOneWord(A);
		for(int j = 0; j < strlen(A); ++j)
		{
			if(A[j] != B[j])
			{
				tag = 0;
				break;
			}
			tag = 1;
		}
	}
	return tag;
}

int main(int argc, char *argv[])
{
	char a[] = "abcdbes";
	char b[] = "cdsbeab";
	printf("%d\n", rotateString(a, b));
	return 0;
}


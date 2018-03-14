#include <stdio.h>
#include <stdlib.h>

int numJewelsInStones(char* J, char* S) {
	int count = 0;
	while(*J != '\0') {
		char *Stones = S;
		while(*Stones != '\0') {
			if(*Stones == *J) count++;
			Stones++;
		}
		J++;
	}
	return count;
}

int main(int argc, char *argv[])
{
	printf("%d\n", numJewelsInStones("aB", "aaabbBBBcc"));
	return 0;
}

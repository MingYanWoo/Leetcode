#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strsSize == 0) return "";
	char *out = strs[0];
	for(int i = 1; i < strsSize; i++) {
		int j = 0;
		while(out[j] && strs[i][j] && strs[i][j] == out[j])	j++;
		out[j] = 0;
	}
	return out;
}

int main(int argc, char *argv[])
{
	char *strs[] = {"c"};
	char *result = longestCommonPrefix(strs, 1);
	printf("%s\n", result);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10000

char stack[MaxSize];
int top;

void InitStack() {
	top = -1;
}

void Push(char e) {
	if(top == MaxSize-1) return;
	top++;
	stack[top] = e;
}

char Pop() {
	if(top == -1) return '\0';
	char temp = stack[top];
	top--;
	return temp;
}

int isValid(char* s) {
	InitStack();
	while(s) {
		if(*s == '(') Push(*s);
		else if(*s == '{') Push(*s);
		else if(*s == '[') Push(*s);
		else if(*s == ')') {
			char e = Pop();
			if(e != '(') return 0;
		}
		else if(*s == '}') {
			char e = Pop();
			if(e != '{') return 0;
		}
		else if(*s == ']') {
			char e = Pop();
			if(e != '[') return 0;
		}else if(*s == '\0') break;
		s++;
	}
	if(top != 0) return 0;				//栈内还有元素，返回false
	return 1;
}

int main(int argc, char *argv[])
{
	printf("%d\n", isValid("(){}[{]"));
	return 0;
}

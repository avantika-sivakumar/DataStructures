#include <stdio.h>

#define MAX 30

char stack[MAX];
int top=-1;

void push(char);
char showtop();
void pop();

void push(char c){
	if(top==MAX-1){
		printf("Stack full\n");
		return;
	}
	top++;
	stack[top]=c;
}

char showtop(){
	return stack[top];
}

void pop(){
	if(top==-1){
		printf("Stack empty\n");
		return;
	}
	top--;
}

int main(){
	char c;
	int i;
	printf("Enter the string:\n");
	for(i=0;i<MAX && ((c=getchar())!='\n');i++){
		if(c=='('||c=='{'||c=='['){
			push(c);
		}
		else if(c==')'){
			if(showtop()=='('){
				pop();
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
		else if(c=='}'){
			if(showtop()=='{'){
				pop();
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
		else if(c==']'){
			if(showtop()=='['){
				pop();
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
	}
	if(top==-1){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}

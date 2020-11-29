//n queens question
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int y[MAX];//stores position of queens as (index,y[index])
int solNo=1;
int n;

int valid(int r,int c){//returns 1 if queen can be placed here without attacking any other queen already present on the board, else 0
	int i;
	for(i=0;i<r;i++)
	{
		if(y[i]==c)//if row already has a queen
			return 0;
		else if(abs(y[i]-c)==abs(i-r))//if diagonal already has a queen
	    	return 0;
	}
	return 1;
}

void display(){
	int i,j;
	printf("\nSOLUTION %d:\n",solNo++);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(y[i]==j){
				printf("Q%d ",i+1);
			}
			else{
				printf(" - ");
			}
		}
		printf("\n");
	}
}

void solve(int row){
	int col;
	for(col=0;col<n;col++){
		if(valid(row,col)){
			y[row]=col;
			if(row==n-1){
				//solution found. print it.
				display();
			}
			else{
				solve(row+1);
			}
		}
	}
}

int main(){
	printf("Enter n: ");
	scanf("%d",&n);
	solve(0);
	return 0;
}

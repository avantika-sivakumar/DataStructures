//subset sum problem: backtracking
#include<stdio.h>

#define MAX 10

int size,sum,solNo=1;
int set[MAX];
int incl[MAX];

void sort(){
	int i,j,smallest,pos;
	for(i=0;i<size;i++){
		smallest=set[i];
		pos=i;
		for(j=i;j<size;j++){
			if(smallest>set[j]){
				smallest=set[j];
				pos=j;
			}
		}
		set[pos]=set[i];
		set[i]=smallest;
	}
}

int valid(int index,int total){
	int sumTemp=total,i;
	for(i=index+1;i<size;i++){
		sumTemp+=set[i];
	}
	if(sumTemp<sum){
		return 0;
	}
	if(total+set[index+1]>sum && total!=sum){
		return 0;
	}
	return 1;
}

void disp(){
	int i;
	printf("%d) ",solNo++);
	for(i=0;i<size;i++){
		if(incl[i]==1)
			printf("%d ",set[i]);
	}
	printf("\n");
}

void solve(int i,int s){//s:temporary sum
	if(valid(i,s)){
		//check if soln is found
		if(sum==s){
			disp();
		}
		else{
			incl[i+1]=1;
			solve(i+1,s+set[i+1]);
			incl[i+1]=0;
			solve(i+1,s);
		}
	}
}

int main(){
	int i;
	printf("Enter the size of the set: ");
	scanf("%d",&size);
	printf("Enter the elements of the set: ");
	for(i=0;i<size;i++){
		scanf("%d",&set[i]);
	}
	printf("Enter the subset sum: ");
	scanf("%d",&sum);
	sort();
	printf("\nSorted set: ");
	for(i=0;i<size;i++){
		printf("%d ",set[i]);
	}
	printf("\n\n  Subsets:\n");
	solve(-1,0);
	if(solNo==1){
		printf("No solutions found\n");
	}
}

//hashing: chaining

#include<stdio.h>
#include<stdlib.h>

#define n 10

struct node{
	int data;
	struct node*next;
};

int main(){
	int f,d;//f(d)=d%n
	struct node*temp;
	struct node ptr;
	struct node arr[n];
	for(d=0;d<n;d++){
		arr[n].next=NULL;
	}
	printf("HASHING: CHAIN METHOD: f(x)=x\%10\n");
	printf("Enter the elements(-1 to stop):\n");
	while(d!=-1){
		scanf("%d",&d);
		//create node having data value d
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=d;
		temp->next=NULL;
		printf("Created node with d=%d\n",temp->data);
		f=d%n;
		ptr=arr[f];
		while(ptr.next){
			ptr=*(ptr.next);
		}
		ptr.next=temp;
		printf("printing%d . added to index %d\n",ptr.data,f);
	}
	printf("\nHASH TABLE:\n");
	for(f=0;f<n;f++){
		ptr=arr[f];
		ptr=*(ptr.next);
		while(ptr!=NULL){
			printf("%d->",ptr.data);
			ptr=*(ptr.next);
		}
		printf("\n");
	}
	return 0;
}

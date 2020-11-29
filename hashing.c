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
	struct node*ptr;
	struct node*arr[n];
	for(d=0;d<n;d++){
		arr[d]=NULL;
	}
	printf("HASHING: CHAIN METHOD: f(x)=x%%10\n");
	printf("Enter the elements(-1 to stop):\n");
	while(1){
		scanf("%d",&d);
		if(d==-1){
			break;
		}
		//create node having data value d
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=d;
		temp->next=NULL;
		f=d%n;
		ptr=arr[f];
		if(arr[f]==NULL){
			arr[f]=temp;
			continue;
		}
		while(ptr->next){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	printf("\nHASH TABLE:\n");
	for(d=0;d<n;d++){
		ptr=arr[d];
		while(ptr){
			printf("%d  ",ptr->data);
			ptr=ptr->next;
		}
		if(arr[d]==NULL){
			printf("-EMPTY-");
		}
		printf("\n");
	}
	printf("\nEnter the element you want to search for: ");
	scanf("%d",&d);
	f=d%n;
	ptr=arr[f];
	if(arr[f]==NULL){
		printf("Not found\n");
		return 0;
	}
	while(ptr){
		if(ptr->data==d){
			printf("Found\n");
			return 0;
		}
		ptr=ptr->next;
	}
	printf("Not found\n");
	return 0;
}

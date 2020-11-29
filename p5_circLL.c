//circLL
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};

struct node *last=NULL;

void insert(int n, int pos);
void del(int pos);
void find(int n);
void display();
void modify(int n, int a);
int count();

void insert(int n,int pos){
	struct node*start;
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	if(pos<1 || pos>count()+1){
		printf("Invalid position\n");
		return;
	}
	if(last==NULL){
		last=temp;
		temp->next=temp;
		return;
	}
	if(pos==1){
		temp->next=last->next;
		last->next=temp;
		return;
	}
	start=last;
	for(;pos>1;pos--){
		start=start->next;
	}
	if(start==last){
		last=temp;
	}
	temp->next=start->next;
	start->next=temp;
}

void del(int pos){
	struct node*start;
	struct node*temp;
	if(last==NULL){
		printf("List is empty!\n");
		return;
	}
	if(pos<1 || pos>count()+1){
		printf("Invalid position\n");
		return;
	}
	if(pos==count()){
		start=last;
		while(start->next!=last){
			start=start->next;
		}
		temp=start->next;
		last=start;
		start->next=temp->next;
		printf("Deleted %d\n",temp->data);
		free(temp);
		return;
	}
	start=last;
	for(;pos>1;pos--){
		start=start->next;
	}
	temp=start->next;//free later
	printf("Deleted %d\n",temp->data);
	start->next=temp->next;
	free(temp);
}

void find(int n){
	struct node*ptr;
	int pos=1;
	if(last==NULL){
		printf("Not found!\n");
		return;
	}
	ptr=last->next;
	while(ptr&&ptr!=last){
		if(ptr->data==n){
			printf("Element %d found at %d\n",n,pos);
			return;
		}
		ptr=ptr->next;
		pos++;
	}
	if(last->data==n){
		printf("Element %d found at %d\n",n,pos);
		return;
	}
	printf("Not found!");
}

void display(){
	struct node*ptr;
	if(last==NULL){
		printf("List is empty!\n");
		return;
	}
	printf("\nPRINTING THE LIST:\n");
	ptr=last->next;
	while(ptr!=last){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d ",ptr->data);
}

void modify(int n,int a){
	struct node*ptr;
	ptr=last->next;
	while(ptr!=last){
		if(n==ptr->data){
			ptr->data=a;
			return;
		}
		ptr=ptr->next;
	}
	if(last->data==n){
		last->data=a;
	}
}

int count(){
	struct node*ptr;
	int count=1;
	if(last==NULL){
		return 0;
	}
	ptr=last->next;
	while(ptr!=last){
		ptr=ptr->next;
		count++;
	}
	return count;
}

int main(){
	int n,pos,ch;
	while(1){
		printf("\n\nMENU:\n");
		printf("1. Insert\n2. Delete\n3. Find\n4. Display\n5. Modify\n6. Count\n7. Exit\n\nEnter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the element to be added and position: ");
				scanf("%d %d",&n,&pos);
				insert(n,pos);
				break;
			case 2:
				printf("Enter the position of the element to be deleted: ");
				scanf("%d",&pos);
				del(pos);
				break;
			case 3:
				printf("Enter the element you're searching for: ");
				scanf("%d",&n);
				find(n);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Enter the element to be modified and its new value: ");
				scanf("%d %d",&n,&pos);//pos stores the new value
				modify(n,pos);
				break;
			case 6:
				printf("The number of elements=%d\n",count());
				break;
			case 7:
				return 0;
			default:
				printf("Invalid choice. Try again!\n");
				break;
		}
	}
}

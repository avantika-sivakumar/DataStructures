//doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*prev;
	struct node*next;
};

struct node head,tail;//head.data will hold the number of nodes

void insert(int n,int pos);
void del(int pos);
void find(int n);
void display();
void modify(int n,int a);

void insert(int n,int pos){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	struct node*ptr;
	temp->data=n;
	//if empty
	if(head.data==0){
		temp->next=&tail;
		temp->prev=&head;
		head.next=temp;
		tail.prev=temp;
		head.data++;
		return;
	}
  if(pos==head.data+1){
    temp->prev=tail.prev;
    temp->next=&tail;
    tail.prev->next=temp;
    tail.prev=temp;
    head.data++;
    return;
  }
	if(pos>(head.data/2)){
		//traverse from the back
		ptr=tail.prev;
		while(pos!=head.data){
			ptr=ptr->prev;
			pos++;
		}
	}
	else{
		ptr=head.next;
		while(pos>1){
			ptr=ptr->next;
			pos--;
		}
	}
	temp->next=ptr;
	temp->prev=ptr->prev;
	(ptr->prev)->next=temp;
	ptr->prev=temp;
	head.data++;
	return;
}

void del(int pos){
	struct node*ptr;
	int i;
	if(head.next==&tail){
		printf("List is empty\n");
		return;
	}
	if(pos>(head.data/2)){
		//traverse from the back
		ptr=tail.prev;
		while(pos!=head.data){
			ptr=ptr->prev;
			pos++;
		}
	}
	else{
		ptr=head.next;
		while(pos>1){
			ptr=ptr->next;
			pos--;
		}
	}
	(ptr->prev)->next=ptr->next;
	(ptr->next)->prev=ptr->prev;
	printf("Deleted %d\n",ptr->data);
	free(ptr);
	head.data--;
}

void find(int n){
	struct node*ptr=&head;
	int pos=0;
	while(ptr!=&tail){
		ptr=ptr->next;
		pos++;
		if(ptr->data==n){
			printf("%d found at position %d\n",n,pos);
			return;
		}
	}
	printf("Not found\n");
}

void display(){
	struct node*ptr=head.next;
	if(head.data==0){
		printf("List is empty\n");
		return;
	}
	while(ptr!=&tail){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

void modify(int n,int a){
	struct node*ptr=&head;
	while(ptr!=&tail){
		ptr=ptr->next;
		if(ptr->data==n){
			ptr->data=a;
			return;
		}
	}
}

int main(){
	int n,pos,ch;
  	head.next=&tail;
  	tail.prev=&head;
  	head.prev=NULL;
  	tail.next=NULL;
  	head.data=0;
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
				printf("The number of elements=%d\n",head.data);
				break;
			case 7:
				return 0;
			default:
				printf("Invalid choice. Try again!\n");
				break;
		}
	}
}


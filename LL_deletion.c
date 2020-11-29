#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node*prev;
	struct node*next;
};

struct node*head;
struct node*tail;

void insert(int);
void del(int);

void insert(int no){
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->n=no;
	if(head->next==tail){
		temp->next=tail;
		tail->prev=temp;
		head->next=temp;
		temp->prev=head;
		return;
	}
	temp->prev=tail->prev;
	temp->next=temp->prev->next;
	tail->prev=temp;
	temp->prev->next=temp;
}

void del(int no){
	struct node*ptr=head->next;
	if(ptr->n==no){
		head->next=ptr->next;
		ptr->next->prev=head;
		free(ptr);
		return;
	}
	if(tail->prev->n==no){
		ptr=tail->prev;
		tail->prev=ptr->prev;
		tail->prev->next=tail;
		free(ptr);
		return;
	}
	while(ptr!=tail){
		if(ptr->n==no){
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);
			return;
		}
		ptr=ptr->next;
	}
	printf("No such node found\n");
}

int main(){
	int n;
	struct node*ptr;
	head=(struct node*)malloc(sizeof(struct node));
	tail=(struct node*)malloc(sizeof(struct node));
	head->prev=NULL;
	head->next=tail;
	tail->prev=head;
	tail->next==NULL;
	insert(1);
	insert(2);
	insert(3);
	ptr=head->next;
	while(ptr->next!=tail){
		printf("%d ->",ptr->n);
		ptr=ptr->next;
	}
	printf("%d\nEnter element to be deleted: ",ptr->n);
	scanf("%d",&n);
	del(n);
	printf("LL after deletion:\n");
	ptr=head->next;
	while(ptr->next!=tail){
		printf("%d ->",ptr->n);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->n);
	return 0;
}

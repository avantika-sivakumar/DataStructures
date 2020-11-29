//circQueue

#include <stdio.h>
#define MAX 3

int queue[MAX];
int rear=-1, front=-1;

void enqueue(int n);
int dequeue();
void display();

void enqueue(int n){
	if((rear==MAX-1 && front==0)||rear==front-1){
		printf("Queue is full.\n");
		return;
	}
	if(front==-1){
		front=0;
	}
	rear=(rear+1)%MAX;
	queue[rear]=n;
}

int dequeue(){
	int n;
	if(front==-1){
		printf("Queue is empty.\n");
		return -1;
	}
	n=queue[front];
	if(rear==front){
		rear=-1;
		front=-1;
	}
	else{
		front=(front+1)%MAX;
	}
	printf("Deleted %d.\n",n);
	return n;
}

void display(){
	int i=front;
	if(front==-1){
		printf("\nQueue is empty.\n");
		return;
	}
	printf("\nPrinting the Queue:  ");
	for(;i!=rear;i=(i+1)%MAX){
		printf("%d ",queue[i]);
	}
	printf("%d\n",queue[i]);
}

int main(){
	int ch,n;
	while(1){
		printf("\nMENU:\n1. Enqueue\n2. Dequeue\n3. Display queue\n4. Exit Program\n");
		printf("Enter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value to be added to queue: ");
				scanf("%d",&n);
				enqueue(n);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice\n");
				break;
		}
	}
	return 0;
}

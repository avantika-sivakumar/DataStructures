//queuearray

#include <stdio.h>
#define MAX 3

int queue[MAX];
int rear=-1, front=-1;

void enqueue(int n);
int dequeue();
void display();

void enqueue(int n){
	if(rear==MAX-1){
		printf("Queue is full.\n");
		return;
	}
	if(front==-1){
		front++;
	}
	rear++;
	queue[rear]=n;
}

int dequeue(){
	int n;
	if(front==-1){
		printf("Queue is empty.\n");
		return;
	}
	n=queue[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else
		front++;
	printf("Deleted %d.\n",n);
	return n;
}

void display(){
	int i=front;
	if(front==-1){
		printf("Queue is empty.\n");
		return;
	}
	for(;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
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

#include <stdio.h>
#define SIZE 100

int queue[SIZE];//A:index 0 to 19. B:20-39
int f1=-1,r1=-1,f2=SIZE/2-1,r2=SIZE/2-1;
int dqcount=0;

void enqueue(int n,int priority);
void dequeue();
void display();

void enqueue(int n,int priority){
	if(priority==0){
		if(r2==SIZE-1){
			printf("Queue is full.\n");
			return;
		}
		if(f2==SIZE/2-1){
			f2++;
		}
		r2++;
		queue[r2]=n;
	}
	else if(priority==1){
		if(r1==SIZE/2-1){
			printf("Queue is full.\n");
			return;
		}
		if(f1==-1){
			f1++;
		}
		r1++;
		queue[r1]=n;
	}
}

void dequeue(){
	int n;
	if((f2==SIZE/2-1)&&(f1==-1)){
			printf("Queue is empty.\n");
			return;
	}
	if(f1==r1||f2==r2){
		dqcount=0;
	}
	if(f2==SIZE/2-1){
		//del high priority job
		n=queue[f1];
		if(f1==r1){
			f1=-1;
			r1=-1;
		}
		else
			f1++;
		printf("Printed %d.\n",n);
		return;
	}
	else if(f1==-1){
		//del low priority job
		n=queue[f2];
		if(f2==r2){
			f2=SIZE/2-1;
			r2=SIZE/2-1;
		}
		else
			f2++;
		printf("Printed %d.\n",n);
		return;
	}
	
	dqcount++;
	if(dqcount%3==0&&dqcount!=0){
		//delete low priority job
		n=queue[f2];
		if(f2==r2){
			f2=SIZE/2-1;
			r2=SIZE/2-1;
		}
		else
			f2++;
		printf("Printed %d.\n",n);
	}
	else{
		n=queue[f1];
		if(f1==r1){
			f1=-1;
			r1=-1;
		}
		else
			f1++;
		printf("Printed %d.\n",n);
	}
}

void display(){
	int i;
	printf("\nQueue A(High priority jobs): ");
	for(i=f1;i<=r1;i++){
		printf("%d ",queue[i]);
	}
	printf("\nQueue B(Low priority jobs): ");
	for(i=f2;i<=r2;i++){
		printf("%d ",queue[i]);
	}
}

int main(){
	int ch,n,pr;
	while(1){
		printf("\nMENU:\n1. Add print job\n2. Print from queue\n3. Display queues\n4. Exit Program\n");
		printf("Enter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the number(print job): ");
				scanf("%d",&n);
				printf("Enter the priority(0-low, 1-high): ");
				scanf("%d",&pr);
				enqueue(n,pr);
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

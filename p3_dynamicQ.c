#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
 
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

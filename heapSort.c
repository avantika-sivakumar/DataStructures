//heap sort
#include <stdio.h>

#define MAX 20

int arr[MAX];
int heapSize, arrSize;

void heapify(int i){
	int biggest=i;
	int left=2*i+1;
	int right=2*i+2;
	if (left < heapSize && arr[left] > arr[biggest])
      biggest = left;
    if (right < heapSize && arr[right] > arr[biggest])
      biggest = right;
	if (biggest != i) {
      //swap arr[i], arr[biggest]
      left=arr[i];
      arr[i]=arr[biggest];
      arr[biggest]=left;
      heapify(biggest);
    }
}

int main(){
	int i;
	printf("Enter the size of the array: ");
	scanf("%d",&arrSize);
	heapSize=arrSize;
	printf("Enter the elements of the array:\n");
	for(i=0;i<arrSize;i++){
		scanf("%d",&arr[i]);
	}
	//now we need to create the heap... 'heapify'
	//non leaf nodes are from index 0 to arrSize/2 -1
	for(i=arrSize/2-1;i>=0;i--){
		heapify(i);
	}
	while(heapSize!=0){
		//delete root
		//swap root, last element
		i=arr[0];
		arr[0]=arr[heapSize-1];
		arr[heapSize-1]=i;
		//reduce size
		heapSize--;
		heapify(0);
	}
	printf("Sorted array:\n");
	for(i=0;i<arrSize;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

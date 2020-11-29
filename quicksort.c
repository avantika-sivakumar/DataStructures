//QuickSort
#include<stdio.h>
#define MAX 20

int arr[MAX];
int size=0;

void display();
void swap(int*,int*);
int partition(int,int);
void quickSort(int low, int high);

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int low, int high){
	int pivot = arr[low];
	int i =low;
	int j=high;
	while(i<j){
		do{
			i++;
		}while(arr[i]<=pivot);
		do{
			j--;
		}while(arr[j]>pivot);
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[low], &arr[j]);
	return j;
}

void quickSort(int low, int high){
	int j;
	if (low < high)
	{
		j= partition(low, high);
		quickSort(low,j);
		quickSort(j+1,high);
	}
}

void display(){
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(){
	int i;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	printf("Enter the elements of the array: ");
	for (i=0; i < size; i++){
		scanf("%d",&arr[i]);
	}
	arr[size]=100;//some arbitrary large number
	quickSort(0,size);
	printf("Sorted array: \n");
	display();
	return 0;
}


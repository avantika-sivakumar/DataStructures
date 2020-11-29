//merge-sort
#include <stdio.h>
#define MAX 20
void merge(int arr[], int l, int m, int h)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = h- m;
	int a[n1], b[n2];
	for (i = 0; i < n1; i++)
		a[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		b[j] = arr[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) {
		if (a[i] <= b[j]) {
			arr[k] = a[i];
			i++;
		}
		else {
			arr[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = b[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int h)
{
	if (l < h) {
		int m = l + (h - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, h);
		merge(arr, l, m,h);
	}
}

void display(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[MAX];
	int size,i;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	printf("Enter the elements of the array:\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	mergeSort(arr, 0, size-1);
	printf("Sorted array:\n");
	display(arr,size);
	return 0;
}


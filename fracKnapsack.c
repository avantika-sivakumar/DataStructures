//fractional knapsack
#include <stdio.h>
#define MAX 10

//inputs:
double arr[MAX][3];//item value,weight,ratio
int size;//no of items
double W;//capacity


//calc:
double wt=0;//total weight taken

//outputs:
double v=0;//maximum possible value
double ans[MAX][3];//value,weight,weights of each item taken

int main(){
	int i,j;
	int smallest,pos,temp2,temp3;
	printf("Enter the number of items:  ");
	scanf("%d",&size);
	printf("\nENTER ITEMS:\n");
	for(i=0;i<size;i++){
		printf("\nEnter value: ");
		scanf("%lf",&arr[i][0]);
		printf("Enter weight: ");
		scanf("%lf",&arr[i][1]);
		arr[i][2]=(double)arr[i][0]/arr[i][1];
	}
	printf("\nEnter the capacity of the knapsack: ");
	scanf("%lf",&W);
	//sort arr according to value/weight ratio
	for(i=0;i<size;i++){
		smallest=arr[i][2];
		pos=i;
		temp2=arr[i][0];
		temp3=arr[i][1];
		for(j=i;j<size;j++){
			if(arr[j][2]<smallest){
				smallest=arr[j][2];
				pos=j;
				temp2=arr[j][0];
				temp3=arr[j][1];
			}
		}
		//swap everything
		arr[pos][2]=arr[i][2];
		arr[pos][1]=arr[i][1];
		arr[pos][0]=arr[i][0];
		arr[i][2]=smallest;
		arr[i][1]=temp3;
		arr[i][0]=temp2;
	}
	j=0;//index of ans
	for(i=size-1;i>=0 && wt<W;i--){
		if(wt+arr[i][1]<W){
			v+=arr[i][0];
			wt+=arr[i][1];
			ans[j][0]=arr[i][0];
			ans[j][1]=arr[i][1];
			ans[j][2]=arr[i][1];
			j++;
		}
		else{
			temp2=W-wt;
			v+=arr[i][2]*temp2;//value per weight*remaining weight
			wt+=arr[i][2]*temp2;
			ans[j][0]=arr[i][0];
			ans[j][1]=arr[i][1];
			ans[j][2]=temp2;
			j++;
			break;
		}
	}
	//output:
	printf("\nVALUE\tWEIGHT\tWEIGHT TAKEN\n");
	for(i=0;i<j;i++){
		printf("  %.2lf  %.2lf  %.2lf\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	printf("MAXIMUM VALUE: %.2lf\n",v);
	return 0;
}

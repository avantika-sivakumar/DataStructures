//staticBT
#include<stdio.h>
#include<math.h>

#define MAX 100

int tree[MAX];
int size;

void insert(int n,int par,int dir);
int find(int n);
void levelorder();
void inorder(int index);
void preorder(int index);
void postorder(int index);

void insert(int n,int par,int dir){
	int pos=find(par);
	if(pos==-1){
		printf("\nNo such parent node found!\n");
		return;
	}
	if(dir==1){
		pos=pos*2+1;
		if(tree[pos]==-1){
			tree[pos]=n;
			return;
		}
		printf("\nElement already present here!\n");
	}
	else{
		pos=pos*2+2;
		if(tree[pos]==-1){
			tree[pos]=n;
			return;
		}
		printf("\nElement already present here!\n");
	}
}

int find(int n){
	int i;
	for(i=0;i<size;i++){
		if(n==tree[i]){
			return i;
		}
	}
	return -1;
}

void levelorder(){
	int i;
	printf("Level Order Traversal:\n");
	for(i=0;i<size;i++){
		if(tree[i]!=-1)
			printf("%d ",tree[i]);
	}
}

void inorder(int i){
	if(i>=size)
		return;
	if(tree[i]==-1)
		return;
	inorder(2*i+1);
	printf("%d ",tree[i]);
	inorder(2*i+2);
}

void preorder(int i){
	if(i>=size)
		return;
	if(tree[i]==-1)
		return;
	printf("%d ",tree[i]);
	preorder(2*i+1);
	preorder(2*i+2);
}

void postorder(int i){
	if(i>=size)
		return;
	if(tree[i]==-1)
		return;
	postorder(2*i+1);
	postorder(2*i+2);
	printf("%d ",tree[i]);
}

int main(){
	int n,par,dir,ch,i;//count stores the numb of nodes
	printf("Enter the depth of the tree: ");
	scanf("%d",&size);//stores depth
	size=pow(2,size+1)-1;
	//initialise tree to -1
	for(i=0;i<MAX;i++){
		tree[i]=-1;
	}
	while(1){
		printf("\nMENU:\n1.Insert\n2.Find\n3.Level Order Traversal\n4.In order Traversal\n5.Preorder Traversal\n6.Postorder Traversal\n7.Exit\n\nEnter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter number to be inserted: ");
				scanf("%d",&n);
				if(tree[0]==-1){
					tree[0]=n;
					break;
				}
				printf("Enter parent's value: ");
				scanf("%d",&par);
				printf("Enter 1 for left child and 0 for right child: ");
				scanf("%d",&dir);
				insert(n,par,dir);
				break;
			case 2:
				printf("\nEnter number to be searched for: ");
				scanf("%d",&n);
				if(find(n)==-1){
					printf("\nNot found\n");
				}
				else{
					printf("\nFound\n");
				}
				break;
			case 3:
				levelorder();
				break;
			case 4:
				printf("\nInorder Traversal:\n");
				inorder(0);
				break;
			case 5:
				printf("\nPreorder Traversal:\n");
				preorder(0);
				break;
			case 6:
				printf("\nPostorder Traversal:\n");
				postorder(0);
				break;
			case 7:
				return 0;
			default:
				printf("Invalid Choice. Try again\n");
				break;
		}
	}
}

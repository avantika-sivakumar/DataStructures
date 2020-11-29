#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;
};

struct node*root=NULL;

struct node* insert(struct node*root,int n);
struct node* del(struct node*root,int n);
struct node*min(struct node*root);
int search(struct node*root,int n);
void inorder(struct node*root);
void preorder(struct node*root);
void postorder(struct node*root);

struct node* insert(struct node*root,int n){
	if(root==NULL){
  		root=(struct node*)malloc(sizeof(struct node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(root->data>n){
		root->left=insert(root->left,n);
	}
	else if(root->data<n){
		root->right=insert(root->right,n);
	}
	else if(root->data==n){
		printf("Duplicate value\n");
	}
	return root;
}

struct node* del(struct node*root,int n){
	struct node*temp;
	if(root==NULL){
		printf("Tree is empty\n");
		return root;
	}
	else if(root->data>n){
		root->left=del(root->left,n);
	}
	else if(root->data<n){
		root->right=del(root->right,n);
	}
	else if (root->left && root->right) {
		temp=min(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
    }
    else{
    	temp=root;
    	if(root->left==NULL){
    		root=root->right;
		}
		else if(root->right==NULL){
			root=root->left;
		}
		free(temp);
	}
	return root;
}

struct node*min(struct node*root){
	if(root==NULL)
		return NULL;
	else if(root->left==NULL)
		return root;
	else
		return min(root->left);
}

int search(struct node*root,int n){
	if(root==NULL){
		printf("Not found\n");
		return 0;
	}
	else if(root->data==n){
		printf("Found\n");
		return 1;
	}
	else if(n<root->data){
		search(root->left,n);
	}
	else{
		search(root->right,n);
	}
}

void inorder(struct node*root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(struct node*root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node*root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

int main(){
	int ch,n;
	while(1){
		printf("\nMENU:\n");
		printf("1. Insert\n2. Delete\n3. Find\n4. Inorder traversal\n5. Preorder traversal\n6. Postorder traversal\n7. Exit\nEnter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter a number: ");
				scanf("%d",&n);
				root=insert(root,n);
				break;
			case 2:
				printf("Enter a number: ");
				scanf("%d",&n);
				root=del(root,n);
				break;
			case 3:
				printf("Enter a number: ");
				scanf("%d",&n);
				search(root,n);
				break;
			case 4:
				printf("Inorder traversal:\n");
				inorder(root);
				break;
			case 5:
				printf("Preorder traversal:\n");
				preorder(root);
				break;
			case 6:
				printf("Postorder traversal:\n");
				postorder(root);
				break;
			case 7:
				return 0;
			default:
				printf("Invalid choice\n");
				break;
		}
	}
}

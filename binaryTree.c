#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;
};

struct node*root=NULL;
struct node*temp=NULL;

void create(int n);
void insert(int n,int parent,char dir);
void del(int n);
void find(struct node*root,int n);
void findParent(struct node*root,int n);
void inorder(struct node*root);
void preorder(struct node*root);
void postorder(struct node*root);

void create(int n){
	root=(struct node*)malloc(sizeof(struct node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;
}

void insert(int n,int parent,char dir){
	find(root,parent);
	struct node*a=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No such parent node found\n");
		return;
	}
	a->data=n;
	a->right=NULL;
	a->left=NULL;
	if(dir==0){
		a->right=temp->right;
		temp->right=a;
	}
	else{
		a->left=temp->left;
		temp->left=a;
	}
	temp=NULL;
}

void del(int n){
	struct node*fr=NULL;//to store element to be freed later
	struct node*par=NULL;
	temp=NULL;
	find(root,n);
	fr=temp;
	if(temp==NULL){
		printf("No such element found\n");
		return;
	}
	temp=NULL;
	findParent(root,n);
	par=temp;
  	//if node has both children
	if(fr->right && fr->left){
		if(par->left){
    	  if((par->left)->data==n){// if its the left child
        	par->left=fr->left;
        	par=par->left;
        	while(par->left&&par->right){
          		par=par->right;
        	}
	        if(par->right==NULL){
	          par->right=fr->right;
	        }
	        else{
	          par->left=fr->right;
	        }
	        free(fr);
	        temp=NULL;
	        return;
	      }
		}
		else{
			par->right=fr->right;
			par=par->right;
			while(par->left&&par->right){
				par=par->left;
			}
			if(par->left==NULL){
				par->left=fr->left;
			}
			else{
				par->right=fr->left;
			}
			free(fr);
			temp=NULL;
			return;
		}
		}
	  //if it is the right child
	  if(par->right){
	    if(par->right->data==n){
	        if(fr->right){
	          par->right=fr->right;
	        }
	        else if(fr->left){
	          par->right=fr->left;
	        }
	        else{
	          //if leaf node
	          par->right=NULL;
	        }
	        temp=NULL;
	        free(fr);
	        return;
	    }
	  }
	  if(par->left){
      if(par->left->data==n){//fr is the left child of par
		    if(fr->right){
		    	par->left=fr->right;
		    }
	        else if(fr->left){
	        	par->left=fr->left;
	        }
	        else{
	          //if leaf node
	          par->left=NULL;
	        }
	        temp=NULL;
	        free(fr);
	        return;
	  }
    }
    temp=NULL;
    free(fr);
}

void find(struct node*root,int n){
	if(root==NULL){
		return;
	}
	if(root->data==n){
		temp=root;
		return;
	}
	find(root->left,n);
	find(root->right,n);
}

void findParent(struct node*root,int n){
	if(((root->right)==NULL)&&((root->left)==NULL)){
		return;
	}
	if(root->right){
		if((root->right)->data==n){
			temp=root;
			return;
		}
	}
	if(root->left){
		if((root->left)->data==n){
			temp=root;
			return;
		}
	}
	findParent(root->left,n);
	findParent(root->right,n);
}

void inorder(struct node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(struct node*root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node*root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

int main(){
	int ch,n,p,dir;
	while(1){
		printf("\nMENU:\n");
		printf("1. Insert\n2. Delete\n3. Find\n4. Inorder traversal\n5. Preorder traversal\n6. Postorder traversal\n7. Exit\nEnter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter a number: ");
				scanf("%d",&n);
				if(root==NULL){
					create(n);
				}
				else{
					printf("Enter the parent node's number: ");
					scanf("%d",&p);
					printf("Enter 0 to insert to the right and 1 to the left: ");
					scanf("%d",&dir);
					insert(n,p,dir);
				}
				break;
			case 2:
				printf("Enter a number: ");
				scanf("%d",&n);
				del(n);
				break;
			case 3:
				printf("Enter a number: ");
				scanf("%d",&n);
				find(root,n);
				if(temp==NULL){
					printf("Not found\n");
				}
				else{
					printf("Found\n");
					temp=NULL;
				}
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

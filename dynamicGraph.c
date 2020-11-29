//graph dynamic
#include<stdio.h>
#include<stdlib.h>

#define MAX 20//max no of vertices

struct vertex{
	int n;
	struct vertex*next;
};

struct vertex *vertices[MAX];
int visited[MAX];
int inpath[MAX];
int vert=-1;//no of vertices-1/index of the last vertex

int cycle=0;//becomes 1 if cyclic

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int);
int dequeue();

void addVertex();
void addEdge();
int find(int);
void display();
void init();
void bfs();
void dfs(int);

void enqueue(int n){
	if(front==-1){
		front++;
	}
	rear++;
	queue[rear]=n;
}

int dequeue(){
	int n=queue[front];
	printf("%d ",n);
	if(front==rear){
		front=-1;
		rear=-1;
		return n;
	}
	front++;
	return n;
}

void addVertex(){
	int v;//stores the vertex number
	struct vertex*ver=(struct vertex*)malloc(sizeof(struct vertex));
	printf("Enter the vertex number: ");
	scanf("%d",&v);
	if(find(v)!=-1){
		printf("Vertex already exists\n");
		return;
	}
	ver->n=v;
	ver->next=NULL;
	vertices[++vert]=ver;
}

void addEdge(){
	int src,dest,i;
	struct vertex*ptr;
	struct vertex*ver;
	printf("Enter the starting and ending vertex: ");
	scanf("%d %d",&src,&dest);
	if((find(src)==-1)||(find(dest)==-1)){
		printf("Source or destination vertex does not exist\n");
		return;
	}
	//create a copy of dest node/vertex:
	ver=(struct vertex*)malloc(sizeof(struct vertex));
	ver->n=dest;
	ver->next=NULL;
	ptr=vertices[find(src)];
	while(ptr->next){
		ptr=ptr->next;
	}
	ptr->next=ver;
}

int find(int no){
	int i;
	for(i=0;i<=vert;i++){
		if(vertices[i]->n==no){
			return i;
		}
	}
	return -1;
}

void display(){
	int i;
	struct vertex*ptr;
	if(vert==-1){
		printf("Empty graph\n");
		return;
	}
	for(i=0;i<=vert;i++){
		ptr=vertices[i];
		while(ptr->next){
			printf("%d -> ",ptr->n);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->n);
	}
}

void init(){
	int i;
	for(i=0;i<=vert;i++){
		visited[i]=0;
		inpath[i]=0;
	}
}

void bfs(){
	int i=0;
	struct vertex*ptr;
	enqueue(vertices[0]->n);
	visited[0]=1;
	while(!(front==-1&&rear==-1)){
		i=dequeue();
		ptr=vertices[find(i)];
		while(ptr){
			if(visited[find(ptr->n)]==0){
				visited[find(ptr->n)]=1;
				enqueue(ptr->n);
			}
			ptr=ptr->next;
		}
	}
}

void dfs(int v){
	struct vertex*ptr=vertices[find(v)];
	struct vertex*temp=ptr;
	visited[find(v)]=1;
	printf("%d ",v);
	while(temp){
		if(visited[find(temp->n)]==0){
			dfs(temp->n);
		}
		temp=temp->next;
	}
}

void cyclic(int v){
	struct vertex*temp=vertices[find(v)];
	temp=temp->next;
	visited[find(v)]=1;
	inpath[find(v)]=1;
	while(temp){
		if(inpath[find(temp->n)]==1){//if marked as inpath
			cycle=1;
			return;
		}
		else if(visited[find(temp->n)]==0){//if marked as visited
			cyclic(temp->n);
		}
		temp=temp->next;
	}
	inpath[find(v)]=0;
}

int main(){
	int ch,n;
	while(1){
		printf("\nMENU:\n1.Insert a vertex\n2.Insert an edge\n3.Check if vertex exists\n4.Display adjacency list\n5.BFS traversal\n6.DFS traversal\n7.Check if cyclic\n8.Exit\nEnter a number: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				addVertex();
				break;
			case 2:
				addEdge();
				break;
			case 3:
				printf("Enter vertex: ");
				scanf("%d",&n);
				if(find(n)!=-1){
					printf("Found\n");
				}
				else{
					printf("Not Found\n");
				}
				break;
			case 4:
				display();
				break;
			case 5:
				init();
				printf("BFS traversal:\n");
				bfs();
				break;
			case 6:
				init();
				printf("DFS Traversal:\n");
				dfs(vertices[0]->n);
				break;
			case 7:
				cycle=0;
				init();
				cyclic(vertices[0]->n);
				if(cycle==1){
					printf("The graph is cyclic\n");
				}
				else{
					printf("The graph is acyclic\n");
				}
				break;
			case 8:
				return 0;
			default:
				printf("Enter valid choice\n");
				break;
		}
	}
}

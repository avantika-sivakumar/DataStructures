//graph-static

#include<stdio.h>

#define MAX 20

int adj[MAX][MAX];
int vert=-1;//no of vertices-1/index of last vertex/name of vertex

int cycle=0;//1 if graph is cyclic

int visited[MAX];
int inpath[MAX];

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int);
int dequeue();

void addEdge(int v1,int v2);
void display();
void init();
void bfs();
void dfs(int);
void cyclic(int);

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

void addEdge(int v1,int v2){
	if(v1>vert||v2>vert||v1<0||v2<0){
		printf("Source of destination vertex not found\n");
		return;
	}
	adj[v1][v2]=1;
}

void display(){
	int i,j;
	printf("\nAdjacency Matrix: \n");
	for(i=0;i<=vert;i++){
		for(j=0;j<=vert;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}

void init(){
	int i;
	for(i=0;i<=vert;i++){
		visited[i]=0;
	}
}

void bfs(){
	int i,j;
	enqueue(0);
	visited[0]=1;
	while(!(rear==-1 && front==-1)){
		i=dequeue();
		for(j=0;j<=vert;j++){
			if(adj[i][j]==1&&visited[j]==0){
				enqueue(j);
				visited[j]=1;
			}
		}
	}
}

void dfs(int v){
	int j;
	visited[v]=1;
	printf("%d ",v);
	for(j=0;j<=vert;j++){
		if(adj[v][j]==1&&visited[j]==0){
			dfs(j);
		}
	}
}

void cyclic(int v){
	int j;
	visited[v]=1;
	inpath[v]=1;
	for(j=0;j<=vert;j++){
		if(adj[v][j]==1&&inpath[j]==1){
			cycle=1;
			return;
		}
		else if(adj[v][j]==1&&visited[j]==0){
			cyclic(j);
		}
	}
	inpath[v]=0;
}

int main(){
	int ch,v1,v2;
	while(1){
		printf("\nMENU:\n1.Add a vertex\n2.Add an edge\n3.Display the adjacency matrix\n4.BFS Traversal\n5.DFS Traversal\n6.Check if cyclic\n7.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				vert++;
				printf("Added vertex %d\n",vert);
				break;
			case 2:
				printf("Enter source and destination vertices: ");
				scanf("%d %d",&v1,&v2);
				addEdge(v1,v2);
				break;
			case 3:
				display();
				break;
			case 4:
				init();
				bfs();
				break;
			case 5:
				init();
				dfs(0);
				break;
			case 6:
				init();
				cycle=0;
				cyclic(0);
				if(cycle==1){
					printf("The graph is cyclic\n");
				}
				else{
					printf("The graph is acyclic\n");
				}
				break;
			case 7:
				return 0;
			default:
				printf("Enter valid choice\n");
				break;
		}
	}
}

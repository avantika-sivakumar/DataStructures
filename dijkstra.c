//dijkstra's shortest path algorithm
#include<stdio.h>

#define MAX 20

struct graph{
	int adj[MAX][MAX];
	int vert;//no of vertices-1/index of last vertex/name of vertex
	int edges;//no of edges
};

int visited[MAX];//1 if vertex (index) is added to path, else zero
int d[MAX];//distance from source

void addEdge(struct graph*,int v1,int v2,int weight);
void display(struct graph*);
void init(struct graph*,int);
int done(struct graph*);//checks if visited contains all vertices
void dijkstra(struct graph *g);

void addEdge(struct graph*g,int v1,int v2,int wt){
	if(v1>g->vert||v2>g->vert||v1<0||v2<0){
		printf("Vertices not found\n");
		return;
	}
	g->adj[v1][v2]=wt;
	g->adj[v2][v1]=wt;
	g->edges++;
}

void display(struct graph*g){
	int i,j;
	printf("\nAdjacency Matrix: \n");
	for(i=0;i<=g->vert;i++){
		for(j=0;j<=g->vert;j++){
			printf("%d ",g->adj[i][j]);
		}
		printf("\n");
	}
}

void init(struct graph*g,int src){
	int i;
	for(i=0;i<=g->vert;i++){
		d[i]=1000;//inf
	    visited[i]=0;
	}
	d[src]=0;
}

int done(struct graph*g){
	int i;
	for(i=0;i<=g->vert;i++){
		if(visited[i]==0)
			return 0;
	}
	return 1;
}

void dijkstra(struct graph *g){
	int i,u;
	int smallest=1000;//inf
	while(!done(g)){
		smallest=1000;
		for(i=0;i<=g->vert;i++){
			if(visited[i]==0 && smallest>d[i]){
				smallest=d[i];
				u=i;
			}
		}
		//we've found the next vertex to be added and stored it in u
		visited[u]=1;
		for(i=0;i<=g->vert;i++){
			if(g->adj[u][i]>0){
				if(d[u]+g->adj[u][i]<d[i])
					d[i]=d[u]+g->adj[u][i];
			}
		}
	}
	
	//printing shortest path table
	printf("Vertex\tShortest distance from source\n");
	for(i=0;i<=g->vert;i++){
		printf("  %d\t\t  %d\n",i,d[i]);
	}
}

int main(){
	int ch,v1,v2,i,j;
	struct graph g;
	struct graph mst;
	g.vert=-1;
	g.edges=0;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			g.adj[i][j]=0;
		}
	}
	while(1){
		printf("\nMENU:\n1.Add a vertex\n2.Add an edge\n3.Display the adjacency matrix\n4.Dijkstra's shortest path\n5.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				g.vert++;
				mst.vert++;
				printf("Added vertex %d\n",g.vert);
				break;
			case 2:
				printf("Enter the vertices, and the weight of the edge: ");
				scanf("%d %d %d",&v1,&v2,&i);
				addEdge(&g,v1,v2,i);
				break;
			case 3:
				display(&g);
				break;
			case 4:
				printf("Enter source vertex: ");
				scanf("%d",&i);
				init(&g,i);
				dijkstra(&g);
				break;
			case 5:
				return 0;
			default:
				printf("Enter valid choice\n");
				break;
		}
	}
}

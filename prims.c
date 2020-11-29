//prims

#include<stdio.h>

#define MAX 20

struct graph{
	int adj[MAX][MAX];
	int vert;//no of vertices-1/index of last vertex/name of vertex
	int edges;//no of edges
};

int mstSet[MAX];//1 if vertex (index) is added to mst, else zero
int key[MAX][2];//keyvalue,corresponding vertex

void addEdge(struct graph*,int v1,int v2,int weight);
void display(struct graph*);
void init(struct graph*);
int mstFull(struct graph*);//checks if mstSet contains all vertices
void prims(struct graph *g,struct graph*mst);

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

void init(struct graph*g){
	int i;
	for(i=0;i<=g->vert;i++){
		key[i][0]=1000;//inf
		key[i][1]=-1;
		mstSet[i]=0;
	}
	key[0][0]=0;
}

int mstFull(struct graph*g){
	int i;
	for(i=0;i<=g->vert;i++){
		if(mstSet[i]==0)
			return 0;
	}
	return 1;
}

void prims(struct graph *g,struct graph*mst){
	int i,u;
	int smallest=1000;//inf
	while(!mstFull(g)){
		smallest=1000;
		for(i=0;i<=g->vert;i++){
			if(mstSet[i]==0 && smallest>key[i][0]){
				smallest=key[i][0];
				u=i;
			}
		}
		//we've found the next vertex to be added and stored it in u
		mstSet[u]=1;
		if(!(u==0)){//if not first time
			addEdge(mst,key[u][1],u,g->adj[key[u][1]][u]);
		}
		for(i=0;i<=g->vert;i++){
			if(g->adj[u][i]>0 && mstSet[i]==0){
				if(g->adj[u][i]<key[i][0]){
					key[i][0]=g->adj[u][i];
					key[i][1]=u;
				}
			}
		}
	}
}

int main(){
	int ch,v1,v2,i,j;
	struct graph g;
	struct graph mst;
	g.vert=-1;
	mst.vert=-1;
	g.edges=0;
	mst.edges=0;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			g.adj[i][j]=0;
			mst.adj[i][j]=0;
		}
	}
	while(1){
		printf("\nMENU:\n1.Add a vertex\n2.Add an edge\n3.Display the adjacency matrix\n4.Display the adjacency matrix of the minimum spanning tree(PRIMS METHOD)\n5.Exit\nEnter your choice: ");
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
				init(&g);
				prims(&g,&mst);
				printf("Adjacency matrix of minimum spanning tree using prim's method:\n");
				display(&mst);
				break;
			case 5:
				return 0;
			default:
				printf("Enter valid choice\n");
				break;
		}
	}
}

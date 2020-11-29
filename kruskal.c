//kruskal

#include<stdio.h>

#define MAX 20

struct graph{
	int adj[MAX][MAX];
	int vert;//no of vertices-1/index of last vertex/name of vertex
	int edges;//no of edges
};

int parent[MAX];

void addEdge(struct graph*,int v1,int v2,int weight);
void display(struct graph*);
void init(struct graph*);
void kruskals(struct graph *g,struct graph*mst);
int cycle(struct graph*);

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
		parent[i]=-1;
	}
}

void kruskals(struct graph *g,struct graph*mst){
	int i,j,k=0;
	int smallest,pos,tempsrc,tempdest,temp;
	//arrange edges:
	int edgeList[3][g->edges];//edgeList[0]-source, edgeList[1]-dest, edgeList[2]-weight
	//first add all the edges:
	for(i=0;i<=g->vert;i++){
		for(j=0;j<=i;j++){
			if(g->adj[i][j]>0){
				edgeList[0][k]=i;
				edgeList[1][k]=j;
				edgeList[2][k++]=g->adj[i][j];
			}
		}
	}
	//sort edges: ascending order of edgeList[2]
	for(i=0;i<=g->edges;i++){
		smallest=edgeList[2][i];
		pos=i;
		for(j=i;j<=g->edges;j++){
			if(edgeList[2][j]<smallest){
				smallest=edgeList[2][j];
				pos=j;
			}
		}
		//switch smallest and edgeList[2][i]
		tempsrc=edgeList[0][pos];
		tempdest=edgeList[1][pos];
		edgeList[0][pos]=edgeList[0][i];
		edgeList[1][pos]=edgeList[1][i];
		edgeList[2][pos]=edgeList[2][i];
		edgeList[0][i]=tempsrc;
		edgeList[1][i]=tempdest;
		edgeList[2][i]=smallest;
	}
	//list is sorted. traverse list and add edge to mst unless it forms a cycle
	for(i=0;mst->edges < g->vert;i++){
		addEdge(mst,edgeList[0][i],edgeList[1][i],edgeList[2][i]);
		//check for cycle in mst
		init(mst);
		if(cycle(mst)){
			//del that edge
			mst->adj[edgeList[0][i]][edgeList[1][i]]=0;
			mst->adj[edgeList[1][i]][edgeList[0][i]]=0;
			mst->edges--;
		}
	}
}

int cycle(struct graph*mst){
	int i,j,p1,p2,p1pos,p2pos;
	for(i=0;i<=mst->vert;i++){
		for(j=0;j<=i;j++){
			if(mst->adj[i][j]>0){
				//edge exists
				//find parent of src,dest(i,j)
				p1=parent[i];
				p1pos=i;
				p2=parent[j];
				p2pos=j;
				while(p1>=0){
					p1pos=p1;
					p1=parent[p1];
				}
				while(p2>=0){
					p2pos=p2;
					p2=parent[p2];
				}
				if(p1pos==p2pos){
					return 1;//CYCLE FOUND
				}
				//union:
				parent[p1pos]--;
				parent[p2pos]=p1pos;
			}
		}
	}
	return 0;
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
		printf("\nMENU:\n1.Add a vertex\n2.Add an edge\n3.Display the adjacency matrix\n4.Display the adjacency matrix of the minimum spanning tree(KRUSKALS METHOD)\n5.Exit\nEnter your choice: ");
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
				kruskals(&g,&mst);
				printf("Adjacency matrix of minimum spanning tree using kruskal's method:\n");
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

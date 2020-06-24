//#include <stdio.h>
//#include <conio.h>
//#define SIZE 15
//#define INFINITY 99999
//#define VISITED 0
//#define UNVISITED 1
//
//
//void dijkstra(int graph[SIZE][SIZE],int Vertices,int src);
//void display();
//
//
//
//int main() {
//	int G[SIZE][SIZE],i,j,n,u;
//	printf("Enter no. of vertices:");
//	scanf("%d",&n);
//	printf("\nEnter the adjacency matrix:\n");
//	
//	for(i=0;i<n;i++)
//		for(j=0;j<n;j++)
//			scanf("%d",&G[i][j]);
//	
//	printf("\nEnter the starting node:");
//	scanf("%d",&u);
//	dijkstra(G,n,u);
//	
//	return 0;
//}
//
//void dijkstra(int graph[SIZE][SIZE],int Vertices,int src) {
//	int i, j,k, Distance[Vertices], mark[SIZE], minimum, otherpath,weight,ndx = 0;
//	
//	for (i = 0; i < Vertices; i++) {
//		if (graph[src][i] == 0) {
//			Distance[i] = INFINITY;
//		}else {
//			Distance[i] = graph[src][i];
//		}
//		printf("Distance[%d] = %d\n",i,Distance[i]);
//	}
//	
//	for (i = 0; i < Vertices; i++) {
//		mark[i] = UNVISITED;
//	}
//	
//	mark[src] = VISITED;
//	Distance[src] = 0;
//	
////	for (i=0;i<Vertices;i++) {
////		printf("mark[%d] = %d\n",i,mark[i]);
////		printf("Distance[%d] = %d",i,Distance[i]);
////	}
////	
//	for (i = 0; i < Vertices; i++) {
//		minimum = INFINITY;
////		minimumIndex = src;
//		for (j = 0; j < Vertices; j++) {
//			if (mark[j] != VISITED) {
//				if (minimum == INFINITY) {
//					minimum = j;
//				}else {
//					minimum = (Distance[j] < Distance[minimum]) ? j : minimum;
//				}
////				minimum = Distance[j];
////				minimumIndex = j;
////				minimumValue = Distance[j];
////				weight = Distance[j];
//			}
//		}
//
////	printf("Minimum Index : %d\n",minimumIndex);
////	printf("Minimum Value : %d\n",minimumValue);
//	mark[minimum] = VISITED;
////	Distance[minimumIndex] = 0;
//	
//		
//		for (k = 0; k < Vertices; k++) {
//			if (mark[k] != VISITED) {
//				/*Pseudocode:
//				D[k] = min(D[k], D[w] + graph[w][k];
//				*/
//				otherpath = Distance[minimum] + graph[minimum][k];
////				printf("Graph value: %d\n",otherpath);
//				Distance[k] = (Distance[k] < otherpath) ? Distance[k] : otherpath;
//			}
//		}
//	}
//	
//	
//	printf("Vertex    Distance from source/starting point\n");
//	for (i = 0; i < Vertices; i++) {
//		printf("%d \t\t %d\n",i,Distance[i]);
//	}
//	
//}

#include <stdio.h>
#include <conio.h>
#define SIZE 15
#define INFINITY 99999
#define VISITED 0
#define UNVISITED 1


void dijkstra(int graph[SIZE][SIZE],int Vertices,int src);
void display();



int main() {
	int G[SIZE][SIZE],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix:\n");
	/* Example:
		
	
	 */
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	return 0;
}

void dijkstra(int graph[SIZE][SIZE],int Vertices,int src) {
	int i, j,k, Distance[Vertices], mark[SIZE], minimum, otherpath,weight,ndx = 0;
	
	for (i = 0; i < Vertices; i++) {
		Distance[i] = graph[src][i];
	}
	
	for (i = 0; i < Vertices; i++) {
		mark[i] = UNVISITED;
	}
	
	mark[src] = VISITED;
	Distance[src] = 0;
	
	for (i = 1; i < Vertices; i++) {
		minimum = INFINITY;
		
		for (j = 0; j < Vertices; j++) {
			if (mark[j] != VISITED){
				if(minimum==INFINITY){
					minimum = j;
				}else{
					minimum=(Distance[j]<Distance[minimum])?j:minimum;
				}
			}
		}

	
	mark[minimum] = VISITED;
	
		
		for (k = 0; k < Vertices; k++) {
			if (mark[k] != VISITED) {
				/*Pseudocode:
				D[k] = min(D[k], D[w] + graph[w][k];
				*/
				otherpath = Distance[minimum] + graph[minimum][k];
				Distance[k] = (Distance[k] > otherpath) ? otherpath :Distance[k];
			}
		}
	}
	
	
	printf("Vertex    Distance from source\n");
	for (i = 0; i < Vertices; i++) {
		printf("%d \t\t %d\n",i,Distance[i]);
	}
	
}


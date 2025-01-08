#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int adj[MAX][MAX];
int visited[MAX]; 
void dfs(int vertex, int n) {
printf("%d ", vertex);
visited[vertex] = 1;
for (int i = 0; i < n; i++) {
if (adj[vertex][i] == 1 && !visited[i]) {
dfs(i, n);
}
}
}
int main(){
int n, edges, u, v, startVertex;
printf("Enter the number of vertices: ");
scanf("%d", &n);
printf("Enter the number of edges: ");
scanf("%d", &edges);
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++)
adj[i][j] = 0;
visited[i] = 0;
}
printf("Enter the edges (u v):\n");
for (int i = 0; i < edges; i++) {
scanf("%d %d", &u, &v);
adj[u][v] = 1;  
adj[v][u] = 1; 
}
printf("Enter the starting vertex: ");
scanf("%d", &startVertex);
printf("DFS Traversal: ");
dfs(startVertex, n);
printf("\n");
return 0;
}

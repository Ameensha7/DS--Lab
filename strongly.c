#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
typedef struct Node{
int vertex;
struct Node* next;
}
Node;
typedef struct Graph{
int numVertices;
Node**adjLists;
bool*visited;
}
Graph;
int stack[MAX];
int top=-1;
void push(int v){
stack[++top]=v;
}
int pop(){
return stack[top--];
}
Node*createNode(int v){
Node*newNode=(Node*)malloc(sizeof(Node));
newNode->vertex=v;
newNode->next=NULL;
return newNode;
}
Graph*createGraph(int vertices){
Graph*graph=(Graph*)malloc(sizeof(Graph));
graph->numVertices=vertices;
graph->adjLists=(Node**)malloc(vertices*sizeof(Node*));
graph->visited=(bool*)malloc(vertices*sizeof(bool));
for(int i=0;i<vertices;i++){
graph->adjLists[i]=NULL;
graph->visited[i]=false;
}
return graph;
}
void addEdge(Graph *graph,int src,int dest){
Node* newNode=createNode(dest);
newNode->next=graph->adjLists[src];
graph->adjLists[src]=newNode;
}
void DFS(Graph*graph,int vertex,bool storeInStack){
graph->visited[vertex]=true;
printf("%d",vertex);
Node*temp=graph->adjLists[vertex];
while(temp){
int connectedVertex=temp->vertex;
if(!graph->visited[connectedVertex]){
DFS(graph,connectedVertex,storeInStack);
}
temp=temp->next;
}
if(storeInStack){
push(vertex);
}
}
Graph*transposeGraph(Graph*graph){
Graph*transpose=createGraph(graph->numVertices);
for(int v=0;v<graph->numVertices;v++){
Node*temp=graph->adjLists[v];
while(temp){
addEdge(transpose,temp->vertex,v);
temp=temp->next;
}
}
return transpose;
}
void findSCCs(Graph*graph){
for(int i=0;i<graph->numVertices;i++){
if(!graph->visited[i]){
DFS(graph,i,true);
}
}
Graph*transpose=transposeGraph(graph);
for(int i=0;i<graph->numVertices;i++){
transpose->visited[i]=false;
}
printf("Strongly Connected Components:\n");
while(top!=-1){
int v=pop();
if(!transpose->visited[v]){
DFS(transpose,v,false);
printf("\n");
}
}
}
int main(){
int vertices,edges,src,dest;
printf("Enter the number of vertices:");
scanf("%d",&vertices);
printf("Enter the number of edges:");
scanf("%d",&edges);
Graph*graph=createGraph(vertices);
printf("Enter the edges(sources and destination):\n");
for(int i=0;i<edges;i++){
scanf("%d %d",&src,&dest);
addEdge(graph,src,dest);
}
findSCCs(graph);
return 0;
}








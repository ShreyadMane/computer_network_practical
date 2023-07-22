#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode);

int main()
{
int G[MAX][MAX],i,j,n,u;
printf("Enter no. of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
printf("\nEnter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

int cost[MAX][MAX],distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far
//create the cost matrix
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(G[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=G[i][j];
//initialize pred[],distance[] and visited[]
for(i=0;i<n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<n-1)
{
mindistance=INFINITY;
//nextnode gives the node at minimum distance
for(i=0;i<n;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}
//check if a better path exists through nextnode
visited[nextnode]=1;
for(i=0;i<n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i]<distance[i])
{
distance[i]=mindistance+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}

//print the path and distance of each node
for(i=0;i<n;i++)
if(i!=startnode)
{
printf("\nDistance of node%d=%d",i,distance[i]);
printf("\nPath=%d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=startnode);
}
}

/*Let the node at which we are starting be called the initial node. Let the distance of node Y be the distance from
the initial node to Y. Dijkstra's algorithm will initially start with infinite distances and will try to improve them step by
step.1. Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set. 2. Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other
nodes. During the run of the algorithm, the tentative distance of a node v is the length of the shortest path
discovered so far between the node v and the starting node. Since initially no path is known to any other vertex
than the source itself (which is a path of length zero), all other tentative distances are initially set to infinity. Set
the initial node as current. 3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances through the
current node. Compare the newly calculated tentative distance to the one currently assigned to the neighbor and
assign it the smaller one. For example, if the current node A is marked with a distance of 6, and the edge
connecting it with a neighbor B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was
previously marked with a distance greater than 8 then change it to 8. Otherwise, the current value will be kept. 4. When we are done considering all of the unvisited neighbors of the current node, mark the current node as
visited and remove it from the unvisited set. A visited node will never be checked again (this is valid and optimal
in connection with the behavior in step 6.: that the next nodes to visit will always be in the order of 'smallest
distance from initial node first' so any visits after would have a greater distance). 5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the
smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal;
occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The
algorithm has finished. 6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new current
node, and go back to step 3.*
o 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0 /

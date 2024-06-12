#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Function to add an edge to the adjacency list
void addEdge(int adj[MAX_NODES][MAX_NODES], int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}
// Function to perform Level Order traversal
void levelordertraversal(int adj[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    //adj: The adjacency matrix of the tree
    //numNodes: The maximum value Node + 1 present in the tree
    //startNode: Root Node i.e 0 
    //TODO: Complete the function to print the level order traversal of the tree
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int visited[MAX_NODES] = {0};
    queue[rear++] = startNode;
    visited[startNode] = 1;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < numNodes; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
     
}

int main() {
    int numEdges;
    scanf("%d", &numEdges);

    int adj[MAX_NODES][MAX_NODES] = {0};
    int numNodes = 0;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        if (u > numNodes) numNodes = u;
        if (v > numNodes) numNodes = v;
    }
    numNodes++; // Nodes are assumed to be zero-indexed, so increment by one for the count
    levelordertraversal(adj, numNodes, 0);
    printf("\n");

    return 0;
}
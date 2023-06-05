#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 6


int minKey(int weight[], bool visited[])
{
/*
  This Function is used to find the minimum weight
  edge value path when there are many paths have from any node.
*/
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++)
        if (visited[i] == false && weight[i] < min){
           min = weight[i];
           min_index = i;
        }

    return min_index;
}


void primMST(int graph[V][V], int startNode)
{

    int mst[V];       // Array to store constructed MST
    int weight[V];
    bool visited[V];  // array which is represented visited node

    // Initialize all keys as INFINITE and set all nodes as unvisited.
    for (int i = 0; i < V; i++){
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    weight[startNode] = 0;
    mst[startNode] = -1; // startNode node set to root of MST

    for (int count = 0; count < V - 1; count++) {

        int u = minKey(weight, visited);  // Find the minimum weight edge from the unvisited set of vertices
        visited[u] = true;  // set it as visited

        for (int i = 0; i < V; i++){
            if (graph[u][i] < weight[i] && visited[i] == false && graph[u][i] != 0){
                mst[i] = u;
                weight[i] = graph[u][i];
            }
        }
    }

    int cost = 0;
    // Printing the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
        cout << mst[i] << " - " << i << "  :  " << graph[i][mst[i]] << " \n";
        cost += graph[i][mst[i]];
    }
    cout << "\nTotal cost = " << cost << endl;
}

int main()
{
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };
    int startNode = 0;

    primMST(graph, startNode);

    return 0;
}

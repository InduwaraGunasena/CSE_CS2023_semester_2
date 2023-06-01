#include <iostream>
using namespace std;

#define MatrixSize 6


int dijkstraAlgo(int graph[MatrixSize][MatrixSize], int src)
{
    int time[MatrixSize];    // array to calculate the minimum time for each node
    bool visited[MatrixSize];    // boolean array to mark visited and unvisited nodes for each node


    for(int k = 0; k < MatrixSize; k++)
    {
        time[k] = INT_MAX;
        visited[k] = false;
    }

    time[src] = 0;  // we set the time as 0 for source node

    for(int q = 0; q < MatrixSize; q++)
    {
        int minimum = INT_MAX;
        int m;

        for(int i = 0; i < MatrixSize; i++)
        {
            if(visited[i] == false && time[i] <= minimum)
            {
                minimum = time[i];
                m = i;
            }
        }

        visited[m] = true;
        for(int a = 0; a < MatrixSize; a++)
        {
            if((time[m] != INT_MAX) && visited[a] == 0 && graph[m][a] && (time[m] + graph[m][a] < time[a]))
                time[a] = time[m] + graph[m][a];
        }
    }

    int totalTim = 0;

    for(int z = 0; z < MatrixSize; z++)
    {
        cout << "From node " << src << " to "<< z << " = " << time[z] << endl;
        totalTim += time[z];
    }

    cout << "Total time for each city = " << totalTim << endl;
    cout << "average time for each city = " << (double)totalTim/(MatrixSize-1) << endl;

}

int main()
{
    int graph[MatrixSize][MatrixSize] =
    {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };


    dijkstraAlgo(graph,5);


    return 0;
}

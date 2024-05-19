#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// A utility function to find the vertex with minimum distance value
int minDistance(int dist[], bool visit[], int V) 
{
    int min = INT_MAX, min_index; //set min to infinity and declare of min_index (represent the vertex with the min dis)
    for (int u = 0; u < V; u++)
        if (!visit[u] && dist[u] <= min) //if vertex u is not visited yet and his dist his smaller then current min 
            min = dist[u], min_index = u;//update min and min_index 
    return min_index; //return the min index
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex: \t \t \t Distance from Source:\n");
    for (int i = 0; i < V; i++)
        printf("%d \t \t \t \t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int **graph, int src, int V) 
{
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    bool visit[V]; // visit[i] will be true if vertex i is included in shortest path 

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, visit[i] = false; //set all the distances to infinity and visit to false
    }
    dist[src] = 0; //set the src vetex dist to 0(starting point)

    for (int count = 0; count < V - 1; count++) //relax phase
    {
        int u = minDistance(dist, visit, V);// every time we set the index of min dist to vertex u
        visit[u] = true; //cause we reach vertex u now he is visited

        for (int i = 0; i < V; i++)
        {
            if (!visit[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i]; //relax the edge
        }
    }

    printSolution(dist, V);//print all the shortestpaths from vertex src to all as matrix
}

// Function to validate input
bool validateGraph(int **graph, int V) 
{
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] < 0) // Dijkstra's algorithm doesn't support negative weights
                return false;
        }
    }
    return true;
}

int main() 
{
    while (1) 
    {
        int V;
        printf("New graph: \n");
        printf("Enter number of vertices: ");
        if (scanf("%d", &V) != 1 || V <= 0) break; // check that scanf is valid and that num of vertex > 0

        int **graph = (int **)malloc(V * sizeof(int *)); //memory allocation for adj matrix
        for (int i = 0; i < V; i++) 
        {
            graph[i] = (int *)malloc(V * sizeof(int)); // memory allocation for every row
        }

       printf("Enter the graph as an adjacency matrix:\n");
        bool validInput = true;
        for (int i = 0; i < V; ++i) 
        {
            for (int j = 0; j < V; ++j) 
            {
                if (scanf("%d", &graph[i][j]) != 1) { // Validate that input is an integer
                    validInput = false;
                    break;
                }
            }
            if (!validInput) break;
        }

        if (!validateGraph(graph, V)) //check if the graph is valid
        {
            printf("Invalid graph input. Please enter again.\n");
            for (int i = 0; i < V; i++) free(graph[i]);//if the graph isnt valid we will free the memory and continue the loop  
            free(graph);
            continue;
        }

        int src; //set src vertex to start with
        printf("Enter source vertex: ");
        if (scanf("%d", &src) != 1 || src < 0 || src >= V) 
        {//if scanf is invalid or src is negative or greater then num of vertices we cant run the algo
            printf("Invalid source vertex. Please enter again.\n");
            for (int i = 0; i < V; i++) free(graph[i]);
            free(graph); //free the memory of the graph and continue the loop
            continue;
        }

        dijkstra(graph, src, V);//run dijkstra algo from src vertex to all vertices

        for (int i = 0; i < V; i++) free(graph[i]);
        free(graph); // after we finish with the graph we will free the memory
    }

    return 0;
}

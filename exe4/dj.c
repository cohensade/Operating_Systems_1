#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V];

    while (true) {
        // Read the graph from stdin
        printf("Enter the adjacency matrix for the graph (%d x %d):\n", V, V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                scanf("%d", &graph[i][j]);
            }
        }

        // Check graph validity (ensure non-negative edge weights)
        bool valid = true;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] < 0) {
                    printf("Invalid graph! Edge weights must be non-negative.\n");
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (!valid) continue; // Restart loop if the graph is invalid

        // Perform Dijkstra's algorithm
        printf("Shortest distances from vertex 0:\n");
        dijkstra(graph, 0);

        // Ask user if they want to continue
        char choice;
        printf("\nDo you want to enter another graph? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') break;
    }

    return 0;
}


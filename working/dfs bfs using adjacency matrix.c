// Represent graph in adjacency matrix form and do DFS and bfs. Take input vertex and edges

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// structure to represent a graph
typedef struct graph {
    int num_vertices;
    bool adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// function to perform DFS on a graph
void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// function to perform BFS on a graph
void BFS(Graph* graph, int vertex, bool visited[]) {
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    visited[vertex] = true;
    queue[rear++] = vertex;

    while (front != rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex);

        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adjacency_matrix[current_vertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    // create a graph with 4 vertices
    Graph graph;
    graph.num_vertices = 4;
    graph.adjacency_matrix[0][1] = true;
    graph.adjacency_matrix[0][2] = true;
    graph.adjacency_matrix[1][2] = true;
    graph.adjacency_matrix[2][0] = true;
    graph.adjacency_matrix[2][3] = true;
    graph.adjacency_matrix[3][3] = true;

    // perform DFS and BFS on the graph starting from vertex 2
    bool visited[MAX_VERTICES] = {false};
    printf("DFS: ");
    DFS(&graph, 2, visited);
    printf("\n");

    for (int i = 0; i < graph.num_vertices; i++) {
        visited[i] = false;
    }

    printf("BFS: ");
    BFS(&graph, 2, visited);
    printf("\n");

    return 0;
}

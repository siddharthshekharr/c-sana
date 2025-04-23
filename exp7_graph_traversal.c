#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Queue is empty when front is -1
int isEmpty(struct Queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    return 0;
}

// Function to add an item to the queue
void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("\nQueue is full!");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("\nQueue is empty!");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Structure to represent a graph
struct Graph
{
    int numVertices;
    int **adjMatrix;
    int *visited;
};

// Function to create a graph with n vertices
struct Graph *createGraph(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = n;

    // Create adjacency matrix
    graph->adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    // Initialize visited array
    graph->visited = (int *)malloc(n * sizeof(int));

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    graph->adjMatrix[src][dest] = 1;

    // Add edge from dest to src (for undirected graph)
    graph->adjMatrix[dest][src] = 1;
}

// BFS traversal algorithm
void BFS(struct Graph *graph, int startVertex)
{
    // Initialize visited array
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->visited[i] = 0;
    }

    // Create a queue for BFS
    struct Queue *q = createQueue();

    // Mark the current node as visited and enqueue it
    graph->visited[startVertex] = 1;
    printf("\nBFS traversal starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    enqueue(q, startVertex);

    // Loop until queue is empty
    while (!isEmpty(q))
    {
        // Dequeue a vertex from queue
        int currentVertex = dequeue(q);

        // Get all adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjMatrix[currentVertex][i] == 1 && !graph->visited[i])
            {
                // Mark the adjacent vertex as visited and enqueue it
                printf("%d ", i);
                graph->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    free(q);
}

// Recursive DFS traversal algorithm
void DFSUtil(struct Graph *graph, int vertex)
{
    // Mark the current node as visited and print it
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all adjacent vertices
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMatrix[vertex][i] == 1 && !graph->visited[i])
        {
            DFSUtil(graph, i);
        }
    }
}

// DFS traversal
void DFS(struct Graph *graph, int startVertex)
{
    // Initialize visited array
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->visited[i] = 0;
    }

    printf("\nDFS traversal starting from vertex %d: ", startVertex);

    // Call the recursive DFS function
    DFSUtil(graph, startVertex);

    printf("\n");
}

// Function to create a graph from user input
struct Graph *createUserGraph()
{
    int numVertices, numEdges, i, src, dest;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph *graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
        {
            addEdge(graph, src, dest);
        }
        else
        {
            printf("Invalid edge! Vertices should be between 0 and %d.\n", numVertices - 1);
            i--; // Retry this edge
        }
    }

    return graph;
}

// Function to display the adjacency matrix
void displayAdjMatrix(struct Graph *graph)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    struct Graph *graph = NULL;
    int choice, startVertex;

    while (1)
    {
        printf("\n=== GRAPH TRAVERSAL OPERATIONS MENU ===\n");
        printf("1. Create a graph\n");
        printf("2. Display adjacency matrix\n");
        printf("3. BFS traversal\n");
        printf("4. DFS traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (graph != NULL)
            {
                // Free previous graph memory
                for (int i = 0; i < graph->numVertices; i++)
                {
                    free(graph->adjMatrix[i]);
                }
                free(graph->adjMatrix);
                free(graph->visited);
                free(graph);
            }
            graph = createUserGraph();
            break;
        case 2:
            if (graph == NULL)
            {
                printf("\nGraph not created yet! Please create a graph first.\n");
            }
            else
            {
                displayAdjMatrix(graph);
            }
            break;
        case 3:
            if (graph == NULL)
            {
                printf("\nGraph not created yet! Please create a graph first.\n");
            }
            else
            {
                printf("\nEnter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < graph->numVertices)
                {
                    BFS(graph, startVertex);
                }
                else
                {
                    printf("\nInvalid vertex! Vertex should be between 0 and %d.\n", graph->numVertices - 1);
                }
            }
            break;
        case 4:
            if (graph == NULL)
            {
                printf("\nGraph not created yet! Please create a graph first.\n");
            }
            else
            {
                printf("\nEnter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < graph->numVertices)
                {
                    DFS(graph, startVertex);
                }
                else
                {
                    printf("\nInvalid vertex! Vertex should be between 0 and %d.\n", graph->numVertices - 1);
                }
            }
            break;
        case 5:
            printf("\nExiting program. Goodbye!\n");
            if (graph != NULL)
            {
                // Free graph memory
                for (int i = 0; i < graph->numVertices; i++)
                {
                    free(graph->adjMatrix[i]);
                }
                free(graph->adjMatrix);
                free(graph->visited);
                free(graph);
            }
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
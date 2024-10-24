#include <iostream>
#include <iostream>

void addEdge(int** graph, int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight; // For undirected graph
}

void printGraph(int** graph, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int vertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;

    // Dynamically allocate memory for the adjacency matrix
    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0; // Initialize with no edges
        }
    }

    // Add edges
    int u, v, weight;
    char choice;
    do {
        std::cout << "Enter an edge (u v) and weight: ";
        std::cin >> u >> v >> weight;
        if(u < vertices && v < vertices) {
            addEdge(graph, u, v, weight);
        } else {
            std::cout << "Invalid vertices. Please enter vertices between 0 and " << vertices - 1 << std::endl;
        }
        std::cout << "Do you want to add another edge? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Print the adjacency matrix
    printGraph(graph, vertices);

    // Free dynamically allocated memory
    for (int i = 0; i < vertices; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}


/*
void addEdge(int** graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

void printGraph(int** graph, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int vertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;

    // Dynamically allocate memory for the adjacency matrix
    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0; // Initialize with no edges
        }
    }

    // Add edges
    int u, v;
    char choice;
    do {
        std::cout << "Enter an edge (u v): ";
        std::cin >> u >> v;
        if(u < vertices && v < vertices) {
            addEdge(graph, u, v);
        } else {
            std::cout << "Invalid vertices. Please enter vertices between 0 and " << vertices - 1 << std::endl;
        }
        std::cout << "Do you want to add another edge? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Print the adjacency matrix
    printGraph(graph, vertices);

    // Free dynamically allocated memory
    for (int i = 0; i < vertices; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
*/
#include <iostream>

// Node structure to represent both vertices and their edges
struct Node {
    int vertex;
    Node* nextVertex; // essentially the next of the linked list  // Points to the next vertex in the graph
    Node* adjList; // Points to the adjacent vertices (edges)

    // Constructor for easy node creation
    Node(int v, Node* adj = nullptr) : vertex(v), nextVertex(nullptr), adjList(adj) {}
};

// Graph class
class Graph {
private:
    Node* head; // Head of the graph (first vertex)

public:
    Graph() : head(nullptr) {}

    // Function to add a vertex to the graph
    void addVertex(int v) {
        Node* newNode = new Node(v);
        newNode->nextVertex = head;
        head = newNode;
    }

    // Function to add an edge from src to dest
    void addEdge(int src, int dest) {
        Node* srcVertex = findVertex(src);
        Node* destVertex = findVertex(dest);

        if (!srcVertex || !destVertex) return;

        // Add edge from src to dest
        srcVertex->adjList = new Node(dest, srcVertex->adjList);

        // Add edge from dest to src (if undirected)
        destVertex->adjList = new Node(src, destVertex->adjList);
    }

    // Function to find a vertex
    Node* findVertex(int v) {
        Node* current = head;
        while (current && current->vertex != v) {
            current = current->nextVertex;
        }
        return current;
    }

    // Function to print the graph
    void printGraph() {
        Node* current = head;
        while (current) {
            std::cout << "Vertex " << current->vertex << " connects to";
            Node* adj = current->adjList;
            while (adj) {
                std::cout << " " << adj->vertex;
                adj = adj->adjList;
            }
            std::cout << std::endl;
            current = current->nextVertex;
        }
    }
};

int main() {
    Graph g;

    // Add vertices
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}

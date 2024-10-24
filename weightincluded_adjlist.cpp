#include <iostream>

// Node structure to represent both vertices and their edges, with weight
struct Node {
    int vertex;
    int weight; // Added weight for the edge
    Node* nextVertex; // Points to the next vertex in the graph
    Node* adjList; // Points to the adjacent vertices (edges)

    // Constructor for easy node creation, with weight
    Node(int v, int w = 0, Node* adj = nullptr) : vertex(v), weight(w), nextVertex(nullptr), adjList(adj) {}
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

    // Modified function to add an edge from src to dest with weight
    void addEdge(int src, int dest, int weight) {
        Node* srcVertex = findVertex(src);
        Node* destVertex = findVertex(dest);

        if (!srcVertex || !destVertex) return;

        // Add edge from src to dest with weight
        srcVertex->adjList = new Node(dest, weight, srcVertex->adjList);

        // Add edge from dest to src with weight (if undirected)
        destVertex->adjList = new Node(src, weight, destVertex->adjList);
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
                std::cout << " " << adj->vertex << "(Weight: " << adj->weight << ")";
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

    // Add edges with weights
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    // Print the graph with edge weights
    g.printGraph();

return 0 ; 
}

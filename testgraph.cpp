#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected, add v to w’s list.
}

// Utility function for DFS traversal
void DFSUtil(int v, vector<bool>& visited, const vector<list<int>>& adj) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, visited, adj);
        }
    }
}

// DFS traversal of the vertices reachable from v
void DFS(int v, const vector<list<int>>& adj) {
    // Mark all the vertices as not visited
    vector<bool> visited(adj.size(), false);

    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited, adj);
}

// BFS traversal from a given source vertex v
void BFS(int v, const vector<list<int>>& adj) {
    // Mark all the vertices as not visited
    vector<bool> visited(adj.size(), false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        v = q.front();
        cout << v << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex v
        // If an adjacent vertex hasn't been visited, mark it visited and enqueue it
        for (int i : adj[v]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<list<int>> adj(V); // Adjacency list representation

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Perform DFS starting from vertex 0
    cout << "DFS starting from vertex 0: ";
    DFS(0, adj);
    cout << endl;

    // Perform BFS starting from vertex 0
    cout << "BFS starting from vertex 0: ";
    BFS(0, adj);
    cout << endl;

    return 0;
}

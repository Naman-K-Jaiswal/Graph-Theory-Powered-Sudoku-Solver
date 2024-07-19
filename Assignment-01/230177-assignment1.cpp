#include <iostream>
#include <vector>
using namespace std;

// Function to add edges to the clone graph
void AddEdges(int node, vector<int> adj[], vector<vector<int>>& clone, vector<int>& visited) {
    visited[node] = 1;
    for (int it : adj[node]) {
        if (!visited[it]) {
            clone[node].push_back(it);
            clone[it].push_back(node);
        }
    }
}

// Function to print the adjacency list of the clone graph
void printList(const vector<vector<int>>& clone) {
    for (size_t node = 0; node < clone.size(); node++) {
        cout << "Node " << node << " is connected to ";
        for (int it : clone[node]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

// Function to clone the graph
void cloneList(vector<int> adj[], int N) {
    vector<vector<int>> clone(N);  // Correctly initialize the clone adjacency list
    vector<int> visited(N, 0);  // Initialize visited array

    for (int node = 0; node < N; node++) {
        if (!visited[node]) {
            AddEdges(node, adj, clone, visited);
        }
    }
    printList(clone);  // Print the cloned graph
}

int main() {
    int N = 15;
    vector<int> adj[N];

    // Initialize the adjacency list
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3, 4 };
    adj[2] = { 0, 5, 6, 10 };
    adj[3] = { 1, 7, 8 };
    adj[4] = { 1, 9 };
    adj[5] = { 2, 10 };
    adj[6] = { 2, 11, 12 };
    adj[7] = { 3 };
    adj[8] = { 3 };
    adj[9] = { 4, 13, 14 };
    adj[10] = { 2, 5 };
    adj[11] = { 6 };
    adj[12] = { 6 };
    adj[13] = { 9 };
    adj[14] = { 9 };

    cloneList(adj, N);  // Function call to clone and print the graph

    return 0;
}



// #include <iostream>
// #include <vector>
// using namespace std;

// void AddEdges(int node, vector<int> adj[],
//               vector<int> clone[], vector<int>& visited)
// {
   
//     visited[node] = 1;
 
//     for (int it : adj[node]) {
//         if (!visited[it]) {
 
           
//             clone[node].push_back(it);
//             clone[it].push_back(node);
//         }
//     }
// }
// void printList(vector<int> clone[], int n)
// {
//     for (int node = 0; node < n; node++) {
//         cout << "Node " << node << " is connected to ";
//         for (int it : clone[node]) {
//             cout << it << " ";
//         }
//         cout << endl;
//     }
// }
// void cloneList(vector<int> adj[], int N)
// {
//     vector<int> clone[N];
 
//     // Visited array to check whether a particular
//     // node is visited or not
//     vector<int> visited(N, 0);
 
//     for (int node = 0; node < N; node++) {
//         if (!visited[node]) {
//             AddEdges(node, adj, clone, visited);
//         }
//     }    
//     printList(clone, N);
// }
// int main()
// {
//     // Adjacency List of a bidirectional graph
//     int N = 15;
//     vector<int> adj[N];
//     adj[0] = { 1, 2 };
//     adj[1] = { 0, 3,4 };
//     adj[2] = { 0, 5, 10 ,6}
//     adj[3] = { 1, 7, 8 };
//     adj[4] = { 1, 9 };
//     adj[5] = { 2, 10 };
//     adj[6] = { 2, 11, 12};
//     adj[7] = {  3 };
//     adj[8] = { 3 };
//     adj[9] = { 4,13,14 };
//     adj[10] = { 5, 2 };
//     adj[11] = { 6 };
//     adj[12] = { 6};
//     adj[13] = {9 };
//     adj[14] = { 9 };
 
//     // Function call
//     cloneList(adj, N);
 
//     return 0;
// }
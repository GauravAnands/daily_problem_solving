// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //visited array
        int visited[V];
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                //cout<< i <<" \n";
                bool bIsCycle = isCycleUtil(i, visited, adj, -1);
                
                // if cycle exists
                if (bIsCycle) return true;
            }
        }
        return false;
    }
    
    // util dfs function
    bool isCycleUtil(int source, int visited[], vector<int> adj[], int parent){
        visited[source] = 1;
        
        //cout<< source <<" \n";
        //traverse the neighbour
        for(auto it: adj[source]){
            //cout<< source <<" : "<<it<<" : "<<parent<<" \n";
            if(visited[it] && it != parent) return true;
            
            if(!visited[it]) 
                if(isCycleUtil(it, visited, adj, source))
                    return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // visited and curent visited array
        int visited[V], currVisited[V];
        memset(visited, 0, sizeof(visited));
        memset(currVisited, 0, sizeof(currVisited));
        
        // flag
        bool bIsCyclic;
        
        for(int i = 0; i < V; i++){
            if (!visited[i]){
                bIsCyclic = isCyclicUtil(i, visited, currVisited, adj);
                if (bIsCyclic) return true;
            }
            //cout<<"Source Node -> " <<i<<" "<<visited[i]<<" \n"; 
        }
        return false;
    }
    
    // util function
    bool isCyclicUtil(int source, int visited[], int currVisited[], vector<int> adj[]){
        visited[source]     = 1;
        currVisited[source] = 1;
        
        for(auto it: adj[source]){

		// if not visited start a dfs from this neighbour
            if(visited[it] == 0){
                bool isCyclic = isCyclicUtil(it, visited, currVisited, adj);
                
		    // once true, it will keep on returning true till the end, 
                if (isCyclic) return true;
            }
            
		// if this node is in current visited set
            else if(currVisited[it] == 1) return true;
        }
	
        // if no neighbour
        currVisited[source] = 0;
        return false;
    }
};
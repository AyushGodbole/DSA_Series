class Solution {
  public:
  
    // DFS Traversal Function
    void dfsTraversal(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs){
        // mark as visited
        vis[node] = 1;
        dfs.push_back(node);
        
        // check neighbours
        for(auto ele : adj[node]){
            // check if alreay visited
            if(!vis[ele]){
                dfsTraversal(ele,adj,vis,dfs);
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        vector<int> dfs;
        
        // recursive call with starting node 
        int start_node = 0;
        dfsTraversal(start_node,adj,vis,dfs);
        
        return dfs;
    }
};

// TC : O(N+2E)
// SC : O(N) + O(N)
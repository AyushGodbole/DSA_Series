class Solution {
  public:
  
    bool detectCycleDFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        // traverse adjacents
        for(auto ele: adj[node]){
            // if not visited
            if(!vis[ele]){
                if(detectCycleDFS(ele,adj,vis,pathVis)==true) return true;
            }
            // already visited and also find in same path
            else if(pathVis[ele]==1){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        // We Have Connected Components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycleDFS(i,adj,vis,pathVis)==true) return true;
            }
        }
        
        return false;
    }
};

// TC : O(N+E)
// SC : O(N) + O(N) + O(N)
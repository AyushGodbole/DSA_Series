class Solution {
  public:
    
    bool detectCycleDFS(pair<int,int> node, vector<int> adj[], vector<int> &vis){
        int src = node.first;
        int parent = node.second;
        
        vis[src] = 1;
        
        // traverse neighbours
        for(auto ele:adj[src]){
            // check if not visited
            if(!vis[ele]){
                if(detectCycleDFS({ele,src},adj,vis)==true) return true;
            }
            // cycle detected
            else if(parent!=ele) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        int src=0;
        
        // WE HAVE COMPONENTS SO CHECK FOR EACH
        for(int i=src; i<V; i++){
            if(!vis[i]){
                if(detectCycleDFS({i,-1},adj,vis)==true) return true;
            }
        }
        return false;
    }
};

// TC : O(N+2E)
// SC : O(N) + O(N)
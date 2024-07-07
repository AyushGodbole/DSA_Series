class Solution {
  public:
    
    bool detectCycleBFS(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            // traverse neighbours
            for(auto ele : adj[node]){
                // if not visited
                if(!vis[ele]){
                    vis[ele] = 1;
                    q.push({ele,node});
                }
                // already visited but parent does not matches
                else if(parent!=ele){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        int src=0;
        
        // WE HAVE COMPONENTS SO CHECK FOR EACH
        for(int i=src; i<V; i++){
            if(!vis[i]){
                if(detectCycleBFS(i,adj,vis)==true) return true;
            }
        }
        return false;
    }
};

// TC : O(N+2E)
// SC : O(N) + O(N)
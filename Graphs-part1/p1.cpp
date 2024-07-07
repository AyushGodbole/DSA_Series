class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            // check neigbours
            for(auto ele : adj[node]){
                // check if already visited
                if(!vis[ele]){
                    vis[ele]=1;
                    q.push(ele);
                }
            }
        }
        
        return bfs;
    }
};

// TC : O(N+2E)
// SC : O(N) + O(N)
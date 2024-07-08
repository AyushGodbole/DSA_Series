class Solution
{
    private:
    void topo_DFS(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        // traverse neighbours
        for(auto ele : adj[node]){
            // if not visited
            if(!vis[ele]){
                topo_DFS(ele,adj,vis,st);
            }
        }
        
        // beforte going , store elements into stack
        st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	   // CHECK FOR EACH NODES
	   for(int i=0; i<V; i++){
	       if(!vis[i]){
	           topo_DFS(i,adj,vis,st);
	       }
	   }
	   
	   //now stack contains result
	   vector<int> ans;
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   
	   return ans;
	}
};
// TC : O(N+E)
// SC : O(N) + O(N)
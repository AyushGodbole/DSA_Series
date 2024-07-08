class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adjacency list
        int N = numCourses;
        vector<int> adj[N];
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        // create indegree of all elements
        vector<int> indegree(N,0);
        for(int i=0; i<N; i++){
            for(auto ele:adj[i]){
                indegree[ele]++;
            }
        }

        // push elements with indegree 0 into queue
        queue<int> q;
        for(int i=0; i<N; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // traverse adjacents
            for(auto ele: adj[node]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }

        // check cycle
        // No cycle detected
        if(topo.size()==N) return true;

        return false; 
    }
};

// TC : O(N+E)
// SC : O(N) + O(N) + O(N)
class Solution {
private:
    bool checkBFS(int start, vector<vector<int>>& graph,  vector<int> &color){
        color[start] = 0;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            // traverse neighbours
            for(auto ele : graph[node]){
                // if not visited
                if(color[ele]==-1){
                    color[ele] = !color[node];
                    q.push(ele);
                }

                // already colored , then check if color are opposite
                else if(color[ele]==color[node]){
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N,-1);

        // check for every component
        for(int i=0; i<N; i++){
            if(color[i]==-1){
                if(checkBFS(i,graph,color)==false) return false; 
            }
        }

        return true;
    }
};

// TC : O(N+2E)
// SC : O(N) + O(N)
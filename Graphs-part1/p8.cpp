class Solution
{
public:
    // using BFS
    vector<int> topo_sortBFS(vector<int> adj[], int &V)
    {

        int indegree[V] = {0};
        // store all elements indegree
        for (int i = 0; i < V; i++)
        {
            for (auto ele : adj[i])
            {
                indegree[ele]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        // push elements with indegree 0
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // traverse adjacents
            for (auto ele : adj[node])
            {
                indegree[ele]--;

                if (indegree[ele] == 0)
                {
                    q.push(ele);
                }
            }
        }

        return ans;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> res = topo_sortBFS(adj, V);

        if (res.size() == V)
            return false;
        return true;
    }
};

// TC : O(N+E)
// SC : O(N) + O(N) + O(N)
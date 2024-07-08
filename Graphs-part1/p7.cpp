class Solution
{
private:
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

public:
	// Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> res = topo_sortBFS(adj,V);

		return res;
	}
};
// TC : O(N+E)
// SC : O(N) + O(N)
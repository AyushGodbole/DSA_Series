class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // WE WILL USE VERTICAL ORDER TRAVERSAL FOR THIS
        map<int,Node*> Mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            Node* frontnode = q.front().first;
            int line = q.front().second;
            q.pop();
            
            // mark line for its node , IF NOT MARKED YET
            if(!Mp[line]){
                Mp[line] = frontnode;
            }
            
            // check left child & right child
            if(frontnode->left!=NULL){
                q.push({frontnode->left,line-1});
            }
            if(frontnode->right!=NULL){
                q.push({frontnode->right,line+1});
            }
        }
        
        vector<int> ans;
        for(auto it:Mp){
            ans.push_back(it.second->data);
        }
        
        return ans;
    }

};


// TC : O(N)
// SC : O(N)
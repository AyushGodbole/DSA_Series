class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // WE WILL USE LOGIC OF VERTICAL ORDER TRAVERSAL
        vector<int> ans;
        // int line=0;
        map<int,Node*> Mp; //(line,node)
        queue<pair<Node*,int>> q; //(node,line)
        
        q.push({root,0});
        while(!q.empty()){
            Node* frontnode = q.front().first;
            int line = q.front().second;
            q.pop();
            
            // mark node corresponding to its line in map
            Mp[line] = frontnode;
            
            // check if left and right childs are there
            if(frontnode->left!=NULL){
                q.push({frontnode->left,line-1});
            }
            if(frontnode->right!=NULL){
                q.push({frontnode->right,line+1});
            }
        }
        
        // get all nodes from map
        for(auto it : Mp){
            ans.push_back(it.second->data);
        }
        
        return ans;
    }
};

// TC : O(N)
// SC : O(N) + O(N)
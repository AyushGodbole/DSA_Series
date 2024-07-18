/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

void traverse(Node* root, vector<int> path, vector<vector<int>> &ans){
    // base case
    if(root==NULL) return;
    
    //check if leaf node
    if(root->left==NULL && root->right==NULL){
        path.push_back(root->data);
        ans.push_back(path);
    }
    
    path.push_back(root->data);
    
    traverse(root->left,path,ans);
    traverse(root->right,path,ans);
}

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // APPROACH
        vector<vector<int>> ans;
        vector<int> path;
        
        traverse(root,path,ans);
        return ans;
    }
};

// TC : O(N)
// SC : O(N)
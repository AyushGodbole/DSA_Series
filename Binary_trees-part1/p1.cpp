/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preOrder(TreeNode* root, vector<int> &ans){
        // base case
        if(root==NULL) return;

        // root
        ans.push_back(root->val);

        // go left
        preOrder(root->left,ans);
    
        // go right
        preOrder(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // APPROACH - [Root,left,Right]
        
        vector<int> ans;
        preOrder(root,ans);

        return ans;
    }
};

// TC : O(N) , N-> no. of nodes
// SC : O(N) , in case of skew trees
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
    void inOrder(TreeNode* root, vector<int> &ans){
        // base case
        if(root==NULL) return;

        // go left
        inOrder(root->left,ans);

        // root
        ans.push_back(root->val);

        // go right
        inOrder(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // APPROACH - [Left,Root,Right]
        vector<int> ans;
        inOrder(root,ans);
        return ans;
    }
};

// TC : O(N)
// SC : O(N)
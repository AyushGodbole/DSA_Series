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
    int traverse(TreeNode* root){
        // base case
        if(root==NULL) return 0;

        int left = traverse(root->left);
        int right = traverse(root->right);

        return 1+max(left,right);
    }
public:
    int maxDepth(TreeNode* root) {
        // APPROACH 2 - using recursion

        int depth = traverse(root);
        return depth;
    }
};

// TC : O(N)
// SC : O(Height of Tree)
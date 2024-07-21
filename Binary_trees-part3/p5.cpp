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
    void flattenTree(TreeNode* &node, TreeNode* &prev){
        if(node==NULL) return;

        // go right
        flattenTree(node->right,prev);
        // go left
        flattenTree(node->left,prev);

        node->right = prev;
        node->left = NULL;
        prev = node;
    }
public:
    void flatten(TreeNode* root) {
        // APPROACH 1 - recursive
        // 1. solve right part , then left part , then root
        TreeNode* prev = NULL;
        flattenTree(root,prev);
    }
};

// TC : O(N)
// SC : O(N)
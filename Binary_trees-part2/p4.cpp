/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // OPTIMAL

        if(root==NULL || root==p || root==q) return root;

        // left call
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // right call
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // cases
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else{
            // means both are non-null , hence the node where we are standing is the LCA
            return root;
        }
    }
};

// TC : O(N)
// SC : O(N)
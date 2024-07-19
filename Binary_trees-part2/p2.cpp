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
    int traverse(TreeNode* root, int &maxi){
        if(root==NULL) return 0;

        int left = traverse(root->left,maxi);
        int right = traverse(root->right,maxi);

        // update maxi
        maxi = max(maxi,left+right);

        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // APPROACH - same used in finding height of tree
        int maxi=0;
        int height = traverse(root,maxi);
        return maxi;
    }
};

// TC : O(N)
// SC : O(N)
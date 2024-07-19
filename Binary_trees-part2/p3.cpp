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
    int findHeight(TreeNode* root){
        if(root==NULL) return 0;

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        // if node found unbalanced , return from there
        if(left==-1 || right==-1) return -1;

        int diff = abs(left-right);
        if(diff>1) return -1;
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        // APPROACH - using concept of height of a tree
        // FOR BALANCED TREE - abs(lh-rh)<=1
        // lh - left height
        // rh - right height
        int height = findHeight(root);

        if(height==-1) return false;
        return true;
    }
};

// TC : O(N)
// SC : O(N)
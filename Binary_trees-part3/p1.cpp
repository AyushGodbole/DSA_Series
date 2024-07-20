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
    int findMaxSum(TreeNode* root, int &maxi){
        // base case
        if(root==NULL) return 0;

        // left & right child calls
        int left = findMaxSum(root->left,maxi);
        int right = findMaxSum(root->right,maxi);

        // no need to carry -ve val
        if(left<0) left=0;
        if(right<0) right=0;

        maxi = max(maxi, root->val+left+right);

        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        // APPROACH - same as max height in tree

        int maxi = INT_MIN;
        int height = findMaxSum(root,maxi);
        return maxi;
    }
};

// TC : O(N)
// SC : O(N)
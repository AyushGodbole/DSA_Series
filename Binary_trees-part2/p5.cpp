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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Approach - using two pointers
        if(p==NULL || q==NULL){
            if(p==q) return true;
            return false;
        }

        if(p->val!=q->val) return false;
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        if(left==false || right==false) return false;

        return true;
    }
};

// TC : O(N)
// SC : O(N)
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
    bool check(TreeNode* leftPtr, TreeNode* rightPtr){
        if(leftPtr==NULL || rightPtr==NULL){
            if(leftPtr==rightPtr) return true;
            return false;
        }

        if(leftPtr->val != rightPtr->val) return false;

        // check for leftPtr->left and rightPtr->right
        bool c1 = check(leftPtr->left,rightPtr->right);

        // check for leftPtr->right and rightPtr->left
        bool c2 = check(leftPtr->right,rightPtr->left);

        if(c1==true && c2==true) return true;

        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        // OPTIMAL - one go left , one go right
        if(root==NULL) return true;

        bool ans = check(root->left,root->right);
        return ans;
    }
};

// TC : O(N)
// SC : O(N)
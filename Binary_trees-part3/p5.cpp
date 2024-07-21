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
    void flatten(TreeNode* root) {
        // APPROACH 3 - optimal , updation of morris traversal

        TreeNode* curr = root;
        while(curr!=NULL){
            // find righmost leaf node in left sub tree
            if(curr->left!=NULL){
                TreeNode* prev = curr->left;
                while(prev->right!=NULL){
                    prev = prev->right;
                }

                // update links
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// TC : O(N)
// SC : O(1)
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
void morrisTraversalInorder(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root;
    while(curr!=NULL){
        // case 1: no left node
        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // case 2: has left node
        // before going left make connection of rightmost node to parent(root) node.
        else{
            TreeNode* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr) prev = prev->right;

            // if no connection, make the connection
            if(prev->right==NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                // already a connection , then break that connection
                prev->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // MORRIS TRAVERSAL - INORDER
        vector<int> ans;
        morrisTraversalInorder(root,ans);
        return ans;
    }
};

// FOR MORRIS TRAVERSAL
// TC : O(N)
// SC : O(1)
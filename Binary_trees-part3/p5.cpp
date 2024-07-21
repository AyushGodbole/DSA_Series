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
        // approch 2 - using stack , iterative

        if(root==NULL || (root->left==NULL && root->right==NULL)) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            // check if right child exists
            if(curr->right!=NULL) st.push(curr->right);
            // check if left child exists
            if(curr->left!=NULL) st.push(curr->left);

            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = NULL;
        }
    }
};

// TC : O(N)
// SC : O(N)
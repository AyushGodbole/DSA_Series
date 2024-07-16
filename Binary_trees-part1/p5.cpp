#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void morrisTraversalPreorder(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root;
    while(curr!=NULL){
        // case 1: no left node
        if(curr->left==NULL){
            ans.push_back(curr->data);
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
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else{
                // already a connection , then break that connection
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    morrisTraversalPreorder(root,ans);
    return ans;
}

// FOR MORRIS TRAVERSAL
// TC : O(N)
// SC : O(1)
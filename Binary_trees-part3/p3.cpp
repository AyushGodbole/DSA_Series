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
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &Mp){
        if(postStart>postEnd || inStart>inEnd) return NULL;

        // create root node
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // find index of root in inorder map
        int root_idx = Mp[root->val];
        int numPrevToRoot = root_idx - inStart;

        root->left = build(postorder,postStart,(postStart+numPrevToRoot-1), inorder,inStart,(root_idx-1),Mp);
        root->right = build(postorder,(postStart+numPrevToRoot),postEnd-1, inorder,root_idx+1,inEnd,Mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // APPROACH

        // 1. map elements of inorder in map
        map<int,int> Mp;
        for(int i=0; i<inorder.size(); i++){
            Mp[inorder[i]] = i;
        }

        int postStart = 0;
        int postEnd = postorder.size()-1;

        int inStart = 0;
        int inEnd = inorder.size()-1;

        TreeNode* root = build(postorder,postStart,postEnd, inorder,inStart,inEnd,Mp);
        return root;
    }
};

// TC : O(N)
// SC : O(N) + O(N)
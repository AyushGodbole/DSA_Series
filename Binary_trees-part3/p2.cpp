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
    TreeNode* build(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int,int> &Mp){
        // preStart passed preEnd or inStart passed inEnd
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        // find where the root is present in Map
        int index = Mp[root->val];
        int numsInLeft = index - inStart;

        root->left = build(preorder,preStart+1,(preStart+numsInLeft), inorder,inStart,index-1,Mp);
        root->right = build(preorder,(preStart+numsInLeft+1),preEnd, inorder,(index+1),inEnd,Mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 1. Map the inorder so that we can get indexes
        map<int,int> Mp;
        for(int i=0; i<inorder.size(); i++){
            Mp[inorder[i]] = i;
        }

        int preStart=0;
        int preEnd = preorder.size() - 1;
        int inStart=0;
        int inEnd = inorder.size() - 1;

        TreeNode* root = build(preorder,preStart,preEnd,inorder,inStart,inEnd,Mp);

        return root;
    }
};

// TC : O(N)
// SC : O(N) + O(N)
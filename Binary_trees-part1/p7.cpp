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
    void traverse(TreeNode* root, vector<int> &ans, int level){
        if(root==NULL) return;

        if(ans.size()==level) ans.push_back(root->val);

        // go right
        traverse(root->right,ans,level+1);

        // go left
        traverse(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // APPROACH
        int level=0;
        vector<int> ans;
        traverse(root,ans,level);
        return ans;
    }
};

// TC : O(N)
// SC : O(N)
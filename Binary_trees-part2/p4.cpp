/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* node){
        if(root==NULL) return false;

        // include in path
        path.push_back(root);

        // check if element found
        if(root->val==node->val) return true;

        // left and right calls
        bool left = findPath(root->left,path,node);
        bool right = findPath(root->right,path,node);

        if(left==true || right==true) return true;

        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BRUTE FORCE
        // find path from root to node 1, node 2 and compare them

        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        bool f1 = findPath(root,path1,p);
        bool f2 = findPath(root,path2,q);

        int i=0;
        int j=0;
        TreeNode* prev = NULL;

        while(i<path1.size() && j<path2.size()){
            if(path1[i]==path2[j]){
                prev = path1[i];
            }
            else{
                break;
            }
            i++;
            j++;
        }

        return prev;
    }
};

// TC : O(N) + O(N)
// SC : O(N) + O(N) + O(N) + O(N)
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
    void traverseLeft(TreeNode* root, vector<TreeNode*> &left){
        if(root==NULL){
            left.push_back(NULL);
            return;
        }

        left.push_back(root);

        // left
        traverseLeft(root->left,left);

        // right
        traverseLeft(root->right,left);
    }

    void traverseRight(TreeNode* root, vector<TreeNode*> &right){
        if(root==NULL){
            right.push_back(NULL);
            return;
        }

        right.push_back(root);

        // right
        traverseRight(root->right,right);
        
        // left
        traverseRight(root->left,right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // BRUTE FORCE
        vector<TreeNode*> left;
        vector<TreeNode*> right;

        traverseLeft(root,left);
        traverseRight(root,right);

        int i=0;
        int j=0;
        while(i<left.size() && j<right.size()){
            // Both ae NULLS
            if(left[i]==NULL && right[j]==NULL){
                i++;
                j++;
            }
            // one is Null and other is not
            else if(left[i]==NULL || right[j]==NULL){
                return false;
            }
            // value does not matches
            else if(left[i]->val != right[j]->val){
                return false;
            }
            else{
                i++;
                j++;
            }
        }

        return true;
    }
};

// TC : O(N) + O(N)
// SC : O(N) + O(N) + O(N)
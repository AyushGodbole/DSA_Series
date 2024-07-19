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
    int maxDepth(TreeNode* root) {
        // APPROACH 1 - using level order traversal

        if(root==NULL) return 0;
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            // traverse each nodes of a level
            for(int i=0; i<size; i++){
                TreeNode* frontnode = q.front();
                q.pop();

                // check childs
                if(frontnode->left) q.push(frontnode->left);
                if(frontnode->right) q.push(frontnode->right);
            }
            depth++;
        }

        return depth;
    }
};

// TC : O(N)
// SC : O(N)
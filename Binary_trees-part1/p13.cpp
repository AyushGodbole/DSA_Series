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
    int widthOfBinaryTree(TreeNode* root) {
        // APPROACH - using indexing to each node and level order traversal

        if(root==NULL) return 0;

        long width=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            long min_idx = q.front().second;
            int size = q.size();
            long first,last;

            // take all nodes at each level
            for(int i=0; i<size; i++){
                long long curr_idx = q.front().second - min_idx;
                TreeNode* frontnode = q.front().first;
                q.pop();

                // find first and last node
                if(i==0) first = curr_idx;
                if(i==size-1) last = curr_idx;

                // check left and right childs
                if(frontnode->left!=NULL){
                    q.push({frontnode->left , 2*curr_idx+1});
                }
                if(frontnode->right!=NULL){
                    q.push({frontnode->right , 2*curr_idx+2});
                }
            }

            width = max(width, (last-first+1));
        }

        return width;
    }
};

// TC : O(N)
// SC : O(N)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // APPRAOCH - same as level order traversal , just need to change the direction

        vector<vector<int>> ans;
        if(root==NULL) return ans;

        bool direction = 0;
        // 0 means left to right , 1 means right to left
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            // change the direction
            for(int i=0;i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                temp.push_back(frontNode->val);

                // check left and right child
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            // if direction is 0 , means insert left to right
            if(!direction){
                ans.push_back(temp);
            }
            else{
                // if direction is 1 , means insert right to left
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            // change direction
            direction = !direction;
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(N)
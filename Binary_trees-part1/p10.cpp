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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> Mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        // Initially vertical=0, level=0;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            TreeNode* frontNode = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            
            // Mark nodes
            Mp[vertical][level].push_back(frontNode->val);
            
            // Check children
            if (frontNode->left != nullptr) {
                q.push({frontNode->left, {vertical - 1, level + 1}});
            }
            if (frontNode->right != nullptr) {
                q.push({frontNode->right, {vertical + 1, level + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto it : Mp) {
            vector<int> temp;
            for (auto levelMap : it.second) {
                sort(levelMap.second.begin(), levelMap.second.end());
                for (auto val : levelMap.second) {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// TC : O(N log N) due to sorting within each level
// SC : O(N)
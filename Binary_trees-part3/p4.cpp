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
    void traverseLeft(TreeNode* root, vector<TreeNode*> &left) {
        if (root == nullptr) {
            left.push_back(nullptr);
            return;
        }

        left.push_back(root);

        // left
        traverseLeft(root->left, left);

        // right
        traverseLeft(root->right, left);
    }

    void traverseRight(TreeNode* root, vector<TreeNode*> &right) {
        if (root == nullptr) {
            right.push_back(nullptr);
            return;
        }

        right.push_back(root);

        // right
        traverseRight(root->right, right);
        
        // left
        traverseRight(root->left, right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // BRUTE FORCE
        vector<TreeNode*> left;
        vector<TreeNode*> right;

        traverseLeft(root->left, left);
        traverseRight(root->right, right);

        for (auto ele : left) {
            if (ele != nullptr) {
                cout << ele->val << " ";
            } else {
                cout << "null ";
            }
        }
        cout << endl;

        for (auto ele : right) {
            if (ele != nullptr) {
                cout << ele->val << " ";
            } else {
                cout << "null ";
            }
        }
        cout << endl;

        int i = 0;
        int j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] == nullptr && right[j] == nullptr) {
                // Both are null, continue
                i++;
                j++;
            } else if (left[i] == nullptr || right[j] == nullptr) {
                // One is null and the other is not, not symmetric
                return false;
            } else if (left[i]->val != right[j]->val) {
                // Values are different
                return false;
            } else {
                // Values are the same, continue
                i++;
                j++;
            }
        }

        return true;
    }
};

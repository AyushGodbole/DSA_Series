// function Template for C++

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // APPROACH
        if(node==NULL) return;
        
        // go to left
        mirror(node->left);
        // go to right
        mirror(node->right);
        
        // swap their left and right
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

// TC : O(N)
// SC : O(N)
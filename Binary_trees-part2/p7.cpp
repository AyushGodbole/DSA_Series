// check if node is a leaf or not
bool isLeaf(Node* node){
    if(node == NULL) return false; // Added null check
    return (node->left == NULL && node->right == NULL);
}

// insert left part
void insertLeft(Node* node, vector<int> &ans){
    Node* temp = node;
    
    while(temp != NULL){
        // if leaf node don't insert
        if(!isLeaf(temp)) ans.push_back(temp->data);
    
        // check if left exists
        if(temp->left != NULL) temp = temp->left;
        else temp = temp->right;
    }
}

// insert leaf nodes using preorder traversal
void insertLeafNodes(Node* root, vector<int> &ans){
    if(root == NULL) return;
    
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return; // Added return to prevent further traversal
    }
    
    // left call
    insertLeafNodes(root->left, ans);
    
    // right call
    insertLeafNodes(root->right, ans);
}

// insert right part in reverse
void insertRight(Node* node, vector<int> &ans){
    Node* temp = node;
    
    // push in stack
    stack<int> st;
    while(temp != NULL){
        // check if not leaf
        if(!isLeaf(temp)) st.push(temp->data);
        
        // check if right exists
        if(temp->right != NULL) temp = temp->right;
        else temp = temp->left;
    }
    
    // now insert elements from stack to ans
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        // APPROACH :
        // 1. root is always in boundary
        // 2. insert left part , excluding leaf nodes and go to left if exists , else go right
        // 3. insert leaf nodes using preorder traversal[root,left,right]
        // 4. insert right part in reverse order, excluding leaf nodes and go to right if exists, else go left
        // 5. copy from right to ans
        
        vector<int> ans;
        if(root == NULL) return ans;
        
        if(!isLeaf(root)) ans.push_back(root->data); // Root node is not a leaf
        
        insertLeft(root->left, ans);
        insertLeafNodes(root, ans);
        insertRight(root->right, ans);
        
        return ans;
    }
};
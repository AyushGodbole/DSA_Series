bool traverse(TreeNode<int> *root, vector<int> &path, int x){
	if(root==NULL) return false;

	// include element in path
	path.push_back(root->data);

	// check if element found
	if(root->data == x) return true;

	// left call
	bool left = traverse(root->left, path, x);

	// right call
	bool right = traverse(root->right, path, x);

	if(left || right) return true;

	// remove from path
	path.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	// APPROACH
    vector<int> path;
	bool res = traverse(root,path,x);
	return path;
}

// TC : O(N)
// SC : O(N)
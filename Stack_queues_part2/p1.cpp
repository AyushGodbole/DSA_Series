vector<int> Solution::prevSmaller(vector<int> &A) {
    // similar to next greater element
    // APROACH
    
    stack<int> st;
    vector<int> ans;
    int n = A.size();
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        
        if(st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top());
        }
        
        st.push(A[i]);
    }
    
    return ans;   
}

// TC : O(N)
// SC : O(N)

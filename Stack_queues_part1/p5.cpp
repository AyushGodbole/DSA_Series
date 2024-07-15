class Solution {
public:
    bool isValid(string s) {
        int n=s.size();

        stack<int> st;
        for(int i=0; i<n; i++){
            // if opening pair , insert it
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                // we got closing pair, but stack is empty
                if(st.empty()) return false;
                else{
                    if(s[i]==')' && st.top()=='(') st.pop();
                    else if(s[i]==']' && st.top()=='[') st.pop();
                    else if(s[i]=='}' && st.top()=='{') st.pop();
                    // not matches , return false
                    else return false;
                }
            }
        }

        // check if stack becomes empty
        if(st.empty()) return true;
        return false;
    }
};

// TC : O(N)
// SC : O(N)
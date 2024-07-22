class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // APPROACH 1 - using stack

        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top()){
                    st.pop();
                }

                if(!st.empty() && abs(asteroids[i])==st.top()){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top()<0){
                        st.push(asteroids[i]);
                    }
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// TC : O(N)
// SC : O(N)
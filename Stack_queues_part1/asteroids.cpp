// ASTEROIDS PROBLEM

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // APPROACH - Let's use stack
        stack<int> st;

        int i=0;
        int n=asteroids.size();

        for(int i=0; i<n; i++)
        {
            if(st.empty()) st.push(asteroids[i]);
            else if(asteroids[i]>0) st.push(asteroids[i]);
            else if(asteroids[i]<0){
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top()) st.pop();

                if(!st.empty() && st.top()>0){
                    if(st.top()==abs(asteroids[i])) st.pop();
                }
                else st.push(asteroids[i]);
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
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // APPROACH 2 - using list/vector

        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0) ans.push_back(asteroids[i]);
            else{
                while(!ans.empty() && ans.back()>0 && abs(asteroids[i])>ans.back()){
                    ans.pop_back();
                }

                if(!ans.empty() && abs(asteroids[i])==ans.back()){
                    ans.pop_back();
                }
                else{
                    if(ans.empty() || ans.back()<0){
                        ans.push_back(asteroids[i]);
                    }
                }
            }
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(1)
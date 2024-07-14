class Solution {
public:
    int romanToInt(string s) {
        // BRUTE FORCE

        // map values with each string
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            // if not last element
            if(i<n-1){
                // check whether to add
                if(mp[s[i+1]] <= mp[s[i]]) ans+=mp[s[i]];
                
                // else substract it
                else ans-=mp[s[i]];
            }
            else{
                // add last value direct
                ans+=mp[s[i]];
            }
        }

        return ans;
    }
};

// TC : O(N)
// SC : O(N)
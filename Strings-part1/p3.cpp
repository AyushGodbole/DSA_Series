class Solution {
private:
    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // added default case for safety
        }
    }
public:
    int romanToInt(string s) {
        // OPTIMAL - using switch case

        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val1 = getValue(s[i]);
            int val2 = (i < n - 1) ? getValue(s[i + 1]) : 0; // safe access

            // if not last character.
            if (i < n - 1) {
                // check if to add
                if (val1 < val2) ans -= val1;
                else ans += val1;
            } else {
                ans += val1;
            }
        }

        return ans;
    }
};

// TC: O(N)
// SC: O(1)
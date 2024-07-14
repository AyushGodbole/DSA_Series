class Solution {
public:
    string reverseWords(string s) {
        // ANUJ BHAIYA

        int i=s.size()-1;
        string ans="";

        while(i>=0){
            
            if(i<0) break;
            // ignore spaces
            while(i>=0 && s[i]==' ') i--;

            // get first word
            int j=i;
            cout<<j<<endl;
            while(i>=0 && s[i]!=' ') i--;
            cout<<i<<endl;
            
            if(j>=0){
                if(!ans.empty()){
                    ans+=' ';
                }
                ans+=s.substr(i+1,j-i);
            }
        }

        return ans;
    }
};

// TC : O(N)
// Sc : O(1)
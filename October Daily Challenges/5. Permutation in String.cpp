class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> store(26,0);
        for(char ch:s1) {
            store[ch-'a']++;
        }
        
        int i=0,j=0;
        int n=s2.length();
        vector<int> st(26,0);
        while(i<n) {
            st[s2[i]-'a']++;
            
            if((i-j+1)>s1.length()) {
                st[s2[j]-'a']--;
                j++;
            } 
            if(store==st) {
                return true;
            }
            i++;
        }
        return false;
    }
};
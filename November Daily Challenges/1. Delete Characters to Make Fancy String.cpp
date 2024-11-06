// S.C. - O(N)
class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char currChar = s[0];

        for(int i=0;i<s.length();i++) {
            if(currChar == s[i]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if(cnt < 3) {
                ans += s[i];
            }

            currChar = s[i];
        }

        return ans;
    }
};

// S.C. - O(1)
class Solution {
public:
    string makeFancyString(string s) {
        // O(1) Space

        int cnt =0, j=0;
        char curr = s[0];

        for(int i=0;i<s.length();i++) {
            if(s[i]==curr) {
                cnt++;
            } else {
                cnt = 1;
                curr=s[i];
            }

            if(cnt < 3) {
                s[j]=curr;
                j++;
            }
        }

        s.resize(j);

        return s;
    }
};

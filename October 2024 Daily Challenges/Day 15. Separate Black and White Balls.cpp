class Solution {
public:
    long long minimumSteps(string s) {
        int len = s.length();

        // Counter method

        long long steps = 0, oneCnt = 0;

        for(int i=0;i<len;i++) {
            if(s[i]=='1') {
                oneCnt++;
            } else {
                steps += oneCnt;
            }
        }

        return steps;
        
    }
};


class Solution {
public:
    long long minimumSteps(string s) {
        int len = s.length();

        // 2 pointer
        long long steps = 0;
        int j = 0;

        for(int i=0;i<len;i++) {
            // whenver encounter a 0
            if(s[i] == '0') {
                steps += (i-j);
                swap(s[i], s[j]);
                j++;
            }
        }

        return steps;
    }
};


class Solution {
public:
    long long minimumSteps(string s) {
        int j=0;
        long long cnt = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0') {
                cnt += (i-j);
                swap(s[j++], s[i]);
            }
        }
        return cnt;
        
    }
};



class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0, ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans += cnt;
            } else {
                cnt++;
            }
        }
        return ans;
        
    }
};
// 2-Pointer Method
// T.C. - O(N)
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

// Counter Method
// T.C. - O(N)
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

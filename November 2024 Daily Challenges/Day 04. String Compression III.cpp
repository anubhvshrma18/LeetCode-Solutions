// T.C. - O(N)
// S.C. - O(N)

// Two Pointer
class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int i=0,j=0;
        string ans = "";
        while(i<n) {
            int cnt = 0;
            // count the character until it occured 9 times
            while(j<n && word[i]==word[j]&& cnt < 9) {
                cnt++;
                j++;
            }
            ans += to_string(cnt) + word[i];
            i=j;
        }

        return ans;
    }
};


// One Pointer
class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int i=0;
        string ans = "";
        while(i<n) {
            char currChar = word[i];
            int cnt = 0;
            // count the character until it occured 9 times
            while(currChar == word[i] && cnt < 9) {
                cnt++;
                i++;
            }
            ans += to_string(cnt) + currChar;
        }

        return ans;
    }
};

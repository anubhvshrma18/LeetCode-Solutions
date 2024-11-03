class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();

        if(n!=m) return false;

        string a = s+s;

        if(a.find(goal) != string::npos) return true;

        return false;
    }
};
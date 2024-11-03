class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();

        for(int i=0;i<n;i++) {
            s = s.substr(1, n-1) + s.substr(0,1);

            if(s == goal) return true;
        }

        return false;
    }
};


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();

        for(int i=0;i<n;i++) {
            rotate(s.begin(), s.begin()+1, s.end());

            if(s==goal) return true;
        }

        return false;
    }
};


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

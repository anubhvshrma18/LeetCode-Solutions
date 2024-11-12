class Solution {
public:
    long long minEnd(int n, int x) {
        long long y = x;
        for(int i=1;i<n;i++) {
            y=(y+1) | x;
        }
        return y;
    }
};
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) {
        // 1 2  3 10 4 2 3 5
        // 10 4
        int N = A.size(), left = 0, right = N - 1;
        while (left + 1 < N && A[left] <= A[left + 1]) ++left;
        if (left == A.size() - 1) return 0;
        while (right > left && A[right - 1] <= A[right]) --right;
        int ans = min(N - left - 1, right), i = 0, j = right;
        while (i <= left && j < N) {
            if (A[j] >= A[i]) {
                ans = min(ans, j - i - 1);
                ++i;
            } else ++j;
        }
        return ans;
    }
};
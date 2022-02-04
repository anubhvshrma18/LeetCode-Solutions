class Solution
{
public:
    int mod = 1000000007;
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        int hd = horizontalCuts[0];
        int vd = verticalCuts[0];
        for (int i = 1; i < n; i++)
        {
            hd = max(hd % mod, abs(horizontalCuts[i] - horizontalCuts[i - 1]) % mod);
        }
        for (int i = 1; i < m; i++)
        {
            vd = max(vd % mod, abs(verticalCuts[i] - verticalCuts[i - 1]) % mod);
        }

        vd = max(vd, w - verticalCuts[m - 1]) % mod;
        hd = max(hd, h - horizontalCuts[n - 1]) % mod;

        long long ans = (long)hd * (long)vd;
        ans = ans % mod;
        return (int)ans;
    }
};
class Solution
{
public:
    bool tab(string s1, string s2, string s3, int n, int m)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[j - 1]);
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i - 1]);
                }
                else
                {
                    if (!dp[i][j - 1] && !dp[i - 1][j])
                    {
                        dp[i][j] = false;
                    }
                    else if (!dp[i - 1][j])
                    {
                        dp[i][j] = (s2[j - 1] == s3[i + j - 1]);
                    }
                    else if (!dp[i][j - 1])
                    {
                        dp[i][j] = (s1[i - 1] == s3[i + j - 1]);
                    }
                    else
                    {
                        dp[i][j] = (s1[i - 1] == s3[i + j - 1]) && (s2[j - 1] == s3[i + j - 1]) && (s1[i - 1] == s2[j - 1]);
                    }
                }
            }
        }
        return dp[n][m];
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3 == s1 + s2)
        {
            return true;
        }
        int n = s1.length();
        int m = s2.length();
        int s = s3.length();
        if (n + m != s)
        {
            return false;
        }
        return tab(s1, s2, s3, n, m);
    }
};
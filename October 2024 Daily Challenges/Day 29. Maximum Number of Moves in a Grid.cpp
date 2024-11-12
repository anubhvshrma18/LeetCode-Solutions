	class Solution {
public:
    int solve(vector<vector<int>>& grid, int cr, int cc, int cval, int maxRow, int maxCol, vector<vector<int>>& dp) {

        if(dp[cr][cc]!=-1) {
            return dp[cr][cc];
        }

        int upper = 0, lower =0, middle =0;
        
        // check for upper value
        if(cr-1 >=0 && cc+1 < maxCol && cval < grid[cr-1][cc+1]) {
            upper = 1+solve(grid, cr-1, cc+1, grid[cr-1][cc+1], maxRow, maxCol,dp);
        }

        // check for lower value
        if(cr+1 < maxRow && cc+1 < maxCol && cval < grid[cr+1][cc+1]) {
            lower = 1 + solve(grid, cr+1, cc+1, grid[cr+1][cc+1], maxRow, maxCol,dp);
        }

        if(cc+1 < maxCol && cval < grid[cr][cc+1]) {
            middle = 1 + solve(grid, cr, cc+1, grid[cr][cc+1], maxRow, maxCol,dp);
        }

        return dp[cr][cc]=max(upper, max(lower, middle));

    }


    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for(int i=0;i<row;i++) {
            int cval = grid[i][0];
            ans = max(ans, solve(grid, i, 0 , cval, row, col, dp));
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        
        if(i >= matrix.size() || j>=matrix[0].size()) return 0;
        if(matrix[i][j]==0) return 0;
        
        // if it is already computed
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(i, j+1, matrix, dp);
        int bottom = solve(i+1, j, matrix, dp);
        int diagonal = solve(i+1, j+1, matrix, dp);
        
        return dp[i][j]=min(right, min(diagonal, bottom))+1;
        
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans += solve(i,j, matrix, dp);

            }
        }
        return ans;
        
    }
};



class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size() , m=mat[0].size(); 
        vector<vector<int>> dp(n,vector<int>(m,0));
        int mx = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j] == 0){
                    dp[i][j]=0;
                }
                else if(i==n-1){
                    dp[i][j]=1;
                }
                else if(j == m-1){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min(dp[i+1][j] , min( dp[i][j+1] , dp[i+1][j+1] ) ) + 1 ;
                }
                
                mx+=dp[i][j];
            }
        }
        
        
        
        
        return mx;
    }
};
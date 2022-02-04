class Solution {
        
    int minCostII(int[][] cost) {
        // write your code here
        int n = cost.length;
        if(n==0){
            return 0;
        }
        int k = cost[0].length;
        
        int[][]dp = new int[n][k];
        
        int inf = Integer.MAX_VALUE;
        int omin = inf;
        int osmin = inf;
        
        for(int i=0; i < n;i++) {
            int csmin = inf;
            int cmin = inf;
            for(int j=0;j < k;j++) {
                
                if(i == 0) {
                    dp[i][j] = cost[i][j];
                }
                else  {
                    if(dp[i-1][j] == omin) {
                        dp[i][j] = cost[i][j] + osmin;
                    }
                    else {
                        dp[i][j] = cost[i][j] + omin;
                    }
                }
                
                //maintain cmin & csmin
                if(dp[i][j] < cmin) {
                    csmin = cmin;
                    cmin = dp[i][j];
                }
                else if(dp[i][j] < csmin) {
                    csmin = dp[i][j];
                }
                
            }
            
            omin = cmin;
            osmin = csmin;
        }
        
        return omin;
    }
}
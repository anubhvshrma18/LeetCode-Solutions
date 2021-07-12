class Solution {
public:
    int mxg=0;
    void dfs(vector<vector<int>> &b,int r,int c,int cg){
        if(r<0 || c<0 || r==b.size() || c==b[0].size()||b[r][c]==0){
            return;
        }
        int val=b[r][c];
        b[r][c]=0;
        cg+=val;
        mxg=max(mxg,cg);
        dfs(b,r-1,c,cg);
        dfs(b,r,c+1,cg);
        dfs(b,r+1,c,cg);
        dfs(b,r,c-1,cg);
        b[r][c]=val;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    dfs(grid,i,j,0);
                }
            }
        }
        return mxg;
    }
};
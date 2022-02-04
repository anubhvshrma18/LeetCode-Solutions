class Solution {
public:
    int area=0;
    void dfs(vector<vector<int>> &grid,int sr,int sc,int r,int c,vector<vector<bool>> &vis,int* ans){
        if(sr<0 || sc<0 || sr==r || sc==c || vis[sr][sc]==true){
            return;
        }
        if(grid[sr][sc]==1){
            vis[sr][sc]=true;
            (*ans)++;
            dfs(grid,sr-1,sc,r,c,vis,ans);
            dfs(grid,sr,sc+1,r,c,vis,ans);
            dfs(grid,sr+1,sc,r,c,vis,ans);
            dfs(grid,sr,sc-1,r,c,vis,ans);
        }  
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int ans=0;
                    dfs(grid,i,j,r,c,vis,&ans);
                    area=max(area,ans);
                }
            }
        }
        return area;
    }
};
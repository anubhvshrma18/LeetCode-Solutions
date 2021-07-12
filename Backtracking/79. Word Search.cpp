class Solution {
public:
    bool check=false;
    void ws(vector<vector<char>> &b,string w,vector<vector<bool>> &vis,int r,int c,int idx){
        if(idx==w.length()){
            check=true;
            return;
        }
        if(r<0 || c<0 || r==b.size() || c==b[0].size() || vis[r][c] == true){
            return;
        }
        
        vis[r][c]=true;
        if(w[idx]==b[r][c]){
            
            ws(b,w,vis,r,c-1,idx+1);
            ws(b,w,vis,r,c+1,idx+1);
            ws(b,w,vis,r+1,c,idx+1);
            ws(b,w,vis,r-1,c,idx+1);
             
        }
        vis[r][c]=false;
       
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size()));
        // ws(board,word,vis,0,0,0);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                ws(board,word,vis,i,j,0);
                if(check){
                    return true;
                }
            }
        }
        return check;
    }
};
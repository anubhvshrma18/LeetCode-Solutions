class Solution {
public:
    void nqueensbnb(int r,vector<vector<bool>> &chess,vector<string> &v,vector<vector<string>> &ans,vector<bool> &colB,vector<bool> &regDB,vector<bool> &revDB){
        if(r==chess.size()){
            ans.push_back(v);
            return;
        }

        for(int c=0;c<chess.size();c++){
            int col=c;
            int rd=r+c;
            int revd=r-c+chess.size()-1;
            if(colB[c]==false && regDB[rd]==false && revDB[revd]==false){
                v[r][c]='Q';
                colB[c]=true;
                regDB[rd]=true;
                revDB[revd]=true;
                nqueensbnb(r+1,chess,v,ans,colB,regDB,revDB);
                v[r][c]='.';
                colB[c]=false;
                regDB[rd]=false;
                revDB[revd]=false;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //ans.clear();
        vector<bool> colB(n,false);
        vector<bool> regDB((2*n)-1,false);
        vector<bool> revDB((2*n)-1,false);
        vector<string> v(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            v[i] = s; 
        }
        vector<vector<string>> ans;
        vector<vector<bool>> chess(n,vector<bool>(n,false));
        // vector<vector<string>> ans(n,vector<string>(n,"."));
        nqueensbnb(0,chess,v,ans,colB,regDB,revDB);
        return ans;
    }
};
class Solution {
public:
    bool isItSafe(vector<vector<char>> &v,int r,int c,int val){
	    // row
        for(int i=0;i<9;i++){
            if(v[i][c]-'0'==val){
                return false;
            }
        }

        // column
        for(int j=0;j<9;j++){
            if(v[r][j]-'0'==val){
                return false;
            }
        }

        // submatrix
        int sbrn=r/3,sbcn=c/3;
        int x=sbrn*3,y=sbcn*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(v[i][j]-'0'==val){
                    return false;
                }
            }
        }

        return true;

    }
    int cnt;
    void solveSud(vector<vector<char>> &v,int r,int c){
        if(c==9){
            r++;
            c=0;
        }

        if(r==9){
            cnt++;
            return;
        }

        if(v[r][c]=='.'){
            for(int i=1;i<=9;i++){
                char tbp = (char)(i+'0');
                if(isItSafe(v,r,c,i)){
                    v[r][c]=tbp;
                    solveSud(v,r,c+1);
                    if(cnt == 1){
                        return;
                    }
                    v[r][c]='.';
                }
            }
        }
        else{
            solveSud(v,r,c+1);
        }

    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        cnt=0;
        solveSud(board,0,0);
    }
};
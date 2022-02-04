class Solution {
public:
    string pushDominoes(string s) {
        int n=s.size();
        vector<int> left(n,0),right(n,0);
        char prev='.';
        int cnt=1;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                prev='R';
                cnt=1;
                continue;
            }
            else if(s[i]=='L'){
                prev='L';
            }
            
            if(prev=='R' && s[i]=='.') {
                right[i]=cnt;
                cnt++;
            }
        }
        prev='.';
        cnt=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='L'){
                prev='L';
                cnt=1;
                continue;
            }
            else if(s[i]=='R'){
                prev='R';
            }
            if(prev=='L' && s[i]=='.') {
                left[i]=cnt;
                cnt++;
            }
        }
        
        string ans="";
        for(int i=0;i<n;i++){
            if(left[i]==0 && right[i]==0) {
                ans+=s[i];
            }
            else if(left[i]==0){
                ans+='R';
            }
            else if(right[i]==0){
                ans+='L';
            }
            else if(left[i]==right[i]) {
                ans+='.';
            }
            else if(left[i] > right[i]){
                ans+='R';
            }
            else{
                ans+='L';
            }
        }
        
        return ans;
    }
};
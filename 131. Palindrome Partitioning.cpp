class Solution {
public:
    void pp(string s,vector<string>& v,vector<vector<string>>& ans,int idx){
        if(idx==s.length()){
            ans.push_back(v);
            return;
        }
        
        for(int i=idx;i<s.length();i++){
            string sub = s.substr(idx,i+1);
            if(palindrome(sub)){
                v.push_back(sub);
                pp(s.substr(i+1),v,ans,0);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        pp(s,v,ans,0);
        return ans;
    }
    
    bool palindrome(string& s){
        int l=0;
        int h=s.length()-1;
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
};
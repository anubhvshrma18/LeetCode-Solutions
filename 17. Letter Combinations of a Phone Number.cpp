class Solution {
public:
    vector<string> v{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // vector<string> ans;
    vector<string> sol(string str){
        if(str.size()==0){
            vector<string> em;
            em.push_back("");
            return em;
        }
        // char ch=;
        string s = v[str[0]-'0'];
        vector<string> rans = sol(str.substr(1));
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            string ch="";
            ch+=s[i];
            for(int j=0;j<rans.size();j++){
                ans.push_back(ch+rans[j]);
            }
        }
        
        return ans;
        
        
    }
    vector<string> letterCombinations(string digits) {
        // ans.clear();
        if(digits.length()==0){
            vector<string> ans;
            return ans;
        }
        return sol(digits);
    }
};
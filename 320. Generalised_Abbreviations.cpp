class Solution {
public:
    vector<string> ans;
    void generate(int idx,string s,int ssf,string asf){
        if(idx==s.length()){
            if(ssf==0){
                ans.push_back(asf);
            }
            else{
                asf=asf+to_string(ssf);
                ans.push_back(asf);
            }
            return;
        }

        if(ssf!=0){
            generate(idx+1,s,0,asf+to_string(ssf)+s[idx]);
        }
        else{
            generate(idx+1,s,0,asf+s[idx]);
        }

        generate(idx+1,s,ssf+1,asf);
    }
    vector<string> generateAbbreviations(string &word) {
        // Write your code here
        ans.clear();
        generate(0,word,0,"");
        return ans;
    }
};
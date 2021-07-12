vector<string> ans;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(ch==')'){
                    if(st.size()>0 && st.top()=='('){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else if(ch==']'){
                    if(st.size()>0 && st.top()=='['){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else if(ch=='}'){
                    if(st.size()>0 && st.top()=='{'){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(st.size()>0){
            return false;
        }
        else
            return true;
    }
    void generate(int lbc,int rbc,string asf){
        if(lbc==0 and rbc==0){
            // if(isValid(asf)){
                ans.push_back(asf);
            // }
            // return;
        }
        if(lbc>0){
            generate(lbc-1,rbc,asf+"(");
        }
        if(rbc>lbc){
            generate(lbc,rbc-1,asf+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        generate(n,n,"");
        return ans;
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0,c=0;
        
        for(char ch:s) {
            if(ch=='(') {
                o++;
            } else if(o>0){
                o--;
            } else {
                c++;
            }

        }
        
        return o+c;
    }
};


class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if(ch=='(') {
                st.push(ch);
            } else if(st.size()>0 && st.top()=='(') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        
        return st.size();
    }
};
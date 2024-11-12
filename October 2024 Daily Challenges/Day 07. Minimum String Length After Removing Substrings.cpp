class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for(auto c: s){
            if(c == 'B')
                if(stk.size() && stk.top() == 'A'){
                    stk.pop();
                } else {
                   stk.push(c); 
                }
            else if(c == 'D') 
                if(stk.size()>0 && stk.top() == 'C'){
                    stk.pop();
                } else {
                    stk.push(c);
                }
            else 
                stk.push(c);
        }
        return stk.size();
    }
};
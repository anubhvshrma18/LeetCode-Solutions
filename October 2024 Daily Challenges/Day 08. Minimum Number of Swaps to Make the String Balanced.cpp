class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        
        for(char &ch : s) {
            if(ch == '[')      size++;
            else if(size != 0) size--;
        }
        
        return (size+1)/2;
    }
};


class Solution {
public:
    int minSwaps(string s) {
        int cb=0,op=0,ans=0;
        stack<char> stack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                stack.push(s[i]);
                op++;
            }
            if(s[i]==']' && stack.size()!=0 && stack.top()=='['){
                stack.pop();
                op--;
            }
            
        }
        
        ans=stack.size();
        if(ans%2==0)
            return ans/2;
        else
            return (ans+1)/2;
    }
};
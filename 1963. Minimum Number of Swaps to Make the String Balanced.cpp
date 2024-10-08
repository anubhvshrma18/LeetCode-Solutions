// Time Complexity - O(N)
// Space Complexity - O(N/2)
class Solution {
public:
    int minSwaps(string s) {
        stack<char> stack;
        for(char ch:s){
            if(s[i]=='['){
                stack.push(s[i]);
            }
            else if(stack.size()!=0 ){
                stack.pop();
            }
        }
        return (st.size()%2==0)? st.size()/2 : (st.size()+1)/2;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)
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

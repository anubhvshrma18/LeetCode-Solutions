// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for(char ch:s) {
            if(ch=='(') {
                st.push(ch);
            } else {
                // balance this closing parantheses
                if(st.size()>0 && st.top()=='(') {
                    st.pop();
                } else {
                    // you cannot balance this closing parantheses, so add it in the storage
                    st.push(ch);
                }
            }
        }

        return st.size();
    }
};


// Time Complexity - O(N)
// Space Complexity - O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBracketCount =0, closedBrackedCount=0;

        for(char ch:s) {
            if(ch=='(') {
                openBracketCount++;
            } else {
                if(openBracketCount>0) {
                    openBracketCount--;
                } else {
                    closedBrackedCount++;
                }
            }
        }

        return openBracketCount+closedBrackedCount;
    }
};

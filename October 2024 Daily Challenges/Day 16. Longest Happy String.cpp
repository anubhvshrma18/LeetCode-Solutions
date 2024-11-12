class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq; // storing characters with their frequencies
        
        // store the characters
        if(a!=0) pq.push({a,'a'});
        if(b!=0) pq.push({b,'b'});
        if(c!=0) pq.push({c,'c'});
        
        string ans = "";
        char prev = '*', prev2 = '*';
        
        while(!pq.empty()) {
            
            auto maxChar = pq.top();
            pq.pop();
            
            int currChFreq = maxChar.first;
            char currCh = maxChar.second;
            
            if(currCh == prev && currCh == prev2) {
                
                if(pq.empty()) break;
                auto secondMaxChar = pq.top();
                pq.pop();
                
                int secondMaxCharFreq = secondMaxChar.first;
                
                ans += secondMaxChar.second;
                secondMaxCharFreq--;
                
                // adding back if second char frequency is greater than 0
                if(secondMaxCharFreq>0) {
                    pq.push({secondMaxCharFreq, secondMaxChar.second});
                }
                
                pq.push({currChFreq, currCh});
                
                prev2 = prev;
                prev = secondMaxChar.second;
                
            } else {
                
                ans += currCh;
                
                currChFreq--;
                
                if(currChFreq > 0) {
                    pq.push({currChFreq, currCh});
                }
                // update the prevChars
                prev2 = prev;
                prev = currCh;
                
            }
            
            
        }
        
        return ans;
    }
};
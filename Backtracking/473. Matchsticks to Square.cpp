class Solution {
public:
    bool check=false;
    bool makesquare(vector<int>& matchsticks) {
        int val = accumulate(begin(matchsticks), end(matchsticks), 0); 
        if (size(matchsticks) < 4 || val % 4) return false; 
        val /= 4; 
        
        unordered_map<int, bool> memo; 
        
        function<bool(int, int)> fn = [&](int mask, int x) {
            if (memo.find(mask) == memo.end()) 
                if (!mask) memo[mask] = (x == 0); 
                else 
                    for (int i = 0; i < size(matchsticks); ++i) 
                        if (mask & (1 << i) && x + matchsticks[i] <= val) 
                            if (fn(mask ^ (1 << i), (x + matchsticks[i])%val)) {
                                memo[mask] = true; 
                                break; 
                            }; 
            return memo[mask]; 
        }; 
        
        return fn((1<<size(matchsticks))-1, 0); 
    }
};
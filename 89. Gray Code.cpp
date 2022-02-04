class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> res;
        backtrack(bits,res,n);
        return res;
    }
    void backtrack(bitset<32> &bits,vector<int> &res,int n){
        if(n==0){
            res.push_back(bits.to_ulong());
            return;
        }
        backtrack(bits,res,n-1);
        bits.flip(n-1);
        backtrack(bits,res,n-1);
    }
};
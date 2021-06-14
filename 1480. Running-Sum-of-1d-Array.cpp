class Solution {
public:
    int sum=0;
    vector<int> runningSum(vector<int>& nums) {
       vector<int> v;
        for(auto x:nums){
           sum+=x;
           v.push_back(sum);
       }
        
        return v;
    }
};
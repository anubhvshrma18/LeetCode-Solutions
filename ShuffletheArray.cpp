class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> x;
        vector<int> y;
        vector<int> c;
        for(int i=0;i<n;i++){
            x.push_back(nums[i]);
            y.push_back(nums[n+i]);
        }
        for(int i=0;i<n;i++){
            c.push_back(x[i]);
            c.push_back(y[i]);
        }
        return c;
    }
};
class Solution {
public:
    int search(vector<int>nums , int target , int i , int j){
        if(i >= j) return i;
        int mid = i + (j -i)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return search(nums , target , i , mid-1);
        else return search(nums , target , mid+1 , j);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        if(nums.size() == 0) return v;
        int index = search(nums , target , 0 , nums.size()-1);
        if(target == nums[index]){
            int start = index , end = index;
            while( start >= 0 && nums[start] == target ) start--;
            while(end < nums.size() && nums[end] == target ) end++;
            start++;
            end--;
            v[0] = start;
            v[1] = end;
        }
        return v;
    }
};

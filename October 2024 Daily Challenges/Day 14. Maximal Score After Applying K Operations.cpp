class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0;i<k;i++) {
            long long top= pq.top()*1LL;
            ans += top;
            pq.pop();
            pq.push((top+2)/3);
        }
        return ans;
    }
};


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<long long> pq; // storing the k max elements;
        
        for(int i=0;i<n;i++) {
            pq.push(nums[i]);
        }
        
        long long ans = 0;
        
        for(int i=0;i<k;i++) {
            long long top = pq.top();
            pq.pop();
            
            ans += top;
            
            long long ceil = (top/3) + (top%3 != 0);
            // for calculating ceil another  (a+b-1)/b
            
            pq.push(ceil);
            
        }
        
        return ans;
    }
};
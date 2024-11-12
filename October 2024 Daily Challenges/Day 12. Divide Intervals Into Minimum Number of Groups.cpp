class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        // min heap
        priority_queue<int, vector<int>, greater<int>> endTimeStorage;
        
        for(int i=0;i<n;i++) {
            
            int strtTime = intervals[i][0];
            int endTime = intervals[i][1];
            
            if(endTimeStorage.empty()) {
                endTimeStorage.push(endTime);
            } else if(endTimeStorage.top() < strtTime){
                endTimeStorage.pop();
                endTimeStorage.push(endTime);
            } else {
                endTimeStorage.push(endTime);
            }
        }
        
        return endTimeStorage.size();
    }
};


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<int> arr(1000002,0);
        
        for(int i=0;i<n;i++) {
            int strtTime = intervals[i][0];
            int endTime = intervals[i][1];
            
            arr[strtTime]++;
            arr[endTime+1]--;
        }
        
        int ans = 0;
        
        for(int i=1;i<1000001;i++) {
            arr[i]+=arr[i-1];
            ans = max(ans, arr[i]);
        }
        
        return ans;
        
    }
};
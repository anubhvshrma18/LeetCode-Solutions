class Solution {
public:
    int search(vector<vector<int>>& items, int price) {
        int l = 0, r = items.size()-1, mB = 0;;
        while(l<=r) {
            int m = (r+l)/2;
            if(items[m][0] <= price) {
                mB = max(mB, items[m][1]);
                l = m+1;
            } else {
                r=m-1;
            }
        }
        return mB;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items), end(items));
        int mx = INT_MIN;
        for(auto &i:items) {
            mx = max(mx, i[1]);
            i[1]=mx;
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++) {
            res.push_back(search(items, queries[i]));
        }
        return res;
    }
};
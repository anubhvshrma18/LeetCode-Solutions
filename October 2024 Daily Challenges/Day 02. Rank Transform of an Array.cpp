class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr);
        sort(v.begin(),v.end());
        unordered_map<int,int> mp;
        for(int a:v) {
            if(mp.find(a) == mp.end()) {
                mp[a] = mp.size()+1;
            }
        }
        vector<int> A(arr.size());
        for(int i=0;i<arr.size();i++) {
            A[i]=mp[arr[i]];
        }
        return A;
    }
};
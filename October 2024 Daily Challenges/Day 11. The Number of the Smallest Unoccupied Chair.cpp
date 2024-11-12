class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<times.size();i++){
            pq.push({times[i][0],{times[i][1],i}});
        }
        int n=times.size();
        vector<int> occupied_seats(n+1,-1);
        while(!pq.empty()){
            int arr=pq.top().first;
            int dept=pq.top().second.first;
            int frnd=pq.top().second.second;
            pq.pop();
            int occupied_seat=-1;
            for(int i=0;i<occupied_seats.size();i++){
                if(occupied_seats[i]==-1||occupied_seats[i]<=arr){
                    occupied_seats[i]=dept;
                    occupied_seat=i;
                    break;
                }
            }
            if(frnd==targetFriend){
                return occupied_seat;
            }
        }
        return -1; 
    }
};


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        int targettime = times[targetFriend][0];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> st1;
        priority_queue<int,vector<int>, greater<int>> st2;
        int chair = 0; 
        sort(times.begin(), times.end());
        
        for(int i=0;i<n;i++) {
            int arr = times[i][0];
            int dept = times[i][1];
            
            while(!st1.empty() && (st1.top()).first <= arr) {
                st2.push(st1.top().second);
                st1.pop();
            }
            
            if(st2.empty()) {
                st1.push({dept, chair});
                if(arr == targettime) return chair;
                chair++;
            } else {
                st1.push({dept, st2.top()});
                if(arr == targettime) return st2.top();
                st2.pop();
            }
        }
        return -1;
    }
};



class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        int targettime = times[targetFriend][0];
        set<pair<int,int>> st1;
        set<int> st2;
        int chair = 0; 
        sort(times.begin(), times.end());
        
        for(int i=0;i<n;i++) {
            int arr = times[i][0];
            int dept = times[i][1];
            
            while(!st1.empty() && (st1.begin())->first <= arr) {
                st2.insert(st1.begin()->second);
                st1.erase(st1.begin());
            }
            
            if(st2.empty()) {
                st1.insert({dept, chair});
                if(arr == targettime) return chair;
                chair++;
            } else {
                st1.insert({dept, *st2.begin()});
                if(arr == targettime) return *st2.begin();
                st2.erase(*st2.begin());
            }
        }
        return -1;
    }
};



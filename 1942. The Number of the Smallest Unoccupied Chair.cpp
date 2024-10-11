// Time Complexity - O(N^2)
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        int targetArrivalTime = times[targetFriend][0];

        vector<int> chairs(n,-1);

        sort(times.begin(), times.end());

        for(int i=0;i<n;i++) {
            int arrTime = times[i][0];
            int deptTime = times[i][1];

            for(int i=0;i<n;i++) {
                if(chairs[i] == -1) {
                    chairs[i]=deptTime;
                    if(arrTime == targetArrivalTime) return i;
                    break;
                } else if(chairs[i] <= arrTime) {
                    chairs[i]=deptTime;
                    if(arrTime == targetArrivalTime) return i;
                    break;
                }
            }
        }

        return -1;
    }
};



// Time Complexity - O(NLogN)
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        int targetArrivalTime = times[targetFriend][0];

        // you can try with set
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied_chairs;
        priority_queue<int, vector<int>, greater<int>> freeChairs;

        sort(times.begin(), times.end());

        int currChair = 0;

        for(int i=0;i<n;i++) {
            int arrTime = times[i][0];
            int deptTime = times[i][1];

            // check for occupied chairs that will be free
            while(!occupied_chairs.empty() && occupied_chairs.top().first <= arrTime) {
                int freeChair = occupied_chairs.top().second;
                occupied_chairs.pop();
                freeChairs.push(freeChair);
            }

            // assigning free chair to ith friend
            if(freeChairs.empty()) {
                occupied_chairs.push({deptTime, currChair});
                if(arrTime == targetArrivalTime) {
                    return currChair;
                }
                currChair++;
            } else {
                int smallestChair = freeChairs.top();
                freeChairs.pop();
                if(arrTime == targetArrivalTime) {
                    return smallestChair;
                }
                occupied_chairs.push({deptTime, smallestChair});
            }
        }

        return -1;
    }
};

// Leetcode - https://leetcode.com/problems/minimum-total-distance-traveled/

class Solution {
public:
    long long minDistance(int currentRobot, int currentFactory, vector<int>& robot, vector<int>& factories, 
                         vector<vector<long long>>& dp) {
        
        // if all robots are assigned to some factories
        if(currentRobot == robot.size()) {
            return 0;
        }
        
        // if all factories are asssinged or not but we have reached the end  some robots are left
        if(currentFactory == factories.size()) {
            return 1e12;
        }
        
        if(dp[currentRobot][currentFactory] != -1) {
            return dp[currentRobot][currentFactory];
        }
        
        // assign current robot to current factory
        long long assigned = abs(robot[currentRobot]-factories[currentFactory]) 
            + minDistance(currentRobot+1, currentFactory+1, robot, factories, dp);
        
        // current robot is not assigned to current factory
        long long notAssigned = minDistance(currentRobot, currentFactory+1, robot, factories, dp);
        
        return dp[currentRobot][currentFactory]=min(assigned, notAssigned);
        
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<int> factories;
        for(auto factor:factory) {
            int pos = factor[0];
            int limit = factor[1];
            
            for(int i=0;i<limit;i++) {
                factories.push_back(pos);
            }
        }
        
        vector<vector<long long>> dp(robot.size(), vector<long long>(factories.size(), -1));
        
        return minDistance(0, 0, robot, factories, dp);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL) return -1;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q; // for BFS
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            while(size>0) {
                TreeNode* node = q.front();
                q.pop();
                levelSum+=node->val*1LL;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                size--;
            }
            if(levelSum>0) {
                pq.push(levelSum);
            }
            if(pq.size()>k) {
                pq.pop();
            }
        }
        return (pq.size() == k) ? pq.top() : -1;
        
    }
};
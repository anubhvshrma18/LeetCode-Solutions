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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Calculate levelSum using BFS
        queue<TreeNode*> q;
        vector<long long> levelSumStorage;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                levelSum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelSumStorage.push_back(levelSum);
        }
        
        // Updating the node values with their cousins sum
        
        q.push(root);
        int level = 1;
        
        root->val = 0;
        
        while(!q.empty()) {
            int size = q.size();
            int levelSum = level<levelSumStorage.size() ? levelSumStorage[level] : 0;
            
            while(size--) {
                TreeNode* currNode = q.front();
                q.pop();
                // preprocessing
                int siblingSum = (currNode->left ? currNode->left->val:0) + (currNode->right? currNode->right->val :0);
                if(currNode->left) {
                    currNode->left->val = levelSum-siblingSum;
                    q.push(currNode->left);
                }
                if(currNode->right) {
                    currNode->right->val = levelSum-siblingSum;
                    q.push(currNode->right);
                }
            }
            level++;
        }
        
        return root;
        
    }
};
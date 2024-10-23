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
        vector<long long> levelSumStore;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                levelSum+=node->val;

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            levelSumStore.push_back(levelSum);
        }

        // Update the tree with modified values of cousins

        q.push(root);
        root->val = 0;

        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            long long levelSum = (level < levelSumStore.size() ? levelSumStore[level] : 0);

            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                // pre processing
                int siblingSum = (node->left? node->left->val: 0) + (node->right ? node->right->val : 0);

                if(node->left) {
                    node->left->val = levelSum - siblingSum;
                    q.push(node->left);
                }
                if(node->right) {
                    node->right->val = levelSum - siblingSum;
                    q.push(node->right);
                }
            }
            level++;
        }

        return root;
    }
};

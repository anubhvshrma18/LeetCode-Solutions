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
    unordered_map<int, int> leftMap;
    unordered_map<int, int> rightMap;
    unordered_map<int, int> removed;
    int populateHeights(TreeNode* root, int height) {
        if (root == NULL) {
            return height - 1;
        }
        
        int left = populateHeights(root->left, height + 1);
        int right = populateHeights(root->right, height + 1);
        
        leftMap[root->val]=left;
        rightMap[root->val]= right;
        
        return max(left, right);
    }
    void calculateRemovedHeights(TreeNode* root, int height) {
        if (root == NULL) return;
        removed[root->val]= height;
		
        calculateRemovedHeights(root->left, max(height, rightMap[root->val]));
        calculateRemovedHeights(root->right, max(height, leftMap[root->val]));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        populateHeights(root, 0);
        calculateRemovedHeights(root, 0);
        
        vector<int> output(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            output[i] = removed[queries[i]];
        }
        return output;
    }
    
    
};
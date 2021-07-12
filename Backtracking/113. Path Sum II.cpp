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
    vector<vector<int>> res;
    void sm(TreeNode* root,int tar,vector<int> &v){
        if(!root){return;}
        if(!root->left && !root->right){
            if(tar==root->val){
                v.push_back(root->val);
                res.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        sm(root->left,tar-root->val,v);
        sm(root->right,tar-root->val,v);
        v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        sm(root,targetSum,v);
        return res;
    }
};
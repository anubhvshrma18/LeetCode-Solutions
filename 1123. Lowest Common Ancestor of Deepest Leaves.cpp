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

// recursive solution
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return f(root).first;
    }
    
    pair<TreeNode*,int> f(TreeNode*root){
        if(root==NULL) return{root,0};
        
        auto left = f(root->left);
        auto right = f(root->right);
        
        if(left.second ==  right.second) return {root,left.second+1};
        
        if(left.second > right.second) return {left.first,left.second+1};
        
        return {right.first,right.second+1};
    }
};


// iterative solution
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* temp=root;

        while(temp!=NULL){
            int lsd = f(temp->left);
            int rsd = f(temp->right);

            if(lsd == rsd) break;
            else if(lsd > rsd) temp = temp->left;
            else temp = temp->right;
        }
        return temp;
    }
    
    int f(TreeNode*root){
        if(!root) return 0;
        return max(f(root->left),f(root->right))+1;
    }
};

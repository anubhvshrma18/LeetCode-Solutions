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
    // DFS Solution
    int sum=0;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(root->val%2==0){
            if(root->left){
                if(root->left->left){sum+=root->left->left->val;}
                if(root->left->right){sum+=root->left->right->val;}
            }
            if(root->right){
                if(root->right->left){sum+=root->right->left->val;}
                if(root->right->right){sum+=root->right->right->val;}
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
    

    // BFS Solution
    void bfs(TreeNode* root){
        if(!root){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val%2 == 0){
                if(node->left){
                    if(node->left->left) sum+=node->left->left->val;
                    if(node->left->right) sum+=node->left->right->val;
                }
                if(node->right){
                    if(node->right->left) sum+=node->right->left->val;
                    if(node->right->right) sum+=node->right->right->val;
                }
            }

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }    
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
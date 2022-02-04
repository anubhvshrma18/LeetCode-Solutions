/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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


// DFS + BFS
class Solution {
    bool dfs(ListNode* head, TreeNode* root){
        if(root == NULL) return false;
        bool ans=false;
        if(head->val == root->val){
            ans = bfs(head,root);
        }
        
        bool left = dfs(head,root->left);
        bool right = dfs(head,root->right);
        
        return left || right || ans;
    }
    
    bool bfs(ListNode* head, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        ListNode* temp=head->next;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && temp && node->left->val == temp->val){
                    q.push(node->left);
                }
                if(node->right && temp && node->right->val == temp->val){
                    q.push(node->right);
                }
            }
            
            if(!q.empty()) temp=temp->next;
        }
        
        return temp==NULL;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,root);
    }
    
    
};


// DFS + DFS
class Solution {
    bool dfs(ListNode* head, TreeNode* root){
        if(root == NULL) return false;
        if(dfs2(head,root)) return true;
        return dfs(head,root->left) || dfs(head,root->right);
    }
    
    bool dfs2(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head->val!=root->val) return false;
        return dfs2(head->next,root->left) || dfs2(head->next,root->right); 
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,root);
    }
    
    
};
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL || root1->val != root2->val) return false;
        // L1 == L2 and R1==R2 - It is not flipped
        // L1 == R2 and L2 == R1 It is flipped
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
        (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
};

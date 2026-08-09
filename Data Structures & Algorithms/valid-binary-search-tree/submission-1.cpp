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
    bool isValidBST(TreeNode* root) {
        long long left=LLONG_MIN;
        long long right=LLONG_MAX;
        return dfs(root,left,right);
    }
    bool dfs(TreeNode* node,long long left,long long right){
        if(node==nullptr)return true;
        int value=node->val;
        if(value<=left || value>=right){
            return false;
        }
        bool l=dfs(node->left,left,node->val);
        bool r=dfs(node->right,node->val,right);
        return (l && r);

    }
};

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
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
    void postorder(TreeNode* temp){
        if(temp==nullptr)return;
        postorder(temp->left);
        postorder(temp->right);
        ans.push_back(temp->val);
    }
};
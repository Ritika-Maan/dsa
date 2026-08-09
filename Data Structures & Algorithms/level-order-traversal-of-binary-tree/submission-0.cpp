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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty()){
            int n=qq.size();
            vector<int> ll;
            for(int i=0;i<n;i++){
                TreeNode* node=qq.front();
                qq.pop();
                ll.push_back(node->val);
                if(node->left){qq.push(node->left);}
                if(node->right){qq.push(node->right);}
            }
            ans.push_back(ll); 
        }
        return ans;
    }
};

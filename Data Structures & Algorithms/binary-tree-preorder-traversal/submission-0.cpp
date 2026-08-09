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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)return{};
        //NLR
        stack<TreeNode*> st;
        TreeNode* temp=root;
        vector<int> ans;
        st.push(temp);
        while(!st.empty()){
            //N
            temp=st.top();
            st.pop();
            ans.push_back(temp->val);

            //L
            if(temp->right){st.push(temp->right);}
            if(temp->left){st.push(temp->left);}

            //R
        }
        return ans;
    }
};
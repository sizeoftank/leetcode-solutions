class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()){
            TreeNode *n = stk.top();
            stk.pop();
            if (n){
                ret.push_back(n->val);
                stk.push(n->right);
                stk.push(n->left);
            }
        }
        return ret;
    }
};
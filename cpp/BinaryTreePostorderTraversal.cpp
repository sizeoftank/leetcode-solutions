class Solution {
private:
    vector<int> ret;
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ret.push_back(root->val);
        }
        return ret;
    }
};

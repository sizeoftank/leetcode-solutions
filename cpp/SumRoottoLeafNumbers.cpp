/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int count = 0;
public:
    int sumNumbers(TreeNode* root) {
        this->count = 0;
        if (root == NULL) {
            return 0;
        }
        this->trace(root, 0);
        return this->count;
    }

    void trace(TreeNode* node, int carry) {
        int value = (carry + node->val);
        if (!node->left && !node->right) {
            this->count = this->count + value;
            return;
        } else {
            if (node->left) {
                trace(node->left, value * 10);
            }
            if (node->right) {
                trace(node->right, value * 10);
            }
        }
    }
};
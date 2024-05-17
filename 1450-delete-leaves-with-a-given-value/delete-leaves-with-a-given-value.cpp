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
    TreeNode* removeLeafNodesHelper(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;

        auto left = removeLeafNodesHelper(root->left, target);
        auto right = removeLeafNodesHelper(root->right, target);

        if (left && left->val == target && left->left == nullptr && left->right == nullptr) {
            root->left = nullptr;
            delete left;
        }

        if (right && right->val == target && right->left == nullptr && right->right == nullptr) {
            root->right = nullptr;
            delete right;
        }

        return root;               
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = removeLeafNodesHelper(root, target);
        if (root && root->val == target && !root->left && !root->right) root = nullptr;
        return root;
    }
};
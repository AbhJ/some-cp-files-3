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
public:
    TreeNode* a, * b;
    pair <TreeNode *, bool> dfs (TreeNode* u) {
        if (u == NULL)
            return make_pair (nullptr, false);
        if (u == a or u == b)
            return make_pair (u, true);
        auto [leftLCA, leftPoss] = dfs (u -> left);
        auto [rightLCA, rightPoss] = dfs (u -> right);
        if (leftPoss == true and rightPoss == true)
            return make_pair (u, true);
        if (leftPoss == true)
            return make_pair (leftLCA, leftPoss);
        if (rightPoss == true)
            return make_pair (rightLCA, rightPoss);
        return make_pair (nullptr, false);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a = p, b = q;
        return dfs (root).first;
    }
};
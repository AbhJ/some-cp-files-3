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
    vector <int> v;
    void dfs (TreeNode* root, int lev = 0) {
        if (root == NULL)
            return;
        v[lev] += root -> val;
        dfs (root -> left, lev + 1);
        dfs (root -> right, lev + 1);
    }
    int maxLevelSum(TreeNode* root) {
        v.resize(1e4 + 1, 0);
        dfs (root);
        int ans = 0;
        for (int i = 0; i < 1e4 + 1; i++) {
            if (v[i] > v[ans])
                ans = i;
        }
        return ans + 1;
    }
};
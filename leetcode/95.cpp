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
class Solution
{
public:
    vector<vector<vector<TreeNode *>>> dp;

    vector<TreeNode *> BST(int st, int en, int n)
    {
        if (st > en or st < 1 or en > n)
            return vector<TreeNode *>{NULL};
        if (!dp[st - 1][en - 1].empty())
            return dp[st - 1][en - 1];
        if (st == en)
            return vector<TreeNode *>{new TreeNode(st)};
        for (int ce = st; ce <= en; ce++)
        {
            vector<TreeNode *> l = BST(st, ce - 1, n);
            vector<TreeNode *> r = BST(ce + 1, en, n);
            for (auto *le : l)
                for (auto *ri : r)
                {
                    TreeNode *cu = new TreeNode(ce, le, ri);
                    dp[st - 1][en - 1].emplace_back(cu);
                }
        }
        return dp[st - 1][en - 1];
    }

    vector<TreeNode *> generateTrees(int n)
    {
        dp.assign(n, vector(n, vector<TreeNode *>()));
        return BST(1, n, n);
    }
};
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
	map <int, vector<TreeNode*>> dp;
	vector<TreeNode*> allPossibleFBT (int n) {
		if (n & 1 ^ 1)
			return vector<TreeNode * >();
		if (n == 1)
			return vector<TreeNode * > {new TreeNode (0)};
		if (dp.contains (n))
			return dp[n];
		for (int i = 1; i <= n - 1; i++)
			for (auto lef : allPossibleFBT (i))
				for (auto rig : allPossibleFBT (n - 1 - i)) {
					TreeNode* cur = new TreeNode (0);
					cur -> left = lef;
					cur -> right = rig;
					dp[n].emplace_back (cur);
				}
		return dp[n];
	}
};
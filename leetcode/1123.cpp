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
	// depth,
	pair <int, TreeNode*> dfs (TreeNode* u, int dep = 0) {
		if (u == NULL)
			return make_pair (dep, nullptr);
		auto [depLeft, lcaLeft] = dfs (u -> left, dep + 1);
		auto [depRight, lcaRight] = dfs (u -> right, dep + 1);
		if (depLeft == depRight) {
			return make_pair (depLeft, u);
		}
		if (depLeft < depRight) {
			return make_pair (depRight, lcaRight);
		}
		return make_pair (depLeft, lcaLeft);
	}
	TreeNode* lcaDeepestLeaves (TreeNode* root) {
		return dfs (root).second;
	}
};
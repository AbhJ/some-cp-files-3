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
	vector<vector<int>> levelOrderBottom (TreeNode* root) {
		// depth, TreeNode*
		priority_queue <tuple<int, int, TreeNode*>> q;
		vector<vector<int>> v;
		int ord = 0;
		q.emplace (tuple<int, int, TreeNode*> {0, ord--, root});
		while (q.empty() == 0) {
			auto [dep, ty, u] = q.top();
			q.pop();
			dep = - dep;
			if (u == NULL)
				continue;
			if (v.size() <= dep) {
				v.resize (dep + 1);
			}
			v[dep].emplace_back (u -> val);
			q.emplace (tuple<int, int, TreeNode*> {- dep - 1, ord--, u -> left});
			q.emplace (tuple<int, int, TreeNode*> {- dep - 1, ord--, u -> right});
		}
		reverse (v.begin(), v.end());
		return v;
	}
};
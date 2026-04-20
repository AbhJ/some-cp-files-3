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
	string ans = "{";
	void dfs (TreeNode* root, string &s) {
		if (root == NULL) {
			return;
		}
		s += ((char) ('a' + root -> val));
		if (root -> left == NULL and root -> right == NULL) {
			bool upd = false;
			for (int i = s.length() - 1, j = ans.length() - 1; (~i) and (~j); i--, j--) {
				if (ans[j] > s[i]) {
					upd = true;
					break;
				}
				else if (ans[j] < s[i]) {
					upd = false;
					break;
				}
				if (i == 0 or j == 0) {
					if (ans.length() > s.length())
						upd = true;
				}
			}
			if (upd == true)
				ans = s;
		}
		dfs (root -> left, s);
		dfs (root -> right, s);
		s.pop_back();
	}
	string smallestFromLeaf (TreeNode* root) {
		string s;
		dfs (root, s);
		reverse (ans.begin(), ans.end());
		return ans;
	}
};
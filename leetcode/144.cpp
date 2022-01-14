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
	vector<int> preorderTraversal (TreeNode *A) {
		vector<int>v;
		stack<TreeNode * >s;
		TreeNode *tmp = new TreeNode (-1);
		tmp -> right = A;
		s.push (tmp);
		while (s.empty() == 0) {
			tmp = s.top() -> right;
			s.pop();
			while (tmp != NULL) {
				s.emplace (tmp);
				v.emplace_back (tmp -> val);
				tmp = tmp -> left;
			}
		}
		return v;
	}
};

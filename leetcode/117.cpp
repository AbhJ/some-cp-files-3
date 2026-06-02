/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	vector <Node*> v;

	void dfs (Node* root, int dep = 0) {
		if (root == NULL)
			return;
		if (v.size() == dep)
			v.resize (dep + 1);
		if (v[dep] != NULL)
			v[dep] -> next = root;
		v[dep] = root;
		dfs (root -> left, dep + 1);
		dfs (root -> right, dep + 1);
	}

	Node* connect (Node* root) {
		dfs (root);
		return root;
	}
};
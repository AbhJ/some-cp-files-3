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
    TreeNode* construct (int root, map <pair <int, int>, int> &e) {
        TreeNode* cur = new TreeNode (root);
        if (e.count({root, 1}))
            cur -> left = construct (e[{root, 1}], e);
        if (e.count({root, 0}))
            cur -> right = construct (e[{root, 0}], e);
        return cur;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set <int> nodes;
        map <pair <int, int>, int> edg;
        for (auto i: descriptions) {
            nodes.emplace(i[0]);
            nodes.emplace(i[1]);
            edg [{i[0], i[2]}]= i[1];
        }
        auto root_set = nodes;
        for (auto i: descriptions) {
            root_set.erase(i[1]);
        }
        int root = *root_set.begin();
        return construct (root, edg);
    }
};
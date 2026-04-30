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
    set <int> leftNonLeaves, leavesChecked;
    map <int, TreeNode*> m;
    bool inValid = false;
    int nodesSeenInValidation = 0;
    int nodesSeenInFirstGo = 0;
    void f (TreeNode* u) {
        if (inValid)
            return;
        nodesSeenInFirstGo++;
        if (u -> left != NULL) {
            if(m.count(u -> left -> val)) {
                u -> left = m[u -> left -> val];
                leftNonLeaves.erase(u -> left -> val);
            }
            else
                nodesSeenInFirstGo++;
            if (leavesChecked.count(u -> left -> val))
                inValid = true;
            leavesChecked.emplace(u -> left -> val);
        }
        if (u -> right != NULL) {
            if(m.count(u -> right -> val)) {
                u -> right = m[u -> right -> val];
                leftNonLeaves.erase(u -> right -> val);
            }
            else
                nodesSeenInFirstGo++;
            if (leavesChecked.count(u -> right -> val))
                inValid = true;
            leavesChecked.emplace(u -> right -> val);
        }
    }
    pair <int, int> validate (TreeNode* u) {
        if (inValid)
            return {- 1e9, - 1e9};
        nodesSeenInValidation++;
        int mini = u -> val, maxi = u -> val;
        if (u -> left) {
            auto [mi, ma] = validate (u -> left);
            if (ma > u -> val)
                inValid = true;
            mini = min (mi, mini);
        }
        if (u -> right) {
            auto [mi, ma] = validate (u -> right);
            if (mi < u -> val)
                inValid = true;
            maxi = max (ma, maxi);
        }
        return {mini, maxi};
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for (auto i: trees) {
            m[i -> val] = i;
            leftNonLeaves.emplace(i -> val);
        }
        for (auto i: trees) {
            f (i);
        }
        if (leftNonLeaves.size() != 1)
            return NULL;
        validate (m[*leftNonLeaves.begin()]);
        if (inValid or nodesSeenInFirstGo != nodesSeenInValidation)
            return NULL;
        return m[*leftNonLeaves.begin()];
    }
};
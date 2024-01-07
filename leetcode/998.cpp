class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* cur = new TreeNode (val);
        if (root == NULL)
            return cur;
        if (root -> val < val){
            cur -> left = root;
            return cur;
        }
        root -> right = insertIntoMaxTree (root -> right, val);
        return root;
    }
};
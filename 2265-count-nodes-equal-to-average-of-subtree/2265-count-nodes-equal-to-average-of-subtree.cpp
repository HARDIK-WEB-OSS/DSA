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
    int ans = 0;

    void dfs(TreeNode* root, int& sum, int& cnt) {
        if (!root) {
            sum = 0;
            cnt = 0;
            return;
        }

        int ls, lc, rs, rc;
        dfs(root->left, ls, lc);
        dfs(root->right, rs, rc);

        sum = ls + rs + root->val;
        cnt = lc + rc + 1;

        if (sum / cnt == root->val)
            ans++;
    }

    int averageOfSubtree(TreeNode* root) {
        int sum, cnt;
        dfs(root, sum, cnt);
        return ans;
    }
};
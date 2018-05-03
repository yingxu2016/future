/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> v;
        helper(root, v);
        int l = 0, r = v.size() - 1;
        while(l < r) {
            if(v[l] + v[r] == k) {
                return true;
            }
            else if(v[l] + v[r] > k) {
                r--;
            }
            else {
                l++;
            }
        }
        return false;
    }
    void helper(TreeNode* root, vector<int>& v) {
        if(!root) {
            return;
        }
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
};

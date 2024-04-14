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
    TreeNode* constructTree(int l, int r, vector<int>& nums){
        if(l > r) return NULL;
        int m = (l + r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = constructTree(l, m-1, nums);
        root->right = constructTree(m+1, r, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(0, nums.size()-1, nums);;
    }
};
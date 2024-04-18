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
    void getNodesByLevel(TreeNode* root, vector<vector<int>>& result, int i){
        if(!root) return;
        if(i >= result.size()){
            result.resize(i+1);
        }
        result[i].push_back(root->val);
        getNodesByLevel(root->left, result, i+1);
        getNodesByLevel(root->right, result, i+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> nodes;
        getNodesByLevel(root, nodes, 0);
        int max = INT_MIN;
        int idx = 1;
        for(int i = nodes.size()-1; i >= 0; i--){
            int sum = 0;
            for(int j = 0; j < nodes[i].size(); j++){
                sum += nodes[i][j];
            }
            if(sum >= max) {
                idx = i+1;
                max = sum;
            }
        }
        return idx;
    }
};
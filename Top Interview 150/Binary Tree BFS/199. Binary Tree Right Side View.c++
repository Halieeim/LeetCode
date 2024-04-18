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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> nodes;
        vector<int> rightSideNodes;
        getNodesByLevel(root, nodes, 0);
        for(int i = 0; i < nodes.size(); i++){
            rightSideNodes.push_back(nodes[i][nodes[i].size() - 1]);
        }
        return rightSideNodes;
    }
};
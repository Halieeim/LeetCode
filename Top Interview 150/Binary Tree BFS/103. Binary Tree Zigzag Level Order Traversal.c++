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
    void getNodesByLevel1(TreeNode* root, vector<vector<int>>& result, int i){
        if(!root) return;
        if(i >= result.size()){
            result.resize(i+1);
        }
        result[i].push_back(root->val);
        getNodesByLevel1(root->left, result, i+1);
        getNodesByLevel1(root->right, result, i+1);
    }

    void getNodesByLevel2(TreeNode* root, vector<vector<int>>& result, int i){
        if(!root) return;
        if(i >= result.size()){
            result.resize(i+1);
        }
        result[i].push_back(root->val);
        getNodesByLevel2(root->right, result, i+1);
        getNodesByLevel2(root->left, result, i+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes1, nodes2, res;
        getNodesByLevel1(root, nodes1, 0);
        getNodesByLevel2(root, nodes2, 0);
        int n = nodes1.size();
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) res.push_back(nodes1[i]);
            else res.push_back(nodes2[i]);
        }
        return res;
    }
};
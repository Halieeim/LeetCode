/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    void f(TreeNode root, List<List<Integer>> res, int i){
        if(root == null) return;
        if (i >= res.size()) {
            // Ensure that res has a list at index i
            res.add(new ArrayList<>());
        }
        res.get(i).add(root.val);
        f(root.left, res, i+1);
        f(root.right, res, i+1);
    }
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null) return new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        f(root, res, 0);
        List<List<Integer>> reversed = new ArrayList<>();
        for(int i = res.size() - 1; i >= 0; i--){
            reversed.add(res.get(i));
        }
        return reversed;
    }
}
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
    public void getNodesByLevel(TreeNode root, List<List<Integer>> nodes, int i){
        if(root == null) return;
        if(i == nodes.size()) nodes.add(new ArrayList<>());
        nodes.get(i).add(root.val);
        getNodesByLevel(root.left, nodes, i+1);
        getNodesByLevel(root.right, nodes, i+1);
    }
    public List<Integer> largestValues(TreeNode root) {
        List<List<Integer>> nodes = new ArrayList<>();
        List<Integer> maxs = new ArrayList<>();
        getNodesByLevel(root, nodes, 0);
        for(List<Integer> list: nodes){
            maxs.add(Collections.max(list));
        }
        return maxs;
    }
}
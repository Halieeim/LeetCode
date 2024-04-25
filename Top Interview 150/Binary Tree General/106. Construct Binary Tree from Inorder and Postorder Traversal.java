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
    public int getIdx(int[] arr, int num){
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == num) return i;
        }
        return -1;
    }
    public int[] subArray(int[] arr, int start, int end){
        if(end-start <= 0) return null;
        int[] sub = new int[end - start];
        for(int i = start; i < end && i < arr.length; i++){
            sub[i-start] = arr[i];
        }
        return sub;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder == null || inorder.length == 0) return null;
        TreeNode root = new TreeNode(postorder[postorder.length - 1]);
        int idx = getIdx(inorder, root.val);
        int[] leftInorder = subArray(inorder, 0, idx);
        int[] leftPostorder = subArray(postorder, 0, idx);
        root.left = buildTree(leftInorder, leftPostorder);

        int[] rightInorder = subArray(inorder, idx + 1, inorder.length);
        int[] rightPostorder = subArray(postorder, idx, postorder.length - 1);
        root.right = buildTree(rightInorder, rightPostorder);
        return root;
    }
}
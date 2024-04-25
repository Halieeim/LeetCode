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
import java.util.Arrays;
class Solution {
    public int getIdx(int[] arr, int num){
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == num) return i;
        }
        return -1;
    }
    public int[] subArray(int[] arr, int start, int end){
        int[] sub = new int[end - start];
        for(int i = start; i < end && i < arr.length; i++){
            sub[i-start] = arr[i];
        }
        return sub;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0 || inorder.length == 0) return null;
        TreeNode root = new TreeNode(preorder[0]);
        int m = getIdx(inorder, preorder[0]);
        int[] sub1 = subArray(preorder, 1, m+1);
        int[] sub2 = subArray(inorder, 0, m);
        root.left = buildTree(sub1, sub2);
        sub1 = subArray(preorder, m+1, preorder.length);
        sub2 = subArray(inorder, m+1, inorder.length);
        root.right = buildTree(sub1, sub2);
        return root;
    }
}
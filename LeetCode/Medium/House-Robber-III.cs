/*
https://leetcode.com/problems/house-robber-iii/submissions/

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/*
Idea is to decide on whether to rob the house or not
If we are robbing the house then we can only rob houses which are below the child houses
else we are robbing the houses below
1st index of the array signifies the case where we are not robbing the house
2nd index of the array signifies the case where we are robbing the house
*/
    
public class Solution {
    public int Rob(TreeNode root) {
        if (root == null)
            return 0;
        var sum = Robbed(root);
        return Math.Max(sum[0], sum[1]);
    }
    
    private int[] Robbed(TreeNode root) 
    {
        if(root == null){
            return new int[2];
        }
        
        int[] left = Robbed(root.left);
        int[] right = Robbed(root.right);
        
        var result = new int[2];
        result[0] = Math.Max(left[0], left[1]) + Math.Max(right[0], right[1]);
        result[1] = root.val + left[0] + right[0];
        return result;
        
        
    }
}

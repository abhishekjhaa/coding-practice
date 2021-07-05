/*
https://leetcode.com/problems/path-sum-ii/
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
public class Solution {
    public IList<IList<int>> PathSum(TreeNode root, int targetSum) {
        var result = new List<IList<int>>();
        PathSumPostOrder(root, targetSum, 0, result, new List<int>());
        return result;
    }
    
    private void PathSumPostOrder(TreeNode root, int targetSum, int currentSum, IList<IList<int>> result, List<int> path)
    {
        if(root == null)
        {
            return;
        }
        
        
        if(root.left == null && root.right == null && targetSum == currentSum + root.val)
        {
            var n = new List<int>(path);
            n.Add(root.val);
            result.Add(n);
            return;
        }
        
        path.Add(root.val);
        PathSumPostOrder(root.left, targetSum, currentSum + root.val, result, path);
        PathSumPostOrder(root.right, targetSum, currentSum + root.val, result, path);
        path.RemoveAt(path.Count - 1);
    }
}
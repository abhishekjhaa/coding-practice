/*
https://leetcode.com/problems/path-sum-iii/submissions/
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

https://leetcode.com/problems/path-sum-iii/discuss/141424/Python-step-by-step-walk-through.-Easy-to-understand.-Two-solutions-comparison.-%3A-)
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
    public int PathSum(TreeNode root, int sum) {
        
        Dictionary<int, int> map = new Dictionary<int, int>();
        map[0] = 1;
        return Traverse(root, 0, sum, map);
     
    }
    
    public int Traverse(TreeNode root, int currSum, int target, Dictionary<int,int> map)
    {
        if (root==null) return 0;
        int count = 0;
        
        currSum += root.val;

        int currTarget = currSum - target;
        
        count += map.GetValueOrDefault(currTarget, 0);
        map[currSum] = map.GetValueOrDefault(currSum, 0) + 1;
              
        int leftCnt = Traverse(root.left, currSum, target, map);
        int rightCnt = Traverse(root.right, currSum, target, map);
        
        map[currSum]--;
    
        return count + leftCnt + rightCnt;
    }
}
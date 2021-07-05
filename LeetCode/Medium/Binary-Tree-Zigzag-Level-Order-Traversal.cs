/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        if(root == null)
        {
            return new List<IList<int>>();
        }
        
        var result = new List<IList<int>>();
        int count = 0;
        int nextCount = 0;
        var level = 0;
        var q = new Queue<TreeNode>();
        q.Enqueue(root);
        nextCount++;
        while(q.Count > 0)
        {
            count = nextCount;
            nextCount = 0;
            var l = new List<int>();
            while(count > 0)
            {
                var node = q.Dequeue();
                if(node.left != null)
                {
                    q.Enqueue(node.left);
                    nextCount++;
                }
                if(node.right != null)
                {
                    q.Enqueue(node.right);
                    nextCount++;
                }
                
                if(level % 2 == 1)
                {
                    l.Insert(0, node.val);
                }
                else
                {
                    l.Add(node.val);
                }
                count--;
            }

            if(l.Count > 0)
            {
                result.Add(l);
            }
            
            level++;
        }
        
        return result;
        
    }
}
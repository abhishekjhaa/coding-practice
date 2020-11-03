/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    public void Flatten(TreeNode root) {
        //Console.WriteLine(root.left.val);
        FlattenR(root);
        //Console.WriteLine(root.right.val);
    }
    
    private TreeNode FlattenR(TreeNode root) {
        if(root == null)
            return null;
        if (root.left == null && root.right == null)
        {
            return root;
        }
        var left = FlattenR(root.left);
        //Console.WriteLine(root.left.val);
        if(left != null)
        {
            var temp = root.right;
            root.right = root.left;
            root.left = null;
            var node = root;
            while(node.right != null)
            {
                node = node.right;
            }
            node.right = temp;
        }
        FlattenR(root.right);
        return root;
    }
}
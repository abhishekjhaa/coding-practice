/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null)
            return null;
        
        //one of the nodes has been found. return it
        if(root.val==p.val || root.val==q.val)
            return root;
        
        //look for both nodes in both sub-trees
        TreeNode ancestorInLeftSubTree = LowestCommonAncestor(root.left, p, q);
        TreeNode ancestorInRightSubTree = LowestCommonAncestor(root.right, p, q);
        
        //if p & q were found in different sub-trees. I am the LCA
        if(ancestorInLeftSubTree!=null && ancestorInRightSubTree!=null)
            return root;
        
        //if an ancestor was found, return it. Else, return null. <b> Important Step </b>
        return (ancestorInLeftSubTree!=null) ? ancestorInLeftSubTree : ancestorInRightSubTree;
        
        /*var result = new TreeNode();
        LCA(root, p, q, result);
        
        return result;*/
    }
    
    private bool LCA(TreeNode root, TreeNode p, TreeNode q, TreeNode result) {
        if(root == null)
        {
            return false;
        }
        
        //Console.WriteLine(root.val);
        var left = LCA(root.left, p, q, result);
        var right = LCA(root.right, p, q, result);
        //Console.WriteLine("Left " + left.ToString());
        //Console.WriteLine("Right " + right.ToString());
        if (left && right)
        {
            //Console.WriteLine("Left Right " + right.ToString());
            result.val = root.val;
            return false;
        }
        
        if (root.val == p.val || root.val == q.val)
        {
            //Console.WriteLine("Left Right " + root.val.ToString());
            if(left || right)
            {
                result.val = root.val;
                return false;
            }
            
            return true;
        }
        
        if(left || right)
            {
                return true;
            }
        
        return false;
    }
}
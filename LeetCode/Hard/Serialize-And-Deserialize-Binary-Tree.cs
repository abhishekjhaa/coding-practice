/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
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
public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        var sb = new StringBuilder();
        serialize(root, sb);
        //Console.WriteLine(sb.ToString());
        return sb.ToString();
    }
    
    private void serialize(TreeNode root, StringBuilder sb) {
        if(root == null)
        {
            sb.Append($"#,");
            return;
        }
        
        sb.Append($"{root.val},");
        serialize(root.left, sb);
        serialize(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        var subs = data.Split(",");
        if(subs[0] == "#")
        {
            return null;
        }
        
        var q = new Queue<string>();
        for(var i = 0; i < subs.Length - 1; i++)
        {
            q.Enqueue(subs[i]);
            //Console.WriteLine(subs[i]);
        }
        
        return deserialize(q);
    }
    
    private TreeNode deserialize(Queue<string> q) {
        if(q.Count < 1)
        {
            return  null;
        }
        
        var s = q.Dequeue();
        if(s == "#")
        {
            return null;
        }
        
        var root = new TreeNode(int.Parse(s));
        root.left = deserialize(q);
        root.right = deserialize(q);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
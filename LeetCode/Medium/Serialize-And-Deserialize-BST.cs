/*
https://leetcode.com/problems/serialize-and-deserialize-bst/
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.
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
        var st = new Stack<TreeNode>();
        st.Push(root);
        while(st.Count > 0)
        {
            var node = st.Pop();
            if(node == null)
            {
                continue;
            }
            sb.Append($"{node.val},");
            st.Push(node.right);
            st.Push(node.left);
        }
        
        Console.WriteLine(sb.ToString());
        return sb.ToString();
        
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if(data == "")
        {
            return null;
        }
        string[] subs = data.Split(',');
        TreeNode root = new TreeNode(int.Parse(subs[0]));
        for(var i = 1; i < subs.Length - 1; i++)
        {
            //Console.WriteLine($"{i} - {subs[i]}");
            int.TryParse(subs[i], out var val);
            AddNode(val, root);
        }
        
        return root;
    }
    
    private void AddNode(int val, TreeNode root) {
        TreeNode parent = null;
        while(root != null)
        {
            parent = root;
            if(val > root.val)
            {
                root = root.right;
            }
            else
            {
                root = root.left;
            }
        }
        
        if(val > parent.val)
        {
            parent.right = new TreeNode(val);
        }
        else
        {
            parent.left = new TreeNode(val);
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
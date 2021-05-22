/*
https://leetcode.com/problems/clone-graph/
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
Example 4:


Input: adjList = [[2],[1]]
Output: [[2],[1]]
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/

/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    public Node CloneGraph(Node node) {
        if(node == null)
        {
            return null;
        }
        
        var q = new Queue<Node>();
        q.Enqueue(node);
        Node head = new Node(node.val, new List<Node>());
        var map = new Dictionary<int, Node>();
        map.Add(node.val, head);
        while(q.Count > 0)
        {
            var tNode = q.Dequeue();
            Node nNode = null;
            if(!map.ContainsKey(tNode.val))
            {
                nNode = new Node(tNode.val, new List<Node>());
            }
            else
            {
                nNode = map[tNode.val];
            }
            
            foreach(var ne in tNode.neighbors)
            {
                if(map.ContainsKey(ne.val))
                {
                    nNode.neighbors.Add(map[ne.val]);
                }
                else
                {
                    var nnNode = new Node(ne.val, new List<Node>()); 
                    nNode.neighbors.Add(nnNode);
                    map.Add(ne.val, nnNode);
                    q.Enqueue(ne);
                }
            }
        }
        
        return head;
        
        //return CloneGraphRecursive(node, new Dictionary<int, Node>());
    }
    
    private Node CloneGraphRecursive(Node node, Dictionary<int, Node> map) {
        if(node == null)
        {
            return null;
        }
        
        if(map.ContainsKey(node.val))
        {
            return map[node.val];
        }
        
        var result = new Node(node.val, new List<Node>());
        map.Add(result.val, result);
        foreach(var ne in node.neighbors)
        {
            result.neighbors.Add(CloneGraphRecursive(ne, map));
        }
        
        return result;
    }
}
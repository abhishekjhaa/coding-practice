/*
https://leetcode.com/problems/unique-binary-search-trees/
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19

https://www.youtube.com/watch?v=dN1JqAavM_g&feature=youtu.be&t=3
*/
public class Solution {
    private Dictionary<int, int> dict = new Dictionary<int, int>();
    public int NumTrees(int n) {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        
        if(dict.TryGetValue(n, out var value))
        {
            return value;
        }
        
        var total = 0;
        
        for(var left = 1; left <= n; left++)
        {
            total += NumTrees(left-1)*NumTrees(n-left);
        }
        
        dict[n] = total;
        
        return dict[n];
            
    }
}

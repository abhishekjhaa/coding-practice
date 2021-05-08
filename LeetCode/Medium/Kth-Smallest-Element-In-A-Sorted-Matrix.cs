/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
*/

public class Solution {
    public int KthSmallest(int[][] matrix, int k) {
        
        
        //return AdditionalArray(matrix, k);
    }
    
    private int AdditionalArray(int[][] matrix, int k)
    {
        var m = matrix.Length;
        var n = matrix[0].Length;
        var visited = new bool[m,n];
        var q = new Queue<int[]>();
        q.Enqueue(new int[2] {m-1, n-1});
        visited[m-1, n-1] = true;
        var arr = new int[m*n];
        var index = 0;
        while(q.Count > 0)
        {
            var temp = q.Dequeue();
            arr[index++] = matrix[temp[0]][temp[1]];
            if(temp[0]-1 >= 0 && !visited[temp[0]-1, temp[1]])
            {
                visited[temp[0]-1, temp[1]] = true;
                q.Enqueue(new int[2] {temp[0]-1, temp[1]});
            }
            
            if(temp[1]-1 >= 0 && !visited[temp[0], temp[1] - 1])
            {
                visited[temp[0], temp[1] - 1] = true;
                q.Enqueue(new int[2] {temp[0], temp[1] - 1});
            }
        }
        
        return InsertionSort(arr, m, n, k);
        //return BubbleSort(arr, m, n, k);
    }
    
    private int InsertionSort(int[] arr, int m, int n, int k)
    {
        for(var i = 1; i < m*n; i++)
        {
            var key = arr[i];
            var j = i - 1;
            while(j >= 0 && arr[j] < key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            
            arr[j+1] = key;
        }
        
        return arr[m*n - k];
    }
    
    private int BubbleSort(int[] arr, int m, int n, int k)
    {
        for(var i = 0; i < m*n; i++)
        {
            var swapped = false;
            for(var j = m*n-1; j >i; j--)
            {
                if(arr[j-1] < arr[j])
                {
                    var t = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = t;
                    swapped = true;
                }
            }
            
            if(!swapped)
            {
                break;
            }
            
        }
        
        return arr[m*n - k];
    }
}
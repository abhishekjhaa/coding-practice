/*
https://leetcode.com/problems/largest-number/
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
public class Solution {
    public string LargestNumber(int[] nums) {
        /*This is a sorting problem 
        where we compare the individual items and then sort them
        instead here we sort based on composite of "item1" + "item2" > "item2" + "item1" 
        
        In object oriented supported languages we can use Comparator to do this.
        */
        
        var comparer = new IntComparer();
        Array.Sort(nums, comparer);
        if(nums[0] == 0)
        {
            return "0";
        }
		return string.Join("", nums);
    }
    
    public class IntComparer : IComparer {
        public int Compare(object x, object y)
        {
            if(string.Compare((x.ToString() + y.ToString()), (y.ToString() + x.ToString())) < 0)
                return 1;
            else if(string.Compare((x.ToString() + y.ToString()), (y.ToString() + x.ToString())) > 0)
                return -1;
            else 
                return 0;
        }
    }
}

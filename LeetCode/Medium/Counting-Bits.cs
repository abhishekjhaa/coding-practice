/*
https://leetcode.com/problems/counting-bits/
Given an integer num, return an array of the number of 1's in the binary representation of every number in the range [0, num].

 

Example 1:

Input: num = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: num = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= num <= 105
 

Follow up:

It is very easy to come up with a solution with run time O(32n). Can you do it in linear time O(n) and possibly in a single pass?
Could you solve it in O(n) space complexity?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
*/

/*Solution
I know for numbers which are power of 2, the count will be 1 always.
For the rest of the numbers, Can I find a pattern to derive it from the previous calculated values.

Lets look at numbers and their binary repesentation:
1 - 1
2 - 10
3 - 11
4 - 100
5 - 101
6 - 110
7 - 111
8 - 1000
9 - 1001
10- 1010
11- 1011
12- 1100
13- 1101
14- 1110
15- 1111
16- 10000

Each number has certain number of bits, lets say 'x'. For each number,:
Number = Pow(2, x) + (Number - Power(2,x))

Same equation applies for number of bits of 1s a number has. And I already know how many 1s (Number - Power(2,x)) has, so if I know 'x', that is how many bits a number has, I can get the number of 1s in it.

Here is the solution:
*/

public class Solution {
    public int[] CountBits(int num) {
        if (num < 1)
        {
            return new int[1];
        }
        var arr = new int[num+1];
        arr[0] = 0;
        var power = 0;
        for (var i = 1; i <= num; i++)
        {
            if(i == 1 << power)
            {
                arr[i] = 1;
                power++;
            }
            else
            {
                arr[i] = arr[ 1 << (power-1)] + arr[i - (1 << (power-1))];
            }
        }
        
        return arr;
    }
}
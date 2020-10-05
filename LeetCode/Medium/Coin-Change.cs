/*
https://leetcode.com/problems/coin-change/

https://leetcode.com/problems/coin-change/discuss/77368/*Java*-Both-iterative-and-recursive-solutions-with-explanations/81427

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

public class Solution {
    public int CoinChange(int[] coins, int amount) {
        int[] dp = Enumerable.Repeat(amount+1, amount+1).ToArray();
        dp[0] = 0;
        for(var eachAmount = 1; eachAmount < amount+1; eachAmount++)
        {
            foreach(var coin in coins)
            {
                if(eachAmount-coin>=0)
                {
                    dp[eachAmount] = Math.Min(dp[eachAmount-coin]+1, dp[eachAmount]);
                }
            }
        }
        
        return dp[amount] == amount+1 ? -1 : dp[amount];
        
        //if(amount<1) return 0;
        //return helper(coins, amount, new int[amount]);
    }
    
    private int helper(int[] coins, int rem, int[] count) { // rem: remaining coins after the last step; count[rem]: minimum number of coins to sum up to rem
    if(rem<0) return -1; // not valid
    if(rem==0) return 0; // completed
    if(count[rem-1] != 0) return count[rem-1]; // already computed, so reuse
    int min = Int32.MaxValue;
    foreach(int coin in coins) {
        int res = helper(coins, rem-coin, count);
        if(res>=0 && res < min)
            min = 1+res;
    }
    count[rem-1] = (min==Int32.MaxValue) ? -1 : min;
    return count[rem-1];
}
}
/*https://leetcode.com/problems/queue-reconstruction-by-height
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.

*/

public class Solution {
    public int[][] ReconstructQueue(int[][] people) {
        var dictionaryByHeight = new Dictionary<int, List<Tuple<int, int>>>();
        var heightList = new List<int>();
        
        for(var i = 0; i < people.Length; i++)
        {
            var height = people[i][0];
            var kPersonAhead = people[i][1];
            if(dictionaryByHeight.ContainsKey(height))
            {
                var count = 0;
                var listSameHeight = dictionaryByHeight[height];
                while(count < listSameHeight.Count)
                {
                    //Console.WriteLine(height.ToString() + " " + listSameHeight.Count.ToString() + " " + kPersonAhead.ToString() + " " +listSameHeight[count].Item2.ToString());
                    if(kPersonAhead > listSameHeight[count].Item2)
                    {
                        count++;
                        continue;
                    }
                    
                    break;
                }
                (dictionaryByHeight[height]).Insert(count, new Tuple<int, int>(height, kPersonAhead));
            }
            else
            {
                dictionaryByHeight[height] = new List<Tuple<int, int>>{new Tuple<int, int>(height, kPersonAhead)};
            }
            
            heightList.Add(height);
        }
        
        heightList.Sort();
        var result = new List<Tuple<int, int>>();
        for(var i = heightList.Count - 1; i >= 0; i--)
        {
            var listOfPpl = dictionaryByHeight[heightList[i]];
            for(var j = 0; j < listOfPpl.Count; j++)
            {
                //Console.WriteLine(listOfPpl[j].Item2);
                result.Insert(listOfPpl[j].Item2, listOfPpl[j]);
            }
            
            i = i - (listOfPpl.Count - 1);
            
        }
        
        for(var i = 0; i < result.Count; i++)
        {
            people[i][0] = result[i].Item1;
            people[i][1] = result[i].Item2;
        }
        
        return people;
        
    }
}
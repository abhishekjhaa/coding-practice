public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        //return MySolution(s, p);        
        
        return MySlidingWindow(s, p);

    }
    
    private IList<int> MySlidingWindow(string s, string p) {
        int[] frequency = new int[26];
        var pc = p.ToCharArray();
        var sc = s.ToCharArray();
        
        for(var i=0; i < pc.Length; i++)
        {
            frequency[pc[i]-'a'] += 1;
        }
        
        var result = new List<int>();
        var left = 0;
        var right = 0;
        while(right < sc.Length)
        {
            if(frequency[sc[right]-'a'] > 0)
            {
                frequency[sc[right]-'a'] -= 1;
                right++;
                if(right - left == pc.Length)
                {
                    result.Add(left);
                    frequency[sc[left]-'a'] += 1;
                    left += 1;
                }
            }
            else
            {
                if(sc[left] == sc[right])
                {
                    frequency[sc[left]-'a'] += 1;
                    left++;
                    continue;
                }
                
                while(left < right)
                {
                    frequency[sc[left]-'a'] += 1;
                    left++;
                }
                
                if(frequency[sc[left]-'a'] < 1)
                {
                    left++;
                    right++;
                }
            }
        }
        
        return result;
    }
    
    private IList<int> MySolution(string s, string p) {
        var pc = p.ToCharArray();
        var sc = s.ToCharArray();
        var result = new List<int>();
        for(var i = 0; i <= sc.Length-pc.Length; i++)
        {
            var dict = GetMeNewDictionary(pc);
            if(dict.ContainsKey(sc[i]))
            {
                var j = i;
                for(j = i; j < i + pc.Length; )
                {
                    if(dict.ContainsKey(sc[j]))
                    {
                        dict[sc[j]] -= 1;
                        if(dict[sc[j]] == 0)
                        {
                            dict.Remove(sc[j]);
                        }
                        
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(j <= sc.Length && j == (i + pc.Length))
                {
                    result.Add(i);
                    while(j < sc.Length)
                    {
                        if(sc[i] == sc[j])
                        {
                            result.Add(i+1);
                            i++;
                            j++;
                        }
                        else
                        {
                            if(!pc.Contains(sc[j]))
                            {
                                i = j;
                            }
                            break;
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    private Dictionary<char, int> GetMeNewDictionary(char[] pc)
    {
        var visitedp = new Dictionary<char, int>();
        for(var i = 0; i < pc.Length; i++)
        {
            visitedp[pc[i]] = visitedp.GetValueOrDefault(pc[i], 0) + 1;
        }
        
        return visitedp;
    }
}
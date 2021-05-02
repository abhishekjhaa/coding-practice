/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
*/
public class WordDictionary {

    /** Initialize your data structure here. */
    private Tries[] t;
    public WordDictionary() {
        t = new Tries[26];
    }
    
    public void AddWord(string word) {
        var cA =  word.ToCharArray();
        var cT = t;
        var pT = t;
        foreach(var c in cA)
        {
            if(cT == null)
            {
                cT = new Tries[26];
            }
            
            if(cT[(int)(c - 'a')] == null)
            {
                cT[(int)(c - 'a')] = new Tries(c);
            }

            pT = cT;
            cT = cT[(int)(c - 'a')].Next;
        }
        
        pT[(int)(cA[cA.Length - 1] - 'a')].SetLast(true);
    }
    
    public bool Search(string word) {
        var cA =  word.ToCharArray();
        return SearchHelper(cA, 0, t);
    }
    
    private bool SearchHelper(char[] cA, int start, Tries[] cT) {
        var pT = cT;
        if(start >= cA.Length)
        {
            return  false;
        }
        for(var j = start; j < cA.Length; j++)
        {
            if(cA[j] == '.')
            {
                //Console.WriteLine(". Hit");
                for(var i = 0; i < 26; i++)
                {
                    if(cT[i] != null)
                    {
                        //Console.WriteLine(cT[i].CChar.ToString());
                        if(j == cA.Length - 1 && cT[i].IsLast)
                        {
                            return true;
                        }
                        
                        if(SearchHelper(cA, j + 1, cT[i].Next))
                        {
                            return true;
                        }
                    }
                }
                
                return false;
            }
            else
            {
            
                if(cT[(int)(cA[j] - 'a')] == null)
                {
                    return false;
                }

                pT = cT;
                cT = cT[(int)(cA[j] - 'a')].Next;
            }
        }
        
        return pT[(int)(cA[cA.Length - 1] - 'a')].IsLast;
    }
    
    public class Tries 
    {
        public char CChar;
        public Tries[] Next;
        public bool IsLast; 
        public Tries(char c)
        {
            CChar = c;
            Next = new Tries[26];
        }
        
        public void SetLast(bool last)
        {
            IsLast = last;
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.AddWord(word);
 * bool param_2 = obj.Search(word);
 */
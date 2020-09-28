/*
https://leetcode.com/problems/implement-trie-prefix-tree/
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

public class Trie {
    
    private class Node
    {
        public char Letter {get; set;}
        public bool EndsHere {get; set;}
        public Node[] Next {get; set;}
    }
    
    private Node[] trie;

    /** Initialize your data structure here. */
    public Trie() {
        trie = new Node[26];
    }
    
    /** Inserts a word into the trie. */
    public void Insert(string word) {
        var arr = word.ToCharArray();
        var start = trie;
        var prev = start;
        var prevChar = 'A';
        foreach (var c in arr)
        {
            if((start[(int)c - (int)'a']) == null)
            {
                start[(int)c - (int)'a'] = new Node();
                start[(int)c - (int)'a'].Letter = c;
            }
            
            if ((start[(int)c - (int)'a']).Next == null)
            {
                (start[(int)c - (int)'a']).Next = new Node[26];
            }
            
            prev = start;
            prevChar = c;
            start = (start[(int)c - (int)'a']).Next;
        }
        
        if (prevChar != 'A')
        {
            (prev[(int)prevChar - (int)'a']).EndsHere = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    public bool Search(string word) {
        var arr = word.ToCharArray();
        var start = trie;
        var prev = start;
        var prevChar = 'A';
        foreach (var c in arr)
        {
            if(start[(int)c - (int)'a'] == null || start[(int)c - (int)'a'].Letter != c)
            {
                return false;
            }
            
            prev = start;
            prevChar = c;
            start = (start[(int)c - (int)'a']).Next;
        }
        if (prevChar != 'A' && (prev[(int)prevChar - (int)'a']).EndsHere == false)
        {
            return false;
        }
               
        return true;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public bool StartsWith(string prefix) {
        var arr = prefix.ToCharArray();
        var start = trie;
        var prev = start;
        var prevChar = 'A';
        foreach (var c in arr)
        {
            if(start[(int)c - (int)'a'] == null || start[(int)c - (int)'a'].Letter != c)
            {
                return false;
            }
            
            prev = start;
            prevChar = c;
            start = (start[(int)c - (int)'a']).Next;
        }
               
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.Insert(word);
 * bool param_2 = obj.Search(word);
 * bool param_3 = obj.StartsWith(prefix);
 */
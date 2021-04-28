/*
https://leetcode.com/problems/text-justification/
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/

public class Solution {
    public IList<string> FullJustify(string[] words, int maxWidth) {
        //count the no of words that can fit maxwidth
        // if the count of characters of chosen words is less than maxwidth 
            // then determine the spaces required between each word
        // handle the last line differently
        
        var result = new List<string>();
        var startIndex = 0;
        while(startIndex < words.Length)
        {
            var (endIndex, charCount) =  GetWordsToFit(words, startIndex, maxWidth);
            if(endIndex == words.Length - 1 && startIndex != endIndex)
            {
                result.Add(PadLastLineWithSpaces(words, startIndex, maxWidth, endIndex));
            }
            else
            {
                result.Add(PadLineWithSpaces(words, startIndex, maxWidth, endIndex, charCount));
            }
            
            startIndex = endIndex + 1;
        }
        
        return result;
    }
    
    private string PadLastLineWithSpaces(string[] words, int index, int maxWidth, int endIndex)
    {
        var sb = new StringBuilder();
        for(var i = index; i <= endIndex; i++)
        {
            sb.Append(words[i]);
            maxWidth -= (words[i].Length);
            if(maxWidth > 0)
            {
                sb.Append(' ');
                maxWidth--;
            }
        }
        
        if(maxWidth > 0)
        {
            sb.Append(' ', maxWidth);
        }
        
        return sb.ToString();
    }
    
    private string PadLineWithSpaces(string[] words, int index, int maxWidth, int endIndex, int totalCharacterCount)
    {
        var sb = new StringBuilder();
        if(endIndex - index == 0)
        {
            PadWord(sb, maxWidth - words[index].Length, words[index]);
            return sb.ToString();
        }
        
        var spacesRequired = endIndex - index;
        var totalSpaces = maxWidth - totalCharacterCount;
        if(totalSpaces%spacesRequired == 0)
        {
            var spaceAfterEachWord = totalSpaces/spacesRequired;
            PadEachWordEvenly(index, endIndex, spaceAfterEachWord, words, sb);
        }
        else
        {
            var unevenCount = totalSpaces%spacesRequired;
            var spaceAfterEachWord = (totalSpaces-unevenCount)/spacesRequired;
            while(unevenCount > 0)
            {
                PadWord(sb, spaceAfterEachWord+1, words[index++]);
                unevenCount--;
            }
            
            PadEachWordEvenly(index, endIndex, spaceAfterEachWord, words, sb);
        }
        
        return sb.ToString();
    }
    
    private void PadEachWordEvenly(int startIndex, int endIndex, int spaceAfterEachWord, string[] words, StringBuilder sb)
    {
        for(var i = startIndex; i < endIndex; i++)
        {
            PadWord(sb, spaceAfterEachWord, words[i]);
        }

        sb.Append(words[endIndex]);
    }
    
    private void PadWord(StringBuilder sb, int spaceAfterWord, string word)
    {
        sb.Append(word);
        sb.Append(' ', spaceAfterWord);
    }
    
    private Tuple<int, int> GetWordsToFit(string[] words, int i, int maxWidth)
    {
        var sum = 0;
        var charCount = 0;
        while(i < words.Length && sum + words[i].Length <= maxWidth)
        {
            sum += words[i].Length + 1;
            charCount += words[i].Length;
            i++;
        }
        
        return new Tuple<int, int>(i-1, charCount) ;
    }
}
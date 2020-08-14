using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Permutations
{
    using System.Collections;

    class Program
    {
        static void Main(string[] args)
        {
            var result = permute("aba");
            
            foreach (var res in result)
            {
                Console.WriteLine(res);
            }

            Console.Read();
        }

        static public IEnumerable<string> permute(string word)
        {
            if (word.Length > 1)
            {

                char character = word[0];
                foreach (string subPermute in permute(word.Substring(1)))
                {

                    for (int index = 0; index <= subPermute.Length; index++)
                    {
                        string pre = subPermute.Substring(0, index);
                        string post = subPermute.Substring(index);

                        if (post.Contains(character))
                            continue;

                        yield return pre + character + post;
                    }

                }
            }
            else
            {
                yield return word;
            }
        }
    }
}

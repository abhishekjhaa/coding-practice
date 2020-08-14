using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UniqueCharactersInString
{
    using System.Threading;

    class Program
    {
        static void Main(string[] args)
        {
            string exampleString = "xXx";
            UsingDictionary(exampleString);
            UsingArray(exampleString);
            UsingCharacterArray(exampleString);

            Console.ReadLine();
        }

        private static void UsingArray(string exampleString)
        {
            var arrayInts = new int[256];
            int count = 0;

            foreach (char c in exampleString)
            {
                if (arrayInts[c] == 0)
                {
                    arrayInts[c] = c;
                    count++;
                }
            }

            Console.WriteLine("Using Array No of Unique Characters are : " + count);
        }

        private static void UsingDictionary(string exampleString)
        {
            var hashDictionary = new Dictionary<char, int>();
            int count = 0;
            foreach (char t in exampleString)
            {
                if (!hashDictionary.ContainsKey(t))
                {
                    hashDictionary.Add(t, 1);
                    count++;
                }
            }

            Console.WriteLine("Using Dictionary No of Unique Characters are : " + count);
        }

        private static void UsingCharacterArray(string exampleString)
        {
            var distinctChars = new List<char>();
            foreach (char c in exampleString)
                if (!distinctChars.Contains(c))
                    distinctChars.Add(c);

            Console.WriteLine("Using Character Array No of Unique Characters are : " + distinctChars.Count());
        }
    }
}

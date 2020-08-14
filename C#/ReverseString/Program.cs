using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ReverseString
{
    class Program
    {
        static void Main(string[] args)
        {
            const string reverse = "bashful doc dopey grumpy happy sleepy sneezy";
            int length = reverse.Length;
            var s = new StringBuilder(reverse);
            for (int i = 0; i < length; i++)
            {
                s[i] = reverse[length - 1 - i];
            }
            
            Console.WriteLine(s + "\n");

            ReverseWords.Reverse();

            Console.ReadLine();
        }
    }
}

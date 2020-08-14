using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ReverseString
{
    public class ReverseWords
    {
        public static void Reverse()
        {
            string dwarves = "bashful doc dopey grumpy happy sleepy sneezy";
            string sevrawd = String.Join(" ", dwarves.Split(' ').Reverse());
            Console.WriteLine(sevrawd);
        }
    }
}

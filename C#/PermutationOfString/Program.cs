using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PermutationOfString
{
    class Program
    {
        static void Main(string[] args)
        {
            var result = Permutation.Permutations("abcdefghi");
            foreach (var permutation in result)
            {
                Console.WriteLine(permutation);
            }
            Console.WriteLine(result.Count);
            Console.ReadLine();

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var root = new BinaryTree { Left = new BinaryTree { Left = new BinaryTree { Left = null, Right = null, Value = 34 }, 
                Right = new BinaryTree { Left = null, Right = null, Value = 4 }, Value = 18 }, 
                Right = new BinaryTree { Left = new BinaryTree { Left = null, Right = null, Value = 66 }, 
                    Right = new BinaryTree { Left = null, Right = null, Value = 71 }, Value = 1 }, 
                Value = 3 };

            const int searchFor = 75;
            bool search = DepthFirstSearch.DepthFirstSearchMethod(root, searchFor);
            Console.WriteLine("DFS Search is " + search);
            search = DepthFirstSearch.DepthFirstSearchMethod2(root, searchFor);
            Console.WriteLine("DFS2 Search is " + search);
            search = DepthFirstSearch.DepthFirstSearchUsingStacks(root, searchFor);
            Console.WriteLine("DFS Using Stacks Search is " + search);
            search = BreadththFirstSearch.BreadththFirstSearchMethod(root, searchFor);
            Console.WriteLine("BFS Search is " + search);
            Preorder.PreorderTraversal(root);
            Console.WriteLine();
            Inorder.InorderTraversal(root); 
            Console.WriteLine();
            Postorder.PostorderTraversal(root);
            Console.ReadLine();
        }
    }
}

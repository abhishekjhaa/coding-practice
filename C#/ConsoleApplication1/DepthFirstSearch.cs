using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public static class DepthFirstSearch
    {
        private static bool search;

        private static Stack<BinaryTree> stack = new Stack<BinaryTree>();

        public static bool DepthFirstSearchMethod(BinaryTree node, int searchFor)
        {
            if (node != null)
            {
                Console.WriteLine(node.Value);
                if (node.Value == searchFor)
                {
                    search = true;
                }
                else if (search == false)
                {
                    DepthFirstSearchMethod(node.Left, searchFor);
                    DepthFirstSearchMethod(node.Right, searchFor);
                }
            }

            return search;
        }

        public static bool DepthFirstSearchMethod2(BinaryTree node, int searchFor)
        {
            if (node == null)
                return false;
            Console.WriteLine(node.Value);
            if (node.Value == searchFor)
                return true;
            return DepthFirstSearchMethod2(node.Left, searchFor) || DepthFirstSearchMethod2(node.Right, searchFor);
        }

        public static bool DepthFirstSearchUsingStacks(BinaryTree node, int searchFor)
        {
            stack.Push(node);
            while (stack.Count > 0 && search == false)
            {
                node = stack.Pop();
                if (node != null)
                {
                    Console.WriteLine(node.Value);
                    if (node.Value == searchFor)
                    {
                        search = true;
                    }
                    else if (search == false)
                    {
                        stack.Push(node.Right);
                        stack.Push(node.Left);
                    }
                }
            }

            return search;
        }
    }
}

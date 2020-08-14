using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public static class BreadththFirstSearch
    {
        private static bool search;

        static Queue<BinaryTree> queue = new Queue<BinaryTree>();
        public static bool BreadththFirstSearchMethod(BinaryTree node, int searchFor)
        {
            queue.Enqueue(node);
            while (queue.Count > 0 && search == false)
            {
                node = queue.Dequeue();
                if (node != null)
                {
                    Console.WriteLine(node.Value);
                    if (node.Value == searchFor)
                    {
                        search = true;
                    }
                    else if (search == false)
                    {
                        queue.Enqueue(node.Left);
                        queue.Enqueue(node.Right);
                        if (node.Left != null)
                        {
                            Console.Write(node.Left.Value + ", ");
                        }
                        if (node.Right != null)
                        {
                            Console.Write(node.Right.Value);
                        }
                        Console.WriteLine();
                    }
                }
            }

            return search;
        }
    }
}

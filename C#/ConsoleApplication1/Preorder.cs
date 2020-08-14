using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public static class Preorder
    {
        public static void PreorderTraversal(BinaryTree node)
        {
            if (node != null)
            {
                Console.Write(node.Value + ", ");
                PreorderTraversal(node.Left);
                PreorderTraversal(node.Right);
            }
        }
    }
}

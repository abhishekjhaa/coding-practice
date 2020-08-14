using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public static class Inorder
    {
        public static void InorderTraversal(BinaryTree node)
        {
            if (node != null)
            {
                InorderTraversal(node.Left);
                Console.Write(node.Value + ", ");
                InorderTraversal(node.Right);
            }
        }
    }
}

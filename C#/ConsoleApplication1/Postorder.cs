using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public static class Postorder
    {
        public static void PostorderTraversal(BinaryTree node)
        {
            if (node != null)
            {
                PostorderTraversal(node.Left);
                PostorderTraversal(node.Right);
                Console.Write(node.Value + ", ");
            }
        }
    }
}

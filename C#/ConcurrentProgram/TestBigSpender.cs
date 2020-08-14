using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConcurrentProgram
{
    using System.Threading;

    public static class TestBigSpender
    {
        public static void Test()
        {
            var b = new BigSpender();
            b.spendAll();
            if (b.Balance < 0) throw new Exception();
        }
        public static void TestWithMultipleThreads()
        {
            var b = new BigSpender();
            for (int i = 0; i < 5; i++)
                new Thread(b.spendAll).Start();
            if (b.Balance < 0) throw new Exception();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConcurrentProgram
{
    using System.Threading;

    class BigSpender
    {
        public decimal Balance = 100m;

        readonly Random rand = new Random();
        public void spendAll()
        {
            Console.WriteLine("Thread No. " + Thread.CurrentThread.ManagedThreadId);
            while (withdraw((rand.Next(5, 11)))) ;
        }

        private bool withdraw(decimal amount)
        {
            lock (this)
            {
                if (Balance - amount < 0)
                {
                    WriteLineWithThreadId(string.Format("Balance is {0}, unable to withdraw {1}", Balance, amount));
                    return false;
                }

                WriteLineWithThreadId(string.Format("Balance is {0}, withdrawing {1}", Balance, amount));

                Balance -= amount;

                if (Balance < 0) // Can't happen! (famous last words)
                {
                    WriteLineWithThreadId(string.Format("Balance is {0}, this should never happen...", Balance));
                    return false;
                }
            }

            return true;
        }

        private void WriteLineWithThreadId(string format)
        {
            Console.WriteLine("Thread No. " + Thread.CurrentThread.ManagedThreadId + " : " + format);
        }
    }
}

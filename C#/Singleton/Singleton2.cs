using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    public class Singleton2
    {
        private Singleton2()
        {
        }
        private static readonly object syncObj = new object();
        private static Singleton2 instance = null;
        public static Singleton2 Instance
        {
            get
            {
                lock (syncObj)
                {
                    if (instance == null)
                        instance = new Singleton2();
                }
                return instance;
            }
        }
    }
}

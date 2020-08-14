using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    public class Singleton3
    {
        private Singleton3()
        {
        }
        private static object syncObj = new object();
        private static Singleton3 instance = null;
        public static Singleton3 Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (syncObj)
                    {
                        if (instance == null)
                            instance = new Singleton3();
                    }
                }
                return instance;
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Singleton
{
    /*
     * There is a nested private class Nested in the code for Singleton5. When the .NET runtime reaches the
    code of the class Nested, its static constructor is invoked automatically, which creates an instance of type
    Singleton5. The class Nested is used only in the property Singleton5.Instance. Since the nested class is
    defined as private, it is inaccessible outside of the class Singleton5.
    
     * When the get method of Singleton5.Instance is invoked the first time, it triggers execution of the
    static constructor of the class Nested to create an instance of Singleton5. The instance is created only
    when it is necessary, so it avoids the waste associated with creating the instance too early.
     */

    public class Singleton5
    {
        Singleton5()
        {
        }
        public static Singleton5 Instance
        {
            get
            {
                return Nested.instance;
            }
        }
        class Nested
        {
            static Nested()
            {
            }
            internal static readonly Singleton5 instance = new Singleton5();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringValueOrReferenceType
{
    class Program
    {
        static void ValueOrReference(Type type)
        {
            String result = "The type " + type.Name;
            if (type.IsValueType)
                Console.WriteLine(result + " is a value type.");
            else
                Console.WriteLine(result + " is a reference type.");
        }

        /*
         * The variable text references the original
           string outside the method ModifyString because text is not marked as ref or out in the argument list.
           Therefore, the output for text is still “hello”. If the expected output is “world”, we have to mark the
           parameter text with ref or out.
         */

        static void ModifyString(String text)
        {
            text = "world";
        }
        static void Main(string[] args)
        {
            String text = "hello";
            ValueOrReference(text.GetType());
            int intType = 10;
            ValueOrReference(intType.GetType());
            ModifyString(text);
            Console.WriteLine(text);
            Console.ReadLine();
        }
    }
}

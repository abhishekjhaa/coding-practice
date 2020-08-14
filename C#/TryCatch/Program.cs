using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TryCatch
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                CalculateAge(2012, 2010);
            }
            catch (Exception ex)
            {
                if (ex is MyCustomException)
                {
                    Panic();
                }
                else if (ex is ArgumentOutOfRangeException)
                {
                    DoSomething();
                    Console.WriteLine("Exception Occured");
                }
                else
                {
                    //// Throwing exception is important. So that it can bubble up till it can be handeled gracefully.
                    throw;
                }
            }

            Console.ReadLine();
        }

        private static void Panic()
        {
           // Handle the Exception
        }

        private static void DoSomething()
        {
            // Do something
        }

        static int CalculateAge(int yearOfBirth, int currentYear)
        {
            if (yearOfBirth > currentYear)
                throw new ArgumentOutOfRangeException();
            return currentYear - yearOfBirth;
        }
    }

    internal class MyCustomException : Exception
    {
    }
}

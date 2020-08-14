using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OverLappingDates
{
    class Program
    {
        static void Main(string[] args)
        {
            var dateOne = new DateRange
            {
                Start = new DateTime(2015, 02, 10),
                End = new DateTime(2015, 02, 11)
            };
            var dateTwo = new DateRange
            {
                Start = new DateTime(2015, 02, 09),
                End = new DateTime(2015, 02, 11)
            };

            DateOverlap(dateOne, dateTwo);
            Console.Read();
        }

        private static void DateOverlap(DateRange dateOne, DateRange dateTwo)
        {
            if (dateOne.End <= dateTwo.Start || dateOne.Start >= dateTwo.End)
            {
                Console.WriteLine("Dates Don't Overlap");
            }
            else
            {
                Console.WriteLine("Dates Overlap");
            }
        }
    }
}

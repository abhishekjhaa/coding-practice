using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnitTestsUsingFakeObjects
{
    public class FancyCalc
    {
        public decimal CalcFoo(IDataFetcher df)
        {
            var data = df.GetData();
            var result = data.Take(100).Average();
            return result;
        }
    }
}

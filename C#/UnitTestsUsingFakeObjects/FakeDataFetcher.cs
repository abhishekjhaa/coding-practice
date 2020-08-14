using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnitTestsUsingFakeObjects
{
    class FakeDataFetcher : IDataFetcher
    {
        public void Combobulate()
        {
            // Don’t need this method for my unit test
            throw new NotImplementedException();
        }

        // Fake method, returns a fixed list of decimals
        public List<decimal> GetData()
        {
            return new List<decimal> { 1, 2, 3 };
        }

        // Don’t need this property for my unit test
        public bool IsFancy { get; set; }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnitTestsUsingFakeObjects
{
    public interface IDataFetcher
    {
        void Combobulate();
        List<decimal> GetData();
        bool IsFancy { get; set; }
    }
}

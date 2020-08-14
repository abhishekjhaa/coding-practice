using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnitTestsUsingFakeObjects
{
    public class DataFetcher : IDataFetcher
    {
        public void Combobulate()
        {
            #region data intensive combobulation
            // ...
            #endregion
        }

        public List<decimal> GetData()
        {
            var result = new List<Decimal>();
            #region Data-intensive code here
            // ... Might be doing database/service calls over the network
            #endregion
            return result;
        }

        public bool IsFancy { get; set; }
    }
}

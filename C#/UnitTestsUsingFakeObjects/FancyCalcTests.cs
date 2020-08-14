using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools;

namespace UnitTestsUsingFakeObjects
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class FancyCalcTests
    {
        [TestMethod]
        public void FancyCalcTest()
        {
            var fakeDataFetcher = new FakeDataFetcher();
            var fc = new FancyCalc();
            var result = fc.CalcFoo(fakeDataFetcher);
            Assert.IsTrue(result == 2m);
        }
    }
}

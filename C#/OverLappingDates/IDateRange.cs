using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OverLappingDates
{
    public interface IDateRange
    {
        DateTime? Start { get; set; }
        DateTime? End { get; set; }
    }
}

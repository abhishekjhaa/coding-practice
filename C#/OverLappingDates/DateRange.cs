﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OverLappingDates
{
    public class DateRange : IDateRange
    {
        public DateTime? Start { get; set; }

        public DateTime? End { get; set; }
    }
}

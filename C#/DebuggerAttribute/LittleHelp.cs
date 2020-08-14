using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DebuggerAttribute
{
    using System.Diagnostics;

    [DebuggerDisplay("X = {X}, Y = {Y}")]
    public class LittleHelp
    {
        private int x;
        public int X { get { return x; } set { x = value; Y = -value; } }
        public int Y { get; set; }
    }
}

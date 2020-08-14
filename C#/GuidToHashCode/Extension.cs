using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuidToHashCode
{
    public static class Extension
    {
        public static string GetAbsoluteHashCode(this Guid applicationObjectId)
        {
            Guid newGuid;
            var result = Guid.TryParse("6E50ECCD-E4F3-C1E4-AB01-1253A7C24C", out newGuid);
            Console.WriteLine(newGuid);
            if (result)
            {
                return checked(Math.Abs(newGuid.GetHashCode())).IntToString();
            }
            else
            {
                return string.Empty;
            }
        }

        public static string IntToString(this int value)
        {
            return Convert.ToString(value);
        }
    }
}

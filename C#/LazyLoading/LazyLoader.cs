using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LazyLoading
{
    public class LazyLoader
    {
        private List<string> _filenames = null;
        public List<string> GetFileNames
        {
            get
            {
                if (_filenames == null)
                    LoadFileNames();
                return _filenames;
            }
        }
        private void LoadFileNames()
        {
            // Iterate over a folder and obtain some file names
            // time-consuming! Don't call this needlessly!
        }
        // etc...
    }
}

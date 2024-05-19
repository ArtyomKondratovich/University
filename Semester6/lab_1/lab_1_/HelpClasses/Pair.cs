using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_1_.HelpClasses
{
    public class Pair<T,K>(T first, K second)
    {
        public T First { get; set; } = first;
        public K Second { get; set; } = second;
    }
}

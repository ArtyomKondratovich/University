namespace lab_4.HelpClasses
{
    public class Segment
    {
        private readonly double _a;
        private readonly double _b;

        public Segment(double a, double b)
        {
            if (a > b)
            {
                throw new ArgumentOutOfRangeException(nameof(a),"a should be less than b");
            }

            _a = a;
            _b = b;
        }

        public IEnumerable<double> GetNodes(double h)
        {
            var nodes = new List<double>();

            for (var node = _a; node <= _b; node += h)
            {
                nodes.Add(node);
            }

            return nodes;
        }
    }
}

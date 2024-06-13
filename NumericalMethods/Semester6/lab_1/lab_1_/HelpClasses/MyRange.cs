namespace lab_1_.HelpClasses
{
    public class MyRange
    {
        public double A { get; set; }
        public double B { get; set; }

        public MyRange(double a, double b)
        {
            if (a > b)
            {
                throw new InvalidOperationException();
            }

            A = a;
            B = b;
        }

        public List<double> GetEquidistantKnots(int n)
        {
            var knots = new List<double>();
            var step = (B - A) / n;

            for (int i = 0; i <= n; i++)
            {
                knots.Add(A + step * i);
            }

            return knots;
        }

        public List<double> GetChebyshevKnots(int n)
        {
            var knots = new List<double>();

            for (int i = 0; i <= n; i++)
            {
                knots.Add((A + B) / 2 + ((B - A) / 2) * Math.Cos(Math.PI * (2 * i + 1) / (2 * (n + 1))));
            }

            return knots;
        }

        public List<double> GetPoints()
        {
            var knots = new List<double>();
            
            for (var i = 0; i <= 100; i++)
            {
                knots.Add(A + i * (B - A) / 100);
            }

            return knots;
        }
    }
}

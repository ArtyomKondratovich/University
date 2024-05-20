namespace lab_4.HelpClasses
{
    public static class Methods
    {
        public static IEnumerable<double> SolveTrapezoidal(Func<double, double, double> f, Func<double, double, double> dfdu, double a, double b, double h, double u0, double epsilon)
        {
            var x = GetNodes(a, b, h).ToArray();

            double[] u = new double[x.Length];
            u[0] = u0;

            for (int i = 1; i < x.Length; i++)
            {
                double uiPrev = u[i - 1];
                double ui = uiPrev;

                while (Math.Abs(ui - uiPrev).CompareTo(epsilon) <= 0)
                {
                    uiPrev = ui;

                    ui = uiPrev - (uiPrev - u[i - 1] - h / 2 * (f(x[i - 1], u[i - 1]) + f(x[i], uiPrev)))
                        / (1 - h / 2 * dfdu(x[i], uiPrev));
                }

                u[i] = ui;
            }

            return u;
        }

        public static IEnumerable<double> SolveRungeKutta(Func<double, double, double> f, double a, double b, double h, double u0)
        {
            var x = GetNodes(a, b, h).ToArray();

            double[] u = new double[x.Length];
            u[0] = u0;

            for (int i = 1; i < x.Length; i++)
            {
                double xi = x[i - 1];
                double uiPrev = u[i - 1];

                double k1 = h * f(xi, uiPrev);
                double k2 = h * f(xi + h / 3, uiPrev + k1 / 3);
                double k3 = h * f(xi + 2 * h / 3, uiPrev + 2 * k2 / 3);

                double deltaUi = (k1  + 3 * k3) / 4;
                u[i] = uiPrev + deltaUi;
            }

            return u;
        }

        public static IEnumerable<double> SolveAdamsBashforthMoulton(Func<double, double, double> f, double a, double b, double h, double u0)
        {
            var x = GetNodes(a, b, h).ToArray();

            double[] u = new double[x.Length];
            u[0] = u0;


            double[] initialU = SolveRungeKutta(f, a, a + 2 * h, h, u0).ToArray();

            for (int i = 0; i < initialU.Length; i++)
            {
                u[i + 1] = initialU[i];
            }

            for (int i = 2; i < x.Length; i++)
            {
                double xi = x[i - 1];
                double uiPrev = u[i - 1];

                // Predictor step using Adams-Bashforth 3rd order
                double predictor = uiPrev + (h / 12) * (23 * f(xi, uiPrev) - 16 * f(xi - h, u[i - 1]) + 5 * f(xi - 2 * h, u[i - 2]));

                // Corrector step using Adams-Moulton 3rd order
                double corrector = uiPrev + (h / 12) * (5 * f(xi + h, predictor) + 8 * f(xi, uiPrev) - f(xi - h, u[i - 1]));

                u[i] = corrector;
            }

            return u;
        }

        public static IEnumerable<double> GetNodes(double a, double b, double h)
        {
            var nodes = new List<double>();

            for (var node = a; node <= b; node += h)
            {
                nodes.Add(node);
            }

            return nodes;
        }

        public static double ErrorEstimateByRunge(int order, double[] y1, double[] y2)
        {
            var max = 0.0;
            var j = 0;

            for (var i = 0; i < y2.Length; i++, j += 2)
            {
                max = Math.Max(Math.Abs(y1[j] - y2[i]), max);
            }

            return max / (Math.Pow(2, order) - 1);
        }

        public static double ErrorEstimateByAbsoluteDifference(double[] exactValues, double[] methodValues)
        {
            var max = 0.0;

            for (var i = 0; i < exactValues.Length; i++)
            {
                max = Math.Max(Math.Abs(exactValues[i] - methodValues[i]), max);
            }

            return max;
        }
    }
}

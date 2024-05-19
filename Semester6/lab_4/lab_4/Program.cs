using lab_4.HelpClasses;

namespace lab_4
{
    public static class Program
    {
        private static readonly Func<double, double> _exactSolution = (x) => Math.Tan(Math.Pow(x, 3) / 3);

        private static readonly Func<double, double, double> _f = (x, u) => Math.Pow(x, 2) * (Math.Pow(u, 2) + 1);

        private static readonly Func<double, double, double> _dfdu = (x, u) => Math.Pow(x, 2) * 2 * u;

        private const double A = 0;

        private const double B = 1;

        private const double EPSILON = 1e-6;

        static void Main()
        {
            ReportPrinting.PrintTableTitle(10);

            var x = Methods.GetNodes(A, B, 0.1).ToArray();
            var u = x.Select(x => _exactSolution(x)).ToArray();

            var y1_1 = Methods.SolveTrapezoidal(_f,_dfdu, A, B, 0.1, 0, EPSILON).ToArray();
            var y2_1 = Methods.SolveRungeKutta(_f, A, B, 0.1, 0).ToArray();
            var y3_1 = Methods.SolveAdamsBashforthMoulton(_f, A, B, 0.1, 0).ToArray();

            var y1_2 = Methods.SolveTrapezoidal(_f, _dfdu, A, B, 0.2, 0, EPSILON).ToArray();
            var y2_2 = Methods.SolveRungeKutta(_f, A, B, 0.2, 0).ToArray();
            var y3_2 = Methods.SolveAdamsBashforthMoulton(_f, A, B, 0.2, 0).ToArray();

            for (var i = 0; i < x.Length; i++)
            {
                ReportPrinting.PrintTableRow(i, x[i], u[i], y1_1[i], y2_1[i], y3_1[i], 10, 6);
            }

            var maxError_1 = Methods.ErrorEstimateByAbsoluteDifference(u, y1_1);
            var maxError_2 = Methods.ErrorEstimateByAbsoluteDifference(u, y2_1);
            var maxError_3 = Methods.ErrorEstimateByAbsoluteDifference(u, y3_1);

            var rungeError_1 = Methods.ErrorEstimateByRunge(2, y1_1, y1_2);
            var rungeError_2 = Methods.ErrorEstimateByRunge(2, y2_1, y2_2);
            var rungeError_3 = Methods.ErrorEstimateByRunge(2, y3_1, y3_2);


            ReportPrinting.PrintErrorRow("max|u[i] - y[i]|",maxError_1, maxError_2, maxError_3, 10, 6);
            ReportPrinting.PrintErrorRow("runge", rungeError_1, rungeError_2, rungeError_3, 10, 6);
        }
    }
}

using lab_1_.HelpClasses;
using OxyPlot;
using OxyPlot.Series;

namespace lab_1_
{
    public partial class Form1 : Form
    {
        private readonly Function _functions;

        public Form1()
        {
            InitializeComponent();
            _functions = new Function(new MyRange(-3, 3));
        }

        private void SetDefaultFunctions()
        {
            
        }

        public void CalculatePn(int n, int number)
        {
            var function = number switch
            {
                1 => _functions.F1,
                2 => _functions.F2,
                _ => throw new NotSupportedException()
            };

            var name = number switch
            {
                1 => "f1(x)",
                2 => "f2(x)",
                _ => throw new NotSupportedException()
            };

            var knots = _functions.Range.GetEquidistantKnots(n);
            var f = knots.Select(x => function(x)).ToList();

            var matrix = new double[n + 1,n + 1];

            for (var i = 0; i < n + 1; i++)
            {
                matrix[0, i] = f[i];
            }


            for (var i = 1; i < n + 1; i++)
            {
                for (var j = 0; j < n + 1 - i; j++)
                {
                    matrix[i, j] = (matrix[i - 1, j + 1] - matrix[i - 1, j]) / (knots[i + j] - knots[j]);
                }
            }


            var pairs = new List<Pair<double, double>>();
            var dots = _functions.Range.GenerateDots();

            foreach (var dot in dots)
            {
                var sum = 0.0;

                for (var i = 0; i < n + 1; i++)
                {
                    var temp = matrix[i, 0];

                    for (var j = 0; j < i; j++)
                    {
                        temp *= (dot - knots[j]);
                    }

                    sum += temp;
                }

                pairs.Add(new Pair<double, double>(dot, sum));
            }

            DrawLines(pairs, OxyColors.Red, name, function);
        }

        public void CalculateCn(int n, int number)
        {
        
        }

        private void DrawLines(List<Pair<double, double>> values, OxyColor color, string name, Func<double, double> function)
        {
            var line1 = new LineSeries()
            {
                Title = name,
                Color = color,
                StrokeThickness = 1,
                MarkerSize = 2,
                MarkerType = MarkerType.Circle
            };

            foreach (var item in values)
            {
                line1.Points.Add(new DataPoint(item.First, item.Second));
            }

            var myModel = new PlotModel { Title = "" };
            myModel.Series.Add(new FunctionSeries(function, _functions.Range.A, _functions.Range.B, 0.001));
            myModel.Series.Add(line1);
            plotView1.Model = myModel;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            if (f1.Checked)
            {
                f2.CheckState = CheckState.Unchecked;

                CalculatePn(3, 1);


            }

            if (f2.Checked) 
            {
                f1.CheckState = CheckState.Unchecked;

                CalculatePn(3, 2);
            }
        }
    }


}

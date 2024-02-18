namespace lab_1_.HelpClasses
{
    public class Function
    {
        public Func<double, double> F1 = (x) => Math.Sin(x) * Math.Cos(x);
        public  Func<double, double> F2 = (x) => 1 / (1 + 12 * Math.Pow(x, 4));
        public MyRange Range;

        public Function(MyRange range)
        {
            this.Range = range;
        }



    }
}

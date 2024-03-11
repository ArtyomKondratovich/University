namespace lab_1_.HelpClasses
{
    public class Function
    {
        public Func<double, double> F1 = (x) => Math.Sin(Math.Cos(x));
        public  Func<double, double> F2 = (x) => Math.Abs(Math.Abs(x) - 1);
        public MyRange Range;

        public Function(MyRange range)
        {
            this.Range = range;
        }



    }
}

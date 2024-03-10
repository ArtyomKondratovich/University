namespace lab_2_2.HelpClasses
{
    public class Segment
    {
        public double A { get; set; }
        public double B { get; set; }

        public double Length
        {
            get => B - A;
        }

        public Func<double, bool> Belongs 
        { 
            get => (x) => x >= A && x <= B;
        }

        public Segment(double a, double b) {

            if (a >= b)
            {
                throw new InvalidOperationException();
            }

            A = a; 
            B = b;
        }

    }
}

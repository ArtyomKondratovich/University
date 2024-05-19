namespace lab_2_2.HelpClasses
{
    public class Data
    {
        public List<double> Points { get; set; }
        public List<double> Values { get; set; }

        public Data(List<double> points, Func<double, double> func) 
        {
            Points = points;
            Values = points
                .Select(x => func(x))
                .ToList();

        }
    }
}

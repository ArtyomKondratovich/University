namespace lab_2_2.HelpClasses
{
    public static class Extensions
    {
        public static List<double> GetEquidistantNodes(this Segment segment, int n)
        {
            var h = segment.Length / n;

            var nodes = new List<double>();

            for (var i = 0; i <= n; i++) 
            {
                nodes.Add(segment.A + i * h);
            }

            return nodes;
        }

        public static List<double> GetLengthOfThePartitionSegements(this List<double> partition)
        {
            var lengths = new List<double>();

            for(var i = 1;i < partition.Count;i++) 
            {
                lengths.Add(partition[i] - partition[i - 1]);
            }

            return lengths;
        }

        public static List<Segment> GetPartitions(this List<double> x)
        {
            var partitions = new List<Segment>()
            {
                new(-10,-9)
            };

            for (var i = 1; i < x.Count; i++)
            {
                partitions.Add(new(x[i - 1], x[i]));
            }

            return partitions;
        }

        public static double max(this List<double> points)
        {
            var max = 0.0;

            for (var i = 0; i < points.Count; i++) {
                max = Math.Max(max, points[i] / 10);
                points[i] /= 10; ;
            }

            return max;
        }
    }
}

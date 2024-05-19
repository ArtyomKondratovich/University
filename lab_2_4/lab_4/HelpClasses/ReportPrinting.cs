namespace lab_4.HelpClasses
{
    public static class ReportPrinting
    {
        public static void PrintTableTitle(int cellWidth)
        {

            var line = new string('-', 48 + cellWidth * 3);
            cellWidth += 3;
            var formatString = string.Format($"| {{0,3}} | {{1,4}} | {{2, {cellWidth}}} | {{3, {cellWidth}}} | {{4, {cellWidth}}} | {{5, {cellWidth}}} |", "i", "x_i", "точное", "метод 1", "метод 2", "метод 3");

            Console.WriteLine(formatString);
            Console.WriteLine(line);
        }

        public static void PrintTableRow(int i, double x, double exact, double firstMethod, double secondMethod, double thirdMethod, int cellWidth, int precision)
        {
            var doubleString = $"{cellWidth}:e{precision}";

            var formatString = string.Format($"| {{0, 3}} | {{1, 3:f2}} | {{2,{doubleString}}} | {{3,{doubleString}}} | {{4,{doubleString}}} | {{5,{doubleString}}} |",  
                i,
                x,
                exact,
                firstMethod,
                secondMethod,
                thirdMethod);

            var line = new string('-', 48 + cellWidth * 3);
            Console.WriteLine(formatString);
            Console.WriteLine(line);
        }

        public static void PrintErrorRow(string message, double firstError, double secondError, double thirdError, int cellWidth, int precision)
        {
            var tab1 = new string(' ', (28 - message.Length) / 2);

            var tab2 = new string(' ', 28 - message.Length - tab1.Length);

            var line = new string('-', 48 + cellWidth * 3);
            var doubleString = $"{cellWidth}:e{precision}";

            var formatString = string.Format($"|{tab1}{message}{tab2}| {{0, {doubleString}}} | {{1, {doubleString}}} | {{2, {doubleString}}} |", firstError, secondError, thirdError);
            Console.WriteLine(formatString);
            Console.WriteLine(line);
        }
    }
}

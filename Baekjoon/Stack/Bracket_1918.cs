using System;

namespace AlgorithmTest2
{
    class Program
    {
        static bool IsCorrect(string str)
        {
            int count = 0;

            foreach (char ch in str)
            {
                if (ch == '(')
                    count++;
                else
                {
                    if (count <= 0) return false;

                    count--;
                }
            }

            return count == 0;
        }

        static void Main(string[] args)
        {
            var line = Console.ReadLine();
            var n = int.Parse(line);

            while ((n--) != 0)
            {
                Console.WriteLine(IsCorrect(Console.ReadLine()) ? "YES" : "NO");

            }
        }
    }
}

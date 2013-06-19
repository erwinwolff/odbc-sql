using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Newtonsoft.Json;

namespace ConsoleApplication1
{
    class Program
    {
        static string TableSerializer(Dictionary<int, List<string>> list)
        {
            string result = string.Empty;

            List<int> countLetters = new List<int>();

            if (list.Any())
            {
                //get the column count from the first item
                int columns = list[0].Count;
                List<int> columnWidthCount = new List<int>();
                for (int i = 0; i < columns; i++)
                {
                    columnWidthCount.Add(0);
                }


                for (int i = 0; i < columns; i++)
                {
                    int max = 0;
                    foreach (KeyValuePair<int, List<string>> item in list)
                    {
                        if (item.Value[i].Count() > max)
                        {
                            max = item.Value[i].Count();
                        }
                        columnWidthCount[i] = max;
                    }
                }

             

            }
            return result;
        }

        static string JsonSerializer(Dictionary<int, List<string>> list)
        {
            string result = JsonConvert.SerializeObject(list);

            return result;
        }

        static string XmlSerializer(Dictionary<int, List<string>> list)
        {
            string result = string.Empty;

            return result;
        }

        static void Main(string[] args)
        {

            Dictionary<int, List<string>> entries = new Dictionary<int, List<string>>();

            List<string> row = new List<string>() { "one", "two", "three", "four" };
            List<string> row2 = new List<string>() { "FourFourFour", "two", "three", "One" };

            for (int i = 0; i < 25; i++)
            {
                List<string> newrow = new List<string>();
                newrow.AddRange(row);
                entries.Add(i, newrow);
            }

            for (int i = 26; i < 50; i++)
            {
                List<string> newrow2 = new List<string>();
                newrow2.AddRange(row2);
                entries.Add(i, newrow2);
            }

           // Console.Write(JsonSerializer(entries));
            Console.Write(TableSerializer(entries));
            Console.ReadKey();
        }
    }
}

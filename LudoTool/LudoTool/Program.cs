using System;
using System.IO;
using System.Text;
using PhantomGrammar.GrammarCore; // using the dll

namespace LudoTool
{
    class MainClass
    {
        private static GenerationSystem system; // ludoscope's generation system
        private static Symbol container = null; // the container of the current tile


        public static StringBuilder sb = new StringBuilder();

        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            GenerateLevel();
        }

        static void GenerateLevel()
        {
            string file = "input/grammar.lsp";

            system = new GenerationSystem();
            system.OpenFromFile(file);

            // start building the world using the generated expression
            Build(Generate());
            //Generate();
            //system.SaveToFile("out.txt");

        }

        internal static Expression Generate()
        {
            system.Reset(); // readies the system for generating
            system.Execute(); // execute the grammar to get the result

            return system.Output; // return the generated expression
        }

        internal static void Build(Expression expression)
        {
            for (int y = 0; y < expression.Height; y++) // loop through the columns of the tilemap
            {
                for (int x = 0; x < expression.Width; x++) // loop through the rows of the tilemap
                {
                    Symbol symbol = expression.Symbols[x + y * expression.Width]; // the symbol of the current tile
                    //Vector3 position = new Vector3(x, -y, 0); // position of the current tile
                    //BuildContainer(expression, symbol, position);
                    BuildContainer(symbol);
                }
            }

            File.AppendAllText("out.txt", sb.ToString());
        }

        private static void BuildContainer(Symbol symbol)
        {
            switch (symbol.Label) // perform the right action for the found label
            {
                case "ground":
                    // fill ground tiles
                    sb.Append("ground,");
                    break;
                case "wall":
                    // fill wall tiles
                    sb.Append("wall,");
                    break;
                case "spike":
                    // fill spike tiles
                    sb.Append("spike,");
                    break;
                case "enemy":
                    // fill enemy tiles
                    sb.Append("enemy,");
                    break;
                case "pit":
                    // fill pit tiles
                    sb.Append("pit,,");
                    break;
            }
        }
    }
}

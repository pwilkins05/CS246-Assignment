using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//bug 1:  doesn't validate user input
//bug 2:  need a way to exit console app
//TODO:  Add score for total Num wins -- comp vs. player

namespace RockPaperScissors
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Welcome To Rock, Paper, Scissors");
            Console.WriteLine("Would you like to play? Y/N");
            string p = Console.ReadLine();
            while (p.ToUpper() == "Y")
            {
                Console.WriteLine("Please choose Rock(1), Paper(2), or Scissors(3)");
                string s = Console.ReadLine();
                switch (s)
                {
                    case "1":
                        s = "Rock";
                        break;
                    case "2":
                        s = "Paper";
                        break;
                    case "3":
                        s = "Scissors";
                        break;
                }
                Random rand = new Random();
                int comp = rand.Next(1, 4);
                string c = "";
                switch (comp)
                {
                    case 1:
                        c = "Rock";
                        break;
                    case 2:
                        c = "Paper";
                        break;
                    case 3:
                        c = "Scissors";
                        break;
                }
                Console.WriteLine("You have chosen:  {0}", s);
                Console.WriteLine("Computer has chosen:  {0}", c);

                if (c == s)
                    Console.WriteLine("It's a tie!");
                else if (c == "Rock" && s == "Scissors")
                    Console.WriteLine("Computer Wins!");
                else if (c == "Rock" && s == "Paper")
                    Console.WriteLine("You Win!");
                else if (c == "Paper" && s == "Rock")
                    Console.WriteLine("Computer Wins!");
                else if (c == "Paper" && s == "Scissors")
                    Console.WriteLine("You win!");
                else if (c == "Scissors" && s == "Rock")
                    Console.WriteLine("You win!");
                else if (c == "Scissors" && s == "Paper")
                    Console.WriteLine("Computer wins!");
                else
                    Console.WriteLine("Something wacky has happened");

                Console.WriteLine("Would you like to play again? Y/N");
                p = Console.ReadLine();
            }



            Console.ReadLine();
                

        }
    }
}

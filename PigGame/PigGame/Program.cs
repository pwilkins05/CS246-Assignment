using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PigGame
{
    //TODO:  create methods for console to finish the game
    //BUG:  When player rolls a 1, "something wacky happens."
    //TODO:  get rid of repetitive code -- streamline turns in console app
    public class Game
    {
        private int score = 0;
        private int roll;
        Random rand = new Random();


        public Game() { }
        public int Score { get { return score; } }
        public int Roll { get { return roll; } }
        public bool Win { get; set; }
        public int WinningScore { get; set; }

        public int RollDie()
        {
            roll = rand.Next(1,7);
            GetScore(roll);
            return roll;
        }

        public int GetScore(int roll)
        {
                if (roll == 1)
                    score = 0;
                else
                    score += roll;
                return score;
        }

        public bool CheckWin(int score)
        {
            bool w = false;
            if (score >= 50)
                w = true;
            return w;
        }

        public bool PlayerTurn(int roll, int score)
        {
            bool canPlay = true;
            if (roll == 1 || CheckWin(score))
                canPlay = false;
            return canPlay;
        }

        public bool ComputerTurn(int roll, int score)
        {
            int numRolls = 0;
            roll = RollDie();
            GetScore(roll);
            if (roll != 1 && !CheckWin(score) && numRolls < 4)
            {
                roll = RollDie();
                GetScore(roll);
                return true;
            }
            else
                return false;
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            Game player1 = new Game();
            Game player2 = new Game();
            
            Console.WriteLine("Welcome to the Pig Game");
            Console.WriteLine("Score 50 points to win");
            Console.WriteLine("Rolling a 1 will end your turn with a score of 0");
            Console.WriteLine("Would you like to roll?  Y/N");
            string reply = Console.ReadLine();
            while (reply.ToUpper() == "Y" && player1.PlayerTurn(player1.Roll, player1.Score))
            {
                Console.WriteLine("You have chosen to roll.");
                player1.RollDie();
                Console.WriteLine("You have rolled a {0}", player1.Roll);
                Console.WriteLine("Your score is {0}", player1.Score);
                Console.WriteLine("Would you like to roll again? Y/N");
                reply = Console.ReadLine();
                
            }
            if (!player1.PlayerTurn(player1.Roll, player1.Score))
            {
                if (player1.Roll == 1)
                {
                    Console.WriteLine("You rolled a 1.  Tough break");
                }

                else if (player1.CheckWin(player1.Score))
                {
                    Console.WriteLine("You win!");
                    Console.WriteLine("Thank you for playing");
                }
            }
                
            if (reply.ToUpper() == "N")
            {
                Console.WriteLine("Your score that turn was {0}", player1.Score);
                Console.WriteLine("Computer's Turn");
                while (player2.ComputerTurn(player2.Roll, player2.Score))
                {
                    Console.WriteLine("Computer score is {0}", player2.Score);
                    Console.WriteLine("Would you like to roll? Y/N");
                }
            }
            
            else
                Console.WriteLine("Something wacky has happened");
            Console.ReadLine();
        }
    }
}

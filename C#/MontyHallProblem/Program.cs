using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MontyHallProblem
{
    public class Program
    {
        private const int ATTEMPTS = 1000000;

        private static readonly Random random = new Random();

        private static void Main()
        {

            Console.WriteLine("\"Contestant always switches\" wins : " + "{0} / {1}", PlayToWin.Play(true), ATTEMPTS);
            Console.WriteLine("\"Contestant always stays\" wins : " + "{0} / {1}", PlayToWin.Play(false), ATTEMPTS);
            Console.WriteLine("\"Contestant always switches\" wins : " + "{0} / {1}", Play(contestantSwitches: true), ATTEMPTS);
            Console.WriteLine("\"Contestant always stays\" wins : " + " {0} / {1}", Play(contestantSwitches: false), ATTEMPTS);
            Console.ReadKey();
        }

        private static int Play(bool contestantSwitches)
        {
            int wins = 0;
            var doors = new bool[3];
            for (int i = 0; i < ATTEMPTS; i++)
            {
                // Reset the doors
                int winningDoor = random.Next(3);
                for (int j = 0; j < 3; j++) 
                    doors[j] = winningDoor == j;
                
                // Contestant chooses a door
                int chosen = random.Next(3);

                // Monty shows a losing door
                int montyDoor = 0;
                do
                {
                    montyDoor = random.Next(3);
                }
                while (montyDoor == chosen || doors[montyDoor]);
                
                // Which door remains?
                int remainingDoor = 0;
                while (remainingDoor == chosen || remainingDoor == montyDoor)
                    remainingDoor += 1;
                
                // Contestant switches or stays
                if (contestantSwitches) 
                    chosen = remainingDoor;
                
                // Did the contestant win?
                wins += (chosen == winningDoor) ? 1 : 0;
            }

            return wins;
        }
    }
}

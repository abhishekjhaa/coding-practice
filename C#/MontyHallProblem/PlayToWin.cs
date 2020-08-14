using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MontyHallProblem
{
    public static class PlayToWin
    {
        private const int ATTEMPTS = 1000000;

        private static readonly Random random = new Random();
        public static int Play(bool contestantSwitches)
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
                int losingDoor = 0;
                if (winningDoor == chosen)
                {
                    losingDoor = 2 - chosen;
                }
                else
                {
                    AssignDoor(winningDoor, chosen, out losingDoor);
                }


                // Which door remains?
                int remainingDoor = 0;
                if (winningDoor == chosen)
                {
                    AssignDoor(winningDoor, losingDoor, out remainingDoor);
                }
                else
                {
                    remainingDoor = winningDoor;
                }

                // Contestant switches or stays
                if (contestantSwitches)
                {
                    chosen = remainingDoor;
                }

                // Did the contestant win?
                wins += (chosen == winningDoor) ? 1 : 0;
            }

            return wins;
        }

        private static void AssignDoor(int winningDoor, int chosen, out int assignDoor)
        {
            assignDoor = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != winningDoor && j != chosen)
                {
                    assignDoor = j;
                }
            }
        }
    }
}

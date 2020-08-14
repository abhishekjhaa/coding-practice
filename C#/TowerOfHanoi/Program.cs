using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TowerOfHanoi
{
    class Tower : Stack<int>
    {
        public string Name { get; set; }
        public Tower(string name)
        {
            Name = name;
        }
    }

    class Program
    {
        static Tower A = new Tower("Tower A");
        static Tower B = new Tower("Tower B");
        static Tower C = new Tower("Tower C");
        
        static void Main(string[] args)
        {
            const int numberOfDisks = 5;
            for (int i = numberOfDisks; i > 0; i--)
                A.Push(i);
            visualizeTowers();
            hanoi(numberOfDisks, from: A, to: C, intermediate: B);
            Console.ReadKey();
        }

        /*
        * In general, to move three disks from A to C you first need to move
        two disks from A to B before you can move the third disk. After you
        have moved the third disk then you can move the two disks from B
        to C
        
        * You can generalize from these simple cases that to move n disks
        from A to C you first need to move n − 1 disks from A to B, then
        move disk n, and finally move n − 1 disks from B to C.
        */

        static void hanoi(int x, Tower from, Tower to, Tower intermediate)
        {
            if (x == 0) return;
            hanoi(x - 1, from, intermediate, to);
            move(x, from, to);
            hanoi(x - 1, intermediate, to, from);
        }

        static void move(int n, Tower from, Tower to)
        {
            Console.WriteLine(string.Format("Move disk {0} from {1} to {2}", n, from.Name, to.Name));
            int x = from.Pop();
            to.Push(x);
            visualizeTowers();
        }
        static void visualizeTowers()
        {
            foreach (Tower t in new List<Tower> { A, B, C })
            {
                Console.WriteLine(t.Name + ":");
                foreach (int i in t.ToArray())
                {
                    for (int j = 1; j <= i; j++)
                        Console.Write('-');
                    Console.WriteLine();
                }
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Threading;

namespace CMPE312_Lab_Work_Q1
{
    class Program
    {

        class Container
        {
            // A container class acts as a generic holder. Define a list to hold fibonacci numbers.
            public static List<int> fibseries = new List<int>();
            //In all methods below, we can reach this list by using Container.fibseries
        }

        public static void CreateFibSeries()
        //This method is used to create a list including first 10 elements of fibonacci series
        {
            int i;
            //Add first to elements of fibonacci series 0 and 1 to the list.
            Container.fibseries.Add(0);
            Container.fibseries.Add(1);
            //Starting from 2nd index, insert the other elements of fibonacci in the list.
            for (i = 2; i < 10; ++i)
                Container.fibseries.Insert(i, Container.fibseries[i - 1] + Container.fibseries[i - 2]);
        }

        public static void thread1()//first thread
        {
            CreateFibSeries();
            Console.Write("Fibonacci Series: ");
            for(int i = 0; i < 10; i++)
            {
                Console.Write(Container.fibseries[i] + " ");
                Thread.Sleep(500);
            }
            Console.WriteLine();
            /*    
            Call the method to create a list of Fibonacci elements: CreateFibSeries();
            Output the content of the list. (wait for half a second (0.5 seconds) before showing each element on the Console)
            */
        }

        public static void thread2()//second thread
        {
            for(int i = 0; i < 4; i++)
            {
                int temp = Container.fibseries[i];
                Container.fibseries[i] = Container.fibseries[9 - i];
                Container.fibseries[9 - i] = temp;
            }
            Console.Write("Reversed: ");
            for (int i = 0; i < 10; i++)
            {
                Console.Write(Container.fibseries[i] + " ");
                Thread.Sleep(500);
            }
            /*
            Reverse the content of list.
            Output the reversed content of the list. (wait for half a second before showing each element on the Console)
            */
        }

        static void Main(string[] args)
        {
            Thread t1 = new Thread(thread1);
            Thread t2 = new Thread(thread2);
            t1.Start();
            Thread.Sleep(TimeSpan.FromSeconds(10));
            t2.Start();
            /*
            Create two threads as t1 and t2 to run methods thread1 and thread2, respectively. Start t1. Then, suspend the main thread for 10 seconds (In other words, your program will wait for 10 seconds). After that, start t2.
            */
        }

    }//end of class program

}

using System;
using System.Threading;


class Program
{
    static void ThreadFunc() {
        Console.WriteLine("Thread! ");
    }        

    static void Main(string[] args)
    {
        //paraméterhez: ParameterizedThreadStart
        Thread t = new Thread(new ThreadStart(ThreadFunc));
        t.Start();



        t.Join();
    }
}

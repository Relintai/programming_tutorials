using System;
using System.Threading;

class Program
{
    private static Semaphore semaphore = Semaphore(0, 3);

    public static void ThreadFunc() {
        //levesz
        semaphore.WaitOne();

        //visszaad
        semaphore.Release(1);
    }

    static void Main(string[] args)
    {
        Console.WriteLine("Hello World!");
    }
}


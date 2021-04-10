using System;
using System.Threading;

class Program
{
    private static Mutex mut = new Mutex();

    static void ThreadFunc() {
        if (mut.WaitOne()) {

            mut.ReleaseMutex();
        }

        if (mut.WaitOne(1000)) {
            //megkaptuk

            Thread.Sleep(1000);

            mut.ReleaseMutex();
        } else {
            //timeout
        }
    }

    ~Program() {
        //nem ajánlott a destruktor c#ban, mert nem garantált, hogy le fog futni
        //mut.Dispose();
    }

    static void Main(string[] args)
    {
        Console.WriteLine("Hello World!");

        mut.Dispose();
    }


}

using System;
using System.Threading;


class Program
{
    static ReaderWriterLock rwl = new ReaderWriterLock();


    static void Main(string[] args)
    {
        try {
            rwl.AcquireReaderLock(1000);

            //rwl.ReleaseReaderLock();

            try {
                //...
            }
            finally {
                rwl.ReleaseReaderLock();
            }
        } catch (Exception ex) {

        }

        try {
            rwl.AcquireWriterLockLock(1000);

            rwl.ReleaseWriterLock();
        } catch (Exception ex) {

        }
    }
}


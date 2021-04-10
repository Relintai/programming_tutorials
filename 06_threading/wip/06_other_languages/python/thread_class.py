import threading
import time

class MyThread(threading.Thread):
    def __init__(self, threadID, name):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name

    def run(self):
        print("t: " + self.name + " " + str(self.threadID))

th1 = MyThread(1, "t1")
th2 = MyThread(2, "t2")

th1.start();
th2.start();

th1.join();
th2.join();
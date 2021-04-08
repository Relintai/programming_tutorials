import threading
import time

def thread_func(threadName, delay):
    print("a " + threadName)
    time.sleep(delay)
    print("b " + threadName)


threads = list()
for i in range(10):
    x = threading.Thread(target=thread_func, args=("A", 0.25))
    x.start()

    threads.append(x)

for t in threads:
    t.join()





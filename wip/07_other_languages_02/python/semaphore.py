import threading
import time

sem = threading.Semaphore()

def fun1():
    sem.acquire()
    #munka
    sem.release()
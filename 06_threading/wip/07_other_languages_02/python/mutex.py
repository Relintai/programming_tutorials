from threading import Thread, Lock

mutex = Lock()

def processData(data):
    mutex.acquire()
    #munka
    print('Do some stuff')
    mutex.release()

    #alternatíva
    mutex.acquire()

    try:
        print('Do some stuff')
        #munka
        pass
    finally:
        mutex.release()


    #alternatíva 2
    with mutex:
        print('Do some stuff')
        #munka
        pass

for i in range(10):
    t = Thread(target=processData, args=(1,))

    t.start()
    
    
#join()...



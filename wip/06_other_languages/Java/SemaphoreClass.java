
import java.util.concurrent.Semaphore;

class SemaphoreClass {
    private final Semaphore sem = new Semaphore(1);

    public void test() {
        //ez állítja meg a threadet
        sem.acquire();

        //ez ad egy futást hozzá
        sem.release();
    }
}

class SemaphoreLimit {
    private final Semaphore sem = new Semaphore(15, true);

    public void search() {
        sem.acquire();
        //keres
        //így egyszerre csak 15 thread kereshet
        sem.release();
    }
}


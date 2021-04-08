

class JavaThreadsWithExtend extends Thread {


    public void run() {
        try {
            System.out.println(Thread.currentThread().getId());
        } catch (Exception e) {
            System.out.println("ex");
        }
    }
}

class JavaThreadhWithInterface implements Runnable {
    public void run() {
        try {
            System.out.println(Thread.currentThread().getId());
        } catch (Exception e) {
            System.out.println("ex");
        }
    }
}

class JavaThreadingAlapok {

    public static void main(String args[]) {

        for (int i = 0; i < 8; ++i) {
            JavaThreadsWithExtend obj = new JavaThreadsWithExtend();
            obj.start();
        }

        for (int i = 0; i < 8; ++i) {
            Thread obj = new Thread(new JavaThreadhWithInterface());
            obj.start();
        }

        System.out.println("Teszt");
    }
}




class JavaThreadingSync {

    public synchronized void sync_method() {
        System.out.println("mutex");
    }

    public void sync_scope() {

        synchronized (this) {


        }

    }


}
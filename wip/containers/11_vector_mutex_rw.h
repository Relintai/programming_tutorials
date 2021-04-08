
//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

class Vector {
    void* arr;
    int size;
    shared_mutex m;

    Vector() {
        size = 0;
        arr = nullptr;
    }

    void get(int index) {
        //olvasásra lezár
    }

    void add(void* data) {
        //mutex lezár írásra

        //resize, ha túl kicsi
        //insert

        //mutex kinyit
    }

    void remove() {
        //mutex lezár írásra

         //resize array

         //mutex kinyit
    }
};



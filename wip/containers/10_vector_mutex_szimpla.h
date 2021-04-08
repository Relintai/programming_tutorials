
//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

class Vector {
    void* arr;
    int size;
    mutex m;

    Vector() {
        size = 0;
        arr = nullptr;
    }

    void add(void* data) {
        //mutex lezár

        //resize, ha túl kicsi
        //insert

        //mutex kinyit
    }

    void remove() {
        //mutex lezár

         //resize array

         //mutex kinyit
    }
};





struct Node {
    Node *next;
    void* data;
};

class Stack {
    Node head;

    void push(void* data) {
        Node *node = new Node();
        node->data = data;

        node->next = head.next;
        head.next = node;
    }

    void *pop() {
        Node *node = head.next;

        if (node == nullptr)
            return nullptr;

        void *data = node->data;

        head.next = node->next;

        delete node;

        return data;
    }

};



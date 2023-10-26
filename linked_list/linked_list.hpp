#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() {
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() { // O(n), onde n é a quantidade de elementos.
        return this->size_;
    }
    unsigned int capacitty() {}
    double percent_occupied() {}
    bool insert_at(unsigned int index, int value) {
        if ( index == 0 ){
            this->push_front(value);
            return true;
        }

        if ( index >= this->size_ ){
            this->push_back(value);
            return true;
        }

        int_node* new_node = new int_node;

        int_node* current = this->head;

        for ( unsigned int i = 0; i < index; i++ )
            current = current->next;

        new_node->value = value;
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev = new_node;
        this->size_++;
        return true;

    }

    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        this->size_--;
        return true; // Removeu
    }

    int get_at(unsigned int index) {
        if (index >= this->size_)
            return -1;
        int_node* current = this->head;

        for ( unsigned int i = 0; i < index; i++ )
            current = current->next;

        return current->value;
        
    }
    void clear() {
        // int_node* current = this->head;
        // while (current != this->tail){
        // {
        //     delete current;
        //     currer
        // }
        
    }
    void push_back(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        // this->tail = new_node
        if ( this->head == nullptr )
            this->head = new_node;
        this->tail = new_node;
        this->size_++;
    }

    void push_front(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_++;
    }
    bool pop_back() {
        if ( this->size_ == 0 )
            return false;
        int_node* anterior = this->tail->prev;
        anterior->next = nullptr;
        delete this->tail;
        this->tail = anterior;
        return true;
    }
    bool pop_front() {}

    int front() { // O(1)
        if ( this->size_ > 0 )
            return this->head->value;
        return -1;
    }

    int back() { // O(1)
        if ( this->size_ > 0 )
            return this->tail->value;
        return -1;
    }

    bool remove(int value) {}

    int find(int value) {
        int_node* current = this->head;
        int i = 0;
        while ( current != nullptr ){
            if ( current->value == value )
                return i;
            current = current->next;
        }

        return -1;
    }

    int count(int value) {
        int_node* current = this->head;
        int c = 0;
        while ( current != nullptr ){
            if ( current->value == value )
                c++;
            current = current->next;
        }

        return c;
    }

    int sum() { // O(n), onde n é a quantidade de elementos no vetor
        int_node* current = this->head;
        int sumValues = 0;
        while ( current != nullptr ){
            sumValues += current->value;
            current = current->next;
        }

        return sumValues;
    }
};

#endif // __LINKED_LIST_IFRN__
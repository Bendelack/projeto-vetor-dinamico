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
    unsigned int size() { // O(1)
        return this->size_;
    }

    unsigned int capacitty() { // O(1)
        return this->size_;
    }

    double percent_occupied() { // O(1)
        return 1.0;
    }

    bool insert_at(unsigned int index, int value) { // O(n), onde n é o valor de index.
        if ( index > this->size_ )
            return false;

        if ( index == 0 ) {
            this->push_front(value);
            return true;
        }

        if ( index == this->size_ ) {
            this->push_back(value);
            return true;
        }

        int_node* new_node = new int_node;

        int_node* current = this->head;

        for ( unsigned int i = 0; i < index; i++ ) {
            current = current->next;
        }

        new_node->value = value;
        new_node->next = current;
        new_node->prev = current->prev;
        new_node->next->prev = new_node;
        new_node->prev->next = new_node;

        this->size_++;
        return true;

    }

    bool remove_at(unsigned int index) {  // O(n), onde n é a quantidade de elementos
        if (index >= this->size_)
            return false; // Não removeu
        if ( index == 0 )
            return pop_front();
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

    int get_at(unsigned int index) { // O(n), onde n é a quantidade de elementos
        if (index >= this->size_)
            return -1;
        int_node* current = this->head;

        for ( unsigned int i = 0; i < index; i++ )
            current = current->next;

        return current->value;
        
    }

    void clear() { // O(n), onde n é a quantidade de elementos

        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }

        this->size_ = 0;
        this->head = 0;
        this->tail = 0;
        
    }
    
    void push_back(int value) { // O(1)
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;

        if ( this->head == nullptr )
            this->head = new_node;
        else
            this->tail->next = new_node;
        this->tail = new_node;
        this->size_++;
    }

    void push_front(int value) { // O(1)
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
    
    bool pop_back() { // O(1)
        if ( this->size_ == 0 )
            return false;
        int_node* to_remove = this->tail;
        if ( this->tail->prev != nullptr ){
            this->tail->prev->next = nullptr;
            this->tail = this->tail->prev;
        }
	else
	    this->tail = this->head = nullptr;
        delete to_remove;
        this->size_--;
        return true;
    }

    bool pop_front() { // O(1)
        if ( this->size_ == 0 )
            return false;

        int_node* to_remove = this->head;
        if ( this->head->next != nullptr )
            this->head->next->prev = nullptr;
        this->head = this->head->next;
        delete to_remove;
        this->size_--;
        return true;
    }

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

    bool remove(int value) { // O(n), onde n é a quantidade de elementos
        if ( this->size_ == 0 )
            return false;
        if ( this->head->value == value )
            return this->pop_front();
        if ( this->tail->value == value )
            return this->pop_back();

        int_node* to_remove = this->head;
        while ( to_remove->value != value && to_remove->next != nullptr )
            to_remove = to_remove->next;

        if ( to_remove->value != value )
            return false;

        to_remove->prev->next = to_remove->next;
        to_remove->next->prev = to_remove->prev;

        delete to_remove;
        this->size_--;
        return true;
    }

    int find(int value) { // O(n), onde n é a quantidade de elementos
        int_node* current = this->head;

        for ( unsigned int i = 0; i < this->size_; i++ ){
            if ( current->value == value )
                return i;
            current = current->next;
        }

        return -1;
    }

    int count(int value) { // O(n), onde n é a quantidade de elementos
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

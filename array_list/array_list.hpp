#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
    private:
        int* data;
        unsigned int size_, capacity_;
        void increase_capacity() { // O(n), onde n é a quantidade de elementos no array
            int* new_data = new int[this->capacity_ * 2];
            for (unsigned i = 0; i < this->size_; i++){
                new_data[i] = this->data[i];
            }
            delete [] this->data;
            this->data = new_data;
            this->capacity_ = this->capacity_ * 2;
        }

    public:
        array_list() {
            data = new int[8];
            this->size_ = 0;
            this->capacity_ = 8;
        }

        ~array_list() {
            delete[] data;
        }

        unsigned int size() { //O(1)
            return this->size_;
        }

        unsigned int capacity() { // O(1)
            return this->capacity_;
        }

        double percent_occupied() { // O(1)
            return static_cast<double>(this->size_)/this->capacity_;
        }

        bool insert_at(unsigned int index, int value) { // O(n), onde n é a quantidade de elementos no array
            if ( index > this->size_ )
                return false;

            if ( index == this->size_ ){
                this->push_back(value);
                return true;
            }

            if ( this->size_ == this->capacity_ )
                increase_capacity();

            for ( unsigned int i = this->size_; i > index; i-- )
                this->data[i] = this->data[i-1];
            this->data[index] = value;
            this->size_++;
            return true;
        }

        bool remove_at(unsigned int index) { // // O(n), onde n é a quantidade de elementos no array
            if (index >= this->size_)
                return false;
            for (unsigned i = index + 1; i < this->size_; ++i) {
                this->data[i - 1] = this->data[i];
            }
            this->size_--;
            return true;
        }

        int get_at(unsigned index) { // O(1)
            if ( index >= this->size_ )
                return -1;
            return this->data[index];
        }

        void clear() { // O(1)
            delete [] this->data;
            this->data = new int[8];
            this->size_ = 0;
            this->capacity_ = 8;
        }

        void push_back(int value) { // O(1)
            if (this->size_ == this->capacity_)
                increase_capacity();
            this->data[size_++] = value;
            this->size_++;
        }

        void push_front(int value) { // O(n), onde n é a quantidade elementos do array antes da inserção
            if ( this->size_ == this->capacity_ )
                increase_capacity();
            for ( unsigned int i = this->size_; i > 0; i-- )
                this->data[i] = this->data[i-1];
            this->data[0] = value;
            this->size_++;
        }

        bool pop_back() { // O(1)
            if ( this->size_ == 0 ) 
                return false;
            this->size_--;
            return true;
        }

        bool pop_front() { // O(n), onde n é a quantidade de elementos do array
            if ( this->size_ == 0 )
                return false;

            for ( unsigned i = 1; i < this->size_; i++ )
                this->data[i-1] = this->data[i];
            this->size_--;
            return true;
        }

        int front(){ // O(1)
            if ( this->size_ == 0 )
                return -1;
            return this->data[0];
        }

        int back(){ // O(1)
            if ( this->size_ == 0 )
                return -1;
            return this->data[this->size_ - 1];
        }

        bool remove(int value) { // O(n), onde n é a quantidade de elementos no array
            for ( unsigned i = 0; i < this->size_; i++ )
                if ( this->data[i] == value )
                    return this->remove_at(i);
            return false;
        }

        int find(int value) { // O(n), onde n é a quantidade de elementos do array
            for ( unsigned i = 0; i < this->size_; i++ )
                if ( this->data[i] == value )
                    return i;
            return -1;
        }

        int count(int value) { // O(n), onde n é a quantidade de elementos do array
            int x = 0;
            for ( unsigned i = 0; i < this->size_; i++ )
                if ( this->data[i] == value )
                    x++;
            return x;
        }

        int sum() { // O(n), onde n é a quantidade de elementos do array
            int soma = 0;
            for ( unsigned i = 0; i < this->size_; i++ )
                soma += this->data[i];
            return soma;
        }
};


#endif // __ARRAY_LIST_IFRN__

/*criar métodos que simplifique o uso*/

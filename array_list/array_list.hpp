#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
    private:
        int* data;
        unsigned int size_, capacity_;
        void increase_capacity() { // O(n), onde n é a quantidade de elementos no array
            int* new_data = new int[this->capacity_ * 2]; //criando o novo array com o dobro da capacidade
            for (unsigned i = 0; i < this->size_; i++) // for que percorrerá o array atual
                new_data[i] = this->data[i]; // colocando cada elemento no novo array
            delete [] this->data; // deletando o array antigo
            this->data = new_data; // fazendo o data apontar para o novo array
            this->capacity_ = this->capacity_ * 2; // modificando a capacidade
        }

    public:
        array_list() { // O(1)
            data = new int[8]; // cria um array inicial com capacidade oito
            this->size_ = 0; // define o tamanho igual a zero
            this->capacity_ = 8; // define a capacidade igual oito
        }

        ~array_list() { //O(1)
            delete[] data; // deleta o array
        }

        unsigned int size() { //O(1)
            return this->size_; // retorna o tamanho
        }

        unsigned int capacity() { // O(1)
            return this->capacity_; // retorna a capacidade
        }

        double percent_occupied() { // O(1)
            return static_cast<double>(this->size_)/this->capacity_; // retorna o percentual ocupado
        }

        bool insert_at(unsigned int index, int value) { // O(n), onde n é a quantidade de elementos no array
            if ( index > this->size_ ) // verifica se o índice é maior que o tamanho
                return false; // verdadeiro, retorna falso

            if ( index == this->size_ ){ // verifica se o índece é igual ao tamanho
                this->push_back(value); // se sim, insere no final do array
                return true; // retorna verdadeiro
            }

            if ( this->size_ == this->capacity_ ) // verifica se o tamanho é igual a capacidade
                increase_capacity(); // se sim, aumenta o tamanho

            for ( unsigned int i = this->size_; i > index; i-- ) // percorre o vetor do fim até o índice
                this->data[i] = this->data[i-1]; // deslocada cada elemento, depois o índice, uma casa à direita
            this->data[index] = value; // adiciona o valor no índice
            this->size_++; // aumenta a quantidade de lementos
            return true; // retorna verdadeiro
        }

        bool remove_at(unsigned int index) { // // O(n), onde n é a quantidade de elementos no array
            if (index >= this->size_) // verifica se o índice é maior ou igual à quantidade de elementos
                return false; // se sim, retorna falso
            for (unsigned i = index + 1; i < this->size_; ++i) { // for para percorrer o vetor a partir do índice
                this->data[i - 1] = this->data[i]; // desloca cada elemento uma posição anterior
            }
            this->size_--; // diminui a quantidade de elementos
            return true; // retorna verdadeiro
        }

        int get_at(unsigned index) { // O(1)
            if ( index >= this->size_ ) // verifica se o índice é valor
                return -1; // retorna -1
            return this->data[index]; // retorna o elemento pelo índice
        }

        void clear() { // O(1)
            delete [] this->data; // deleta o array
            this->data = new int[8]; // cria um novo com capacidade igual a oito
            this->size_ = 0; // define tamanho igual a zero
            this->capacity_ = 8; // define capacidade para oito
        }

        void push_back(int value) { // O(1)
            if (this->size_ == this->capacity_) // verifica se a quantidade de elementos é igual a capacidade
                this->increase_capacity(); // aumenta a capacidade, caso verdadeiro
            this->data[this->size_++] = value; // insere o valor no próximo índice válido e aumenta a quantidade
        }

        void push_front(int value) { // O(n), onde n é a quantidade elementos do array antes da inserção
            if ( this->size_ == this->capacity_ ) // verifica se a quantidade de elementos é igual a capacidade
                increase_capacity(); // aumenta a capacidade, caso verdadeiro
            for ( unsigned int i = this->size_; i > 0; i-- ) // perceor o vetor desde o último até o primeiro
                this->data[i] = this->data[i-1]; // deslocada cada elemento uma posição adiante
            this->data[0] = value; // insere o valor na primeira posição
            this->size_++; // aumenta a quantidade de elementos
        }

        bool pop_back() { // O(1)
            if ( this->size_ == 0 ) // verifica se o array está vazio
                return false; // se sim, retorna falso
            this->size_--; // diminui o tamanho
            return true; // retorna verdadeiro
        }

        bool pop_front() { // O(n), onde n é a quantidade de elementos do array
            if ( this->size_ == 0 ) // verifica se o array está vazio
                return false; // se sim, retorna falso

            for ( unsigned i = 1; i < this->size_; i++ ) // for para percorrer o array
                this->data[i-1] = this->data[i]; // desloca cada elemento uma posição anterior
            this->size_--; // diminui o tamanho
            return true; // retorna verdadeiro
        }

        int front(){ // O(1)
            if ( this->size_ == 0 ) // verifica se o array está vazio
                return -1; // se sim, retorna -1
            return this->data[0]; // retorna o primeiro elemento
        }

        int back(){ // O(1)
            if ( this->size_ == 0 ) // verifica se o array está vazio
                return -1; // se sim, retorna -1
            return this->data[this->size_ - 1]; // retorna o primeiro elemento
        }

        bool remove(int value) { // O(n), onde n é a quantidade de elementos no array
            for ( unsigned i = 0; i < this->size_; i++ ) // percorre o vetor
                if ( this->data[i] == value ) // verifica se o valor corresponde ao da posiçãon o vetor
                    return this->remove_at(i); // se sim, remove pela posição
            return false; // retorna false caso não encontre o valor
        }

        int find(int value) { // O(n), onde n é a quantidade de elementos do array
            for ( unsigned i = 0; i < this->size_; i++ ) // percorre o array
                if ( this->data[i] == value ) // verifica se o valor corresponde ao da posição no vetor
                    return i; // retorna o indice
            return -1; // retorna -1 caso não encontre o valor
        }

        int count(int value) { // O(n), onde n é a quantidade de elementos do array
            int x = 0; // define um contador igual a zero
            for ( unsigned i = 0; i < this->size_; i++ ) // percorre o array
                if ( this->data[i] == value ) // verifica se o valor corresponde ao da posição no array
                    x++; // se sim, soma 1 no contador 
            return x; // retorna o contador
        }

        int sum() { // O(n), onde n é a quantidade de elementos do array
            int soma = 0; // define a soma igual a zero
            for ( unsigned int i = 0; i < this->size_; i++ ) // percorre o array
                soma += this->data[i]; // soma o valor
            return soma; // retorna a soma
        }
};


#endif // __ARRAY_LIST_IFRN__

/*criar métodos que simplifique o uso*/

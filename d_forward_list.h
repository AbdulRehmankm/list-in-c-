#include <iostream>
#include"d_node.h"

namespace myar {

    template <typename T>
    class list {
    private:
        dnode<T>* H;
        int n;

    public:
        list() {
            this->H = new dnode<T>;
            this->H->pre = this->H;
            this->H->next = this->H;
            this->n = 0;
        }

        list(const list& other) {
            if (this->H != other.H) {
                if (this->H != nullptr) {
                    this->clear();
                }
                dnode<T>* temp;
                temp = other.H->next;
                while (temp != other.H) {
                    this->push_front(temp->data);
                    temp = temp->next;
                }
            }
        }

        list& operator=(const list& other) {
            if (this != &other) {
                if (!this->empty()) {
                    this->clear();
                }
                dnode<T>* temp;
                temp = other.H->next;
                while (temp != other.H) {
                    this->push_front(temp->data);
                    temp = temp->next;
                }
            }
            return *this;
        }

        ~list() {
            this->clear();
            delete H;
        }

        void push_front(const T& val) {
            dnode<T>* temp;
            temp = new dnode<T>;
            temp->data = val;
            temp->next = this->H->next;
            temp->next->pre = temp;
            this->H->next = temp;
            temp->pre = this->H;
            this->n++;
        }

        void push_back(const T& val) {
            dnode<T>* temp;
            temp = new dnode<T>;
            temp->data = val;
            temp->pre = this->H->pre;
            temp->next = this->H;
            this->H->pre->next = temp;
            this->H->pre = temp;
            this->n++;
        }

        void pop_front() {
            if (this->empty()) {
                throw "list underflow:";
            }
            dnode<T>* temp;
            temp = this->H->next;
            this->H->next = temp->next;
            temp->next->pre = this->H;
            delete temp;
            this->n--;
        }

        void pop_back() {
            if (this->empty()) {
                throw "list underflow:";
            }
            dnode<T>* temp;
            temp = this->H->pre;
            this->H->pre = temp->pre;
            temp->pre->next = this->H;
            delete temp;
            this->n--;
        }

        void clear() {
            while (this->H->next != this->H) {
                dnode<T>* temp;
                temp = this->H->next;
                this->H->next = temp->next;
                temp->next->pre = this->H;
                delete temp;
            }
            n = 0;
        }

        void display() {
            dnode<T>* temp;
            temp = this->H->next;
            while (temp != this->H) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }

        bool empty() {
            return this->H->next == this->H;
        }

        T front() const {
            if (this->empty()) {
                throw "list underflow:";
            }
            return this->H->next->data;
        }

        T back() const {
            if (this->empty()) {
                throw "list underflow:";
            }
            return this->H->pre->data;
        }

        int size() const {
            return this->n;
        }

        class iterator {
        private:
            dnode<T>* ptr;
            friend class list<T>;

        public:
            iterator& operator++() {
                this->ptr = this->ptr->next;
                return *this;
            }

            iterator operator++(int) {
                iterator old = *this;
                ++(*this);
                return old;
            }

            iterator& operator--() {
                this->ptr = this->ptr->pre;
                return *this;
            }

            iterator operator--(int) {
                iterator old = *this;
                --(*this);
                return old;
            }

            T& operator*() const {
                return this->ptr->data;
            }

            T* operator->() const {
                return &this->ptr->data;
            }

            bool operator==(const iterator& rhs) const {
                return this->ptr == rhs.ptr;
            }

            bool operator!=(const iterator& rhs) const {
                return this->ptr != rhs.ptr;
            }
        };

        iterator begin() const {
            iterator it;
            it.ptr = this->H->next;
            return it;
        }

        iterator end() const {
            iterator it;
            it.ptr = this->H;
            return it;
        }

        class reverse_iterator {
        private:
            dnode<T>* ptr;
            friend class list<T>;

        public:
            reverse_iterator& operator++() {
                this->ptr = this->ptr->pre;
                return *this;
            }

            reverse_iterator operator++(int) {
                reverse_iterator old = *this;
                ++(*this);
                return old;
            }

            reverse_iterator& operator--() {
                this->ptr = this->ptr->next;
                return *this;
            }

            reverse_iterator operator--(int) {
                reverse_iterator old = *this;
                --(*this);
                return old;
            }

            T& operator*() const {
                return this->ptr->data;
            }

            T* operator->() const {
                return &this->ptr->data;
            }

            bool operator==(const reverse_iterator& rhs) const {
                return this->ptr == rhs.ptr;
            }

            bool operator!=(const reverse_iterator& rhs) const {
                return this->ptr != rhs.ptr;
            }
        };
        reverse_iterator rbegin() const
        {
            reverse_iterator it;
            it.ptr = this->H->pre;
            return it;
        }
        reverse_iterator rend() const
        {
            reverse_iterator it;
            it.ptr = this->H;
            return it;
        }
    };
};
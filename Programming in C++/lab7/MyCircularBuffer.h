//
// Created by Егор Назаров on 11.05.2020.
//

#ifndef LAB7_MYCIRCULARBUFFER_H
#define LAB7_MYCIRCULARBUFFER_H


#include <stdexcept>
#include <iterator>

template <typename T>
class circular_buffer_iterator {
private:
    using self = circular_buffer_iterator<T>;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;
    circular_buffer_iterator(pointer arr, size_t size, size_t pos) :
        pos_(pos)
        , arr_(arr)
        , size_(size)
        {
            ptr_ = arr + pos_;
        };

    circular_buffer_iterator(const circular_buffer_iterator& other) = default;

    self operator++() {
        self i = *this; move_fwd(); return i;
    }
    self operator++(int junk) {
        move_fwd(); return *this;
    }
    self operator--() {
        self i = *this; move_bwd(); return i;
    }
    self operator--(int junk) {
        move_bwd(); return *this;
    }
    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }
    size_t get_pos() {
        return pos_;
    }
    bool operator==(const circular_buffer_iterator& rhs) {
        return this->ptr_ == rhs.ptr_;
    }
    bool operator!=(const circular_buffer_iterator& rhs) {
        return this->ptr_ != rhs.ptr_;
    }
private:
    size_t size_;
    size_t pos_;
    pointer arr_;
    pointer ptr_;
    void move_fwd() {
        if (pos_ + 1 >= size_) {
            ptr_ = arr_;
            pos_ = 0;
        } else {
            ptr_++;
            pos_++;
        }
    }
    void move_bwd() {
        if (pos_ == 0) {
            ptr_ = arr_ + size_ - 1;
            pos_ = size_ - 1;
        } else {
            ptr_--;
            pos_--;
        }
    }
};

template <typename T>
class circular_buffer_const_iterator {
private:
    using self = circular_buffer_const_iterator<T>;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const value_type*;
    using reference         = const value_type&;
    circular_buffer_const_iterator(pointer arr, size_t size, size_t pos) :
            pos_(pos)
            , arr_(arr)
            , size_(size)
    {ptr_ = arr + pos_;}

    self operator++() {
        self i = *this; move_fwd(); return i;
    }
    self operator++(int junk) {
        move_fwd(); return *this;
    }
    self operator--() {
        self i = *this; move_bwd(); return i;
    }
    self operator--(int junk) {
        move_bwd(); return *this;
    }
    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }
    bool operator==(const circular_buffer_const_iterator& rhs) {
        return this->ptr_ == rhs.ptr_;
    }
    bool operator!=(const circular_buffer_const_iterator& rhs) {
        return this->ptr_ != rhs.ptr_;
    }
private:
    size_t size_;
    size_t pos_;
    pointer arr_;
    pointer ptr_;
    void move_fwd() {
        if (pos_ + 1 >= size_) {
            ptr_ = arr_;
            pos_ = 0;
        } else {
            ptr_++;
            pos_++;
        }
    }
    void move_bwd() {
        if (pos_ == 0) {
            ptr_ = arr_ + size_ - 1;
            pos_ = size_ - 1;
        } else {
            ptr_--;
            pos_--;
        }
    }
};


template <typename T>
class MyCircularBuffer {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using iterator = circular_buffer_iterator<T>;
    using const_iterator = circular_buffer_const_iterator<T>;

    enum {default_size=100};
    explicit MyCircularBuffer(size_type capacity = default_size) :
            array_(new value_type[capacity])
            , array_size_(capacity)
            , head_(0)
            , tail_(0)
            , contents_size_(0){};
    MyCircularBuffer(const MyCircularBuffer& other) {
        array_size_ = other.array_size_;
        head_ = other.head_;
        tail_ = other.tail_;
        contents_size_ = other.contents_size_;
        array_ = new value_type[array_size_];
        for (int i = 0; i < other.array_size_; ++i) {
            array_ = other.array_[i];
        }
    }

    MyCircularBuffer& operator=(const MyCircularBuffer& other) {
        if (this == &other) {
            return *this;
        }
        this->array_size_ = other.array_size_;
        this->head_ = other.head_;
        this->tail_ = other.tail_;
        this->contents_size_ = other.contents_size_;
        this->array_ = new value_type[array_size_];
        for (int i = 0; i < other.array_size_; ++i) {
            this->array_ = other.array_[i];
        }
    }

    ~MyCircularBuffer() {
        delete [] array_;
    };
    reference front(){
        return array_[head_];
    }
    const_reference front() const {
        return array_[head_];
    }
    reference back() {
        return array_[tail_];
    }
    const_reference back() const {
        return array_[tail_];
    }
    void clear() {
        head_ = tail_ = contents_size_ = 0;
    }
    [[nodiscard]] bool empty() const {////________
        return false;
    }
    [[nodiscard]] size_type size() const {
        return contents_size_;
    }
    [[nodiscard]] size_type capacity() const {
        return array_size_;
    }
    [[nodiscard]] size_type max_size() const {
        return size_type(-1)/sizeof(value_type);
    }
    void push_front(const value_type &item) {
        if (!contents_size_) {
            array_[tail_] = item;
            ++contents_size_;
        } else if (contents_size_ != array_size_)
        {
            decrement_tail();
            ++contents_size_;
            array_[tail_] = item;
        }
        else {
            decrement_tail();
            decrement_head();
            array_[tail_] = item;
        }
    }
    void push_back(const value_type &item) {
        if (!contents_size_) {
            array_[head_] = item;
            ++contents_size_;
        } else if (contents_size_ != array_size_)
        {
            increment_head();
            ++contents_size_;
            array_[head_] = item;
        }
        else {
            increment_head();
            increment_tail();
            array_[head_] = item;
        }
    }
    void pop_front() {
        increment_tail();
        --contents_size_;
    }
    void pop_back() {
        decrement_head();
        --contents_size_;
    }
    iterator insert(iterator pos, const value_type& item) {
        *pos = item;
    }
    iterator remove(iterator pos) {
        size_type spot = pos.get_pos();
        size_type it = tail_;
        size_type next = it + 1;
        if (next == array_size_) next = 0;
        bool flag = false;
        contents_size_--;
        for (int i = 0; i < contents_size_; ++i) {
            if (!flag && it == spot) {
                flag = true;
                continue;
            }
            if (!flag) {
                it++;
                if (it == array_size_) it = 0;
                next++;
                if (next == array_size_) next = 0;
            } else {
                array_[it] = array_[next];
                it++;
                if (it == array_size_) it = 0;
                next++;
                if (next == array_size_) next = 0;
            }
        }
        decrement_head();
    }
    iterator begin() {
        return circular_buffer_iterator(array_, array_size_, tail_);
    }
    const_iterator begin() const {
        return circular_buffer_const_iterator(array_, array_size_, tail_);
    }
    const_iterator cbegin() const {
        return circular_buffer_const_iterator(array_, array_size_, tail_);
    }
    iterator end() {
        increment_head();
        iterator it = circular_buffer_iterator(array_, array_size_, head_);
        decrement_head();
        return it;
    }
    const_iterator end() const {
        increment_head();
        iterator it = circular_buffer_const_iterator(array_, array_size_, head_);
        decrement_head();
        return it;
    }
    const_iterator cend() const {
        increment_head();
        iterator it = circular_buffer_const_iterator(array_, array_size_, head_);
        decrement_head();
        return it;
    }
    reference operator[](size_type index) {
        if (!index_in_bounds(index)) throw std::runtime_error("Error, index out of bounds!");
        return array_[index];
    }
    const_reference operator[](size_type index) const {
        if (!index_in_bounds(index)) throw std::runtime_error("Error, index out of bounds!");
        return array_[index];
    }
    void resize(size_type size) {
        value_type* tmp = array_;
        array_ = new value_type[size];
        size_type new_array_size_ = size;
        size_type new_tail_ = new_array_size_/2;
        size_type new_head_ = new_array_size_/2;
        size_type it = tail_;
        contents_size_ = std::min(new_array_size_, contents_size_);
        for (int i = 0; i < contents_size_; i++) {
            array_[new_tail_] = tmp[it];
            it++;
            if (it == array_size_) it = 0;
            new_tail_++;
            if (new_tail_ == new_array_size_) new_tail_ = 0;
        }
        delete [] tmp;
        tail_ = new_head_;
        head_ = --new_tail_;
        array_size_ = new_array_size_;
    }
private:
    value_type *array_;
    size_type array_size_;
    size_type head_;
    size_type tail_;
    size_type contents_size_;

    void decrement_tail() {
        if (tail_ == 0) tail_ = array_size_ - 1;
        else --tail_;
    }
    void increment_tail() {
        ++tail_;
        if (tail_ == array_size_) tail_ = 0;
    }
    void decrement_head() {
        if (head_ == 0) head_ = array_size_ - 1;
        else --head_;
    }
    void increment_head(){
        ++head_;
        if (head_ == array_size_) head_ = 0;
    }
    bool index_in_bounds(size_type index) {
        return index < contents_size_;
//        size_type it = tail_;
//        for (int i = 0; i < contents_size_; ++i) {
//            if (index == it)
//                return true;
//            it++;
//            if (it > array_size_) it = 0;
//        }
//        return false;
    }
};



#include "MyCircularBuffer.tpp"

#endif //LAB7_MYCIRCULARBUFFER_H

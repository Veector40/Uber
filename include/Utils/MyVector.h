#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>

template <typename T>
class MyVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    MyVector() : data(nullptr), size(0), capacity(0) { }

    ~MyVector() { delete[] data; }
    
    MyVector(const MyVector& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;

            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[capacity];

            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

        data[size++] = value;
    }

    void remove(const T& value) {
        size_t writeIndex = 0;

        for (size_t i = 0; i < size; ++i) {
            if (data[i] != value) {
                data[writeIndex++] = data[i];
            }
        }

        size = writeIndex;
    }
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }

    // ITERATOR STUFF
    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    const_iterator cbegin() const { return data; }

    iterator end() { return data + size; }
    const_iterator end() const { return data + size; }
    const_iterator cend() const { return data + size; }
};

#endif // MYVECTOR_H

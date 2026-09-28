#include "Stack.h"

// =====================================================
// DynamicStack
// =====================================================

template <typename T>
DynamicStack<T>::DynamicStack(int initialCapacity)
{
    if (initialCapacity <= 0)
        initialCapacity = 10;

    capacity = initialCapacity;
    topIndex = -1;

    data = new T[capacity];
}


template <typename T>
DynamicStack<T>::~DynamicStack()
{
    delete[] data;
}


template <typename T>
void DynamicStack<T>::resize()
{
    capacity *= 2;

    T* newData = new T[capacity];

    for (int i = 0; i <= topIndex; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}


template <typename T>
void DynamicStack<T>::push(const T& value)
{
    if (topIndex + 1 >= capacity)
    {
        resize();
    }

    data[++topIndex] = value;
}


template <typename T>
void DynamicStack<T>::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty");
    }

    topIndex--;
}


template <typename T>
T DynamicStack<T>::top() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty");
    }

    return data[topIndex];
}


template <typename T>
bool DynamicStack<T>::isEmpty() const
{
    return topIndex == -1;
}


template <typename T>
int DynamicStack<T>::size() const
{
    return topIndex + 1;
}


// =====================================================
// LinkedStack
// =====================================================

template <typename T>
LinkedStack<T>::LinkedStack()
{
    topNode = nullptr;
    count = 0;
}


template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (!isEmpty())
    {
        pop();
    }
}


template <typename T>
void LinkedStack<T>::push(const T& value)
{
    Node* newNode = new Node(value, topNode);

    topNode = newNode;
    count++;
}


template <typename T>
void LinkedStack<T>::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty");
    }

    Node* temp = topNode;

    topNode = topNode->next;

    delete temp;

    count--;
}


template <typename T>
T LinkedStack<T>::top() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty");
    }

    return topNode->data;
}


template <typename T>
bool LinkedStack<T>::isEmpty() const
{
    return topNode == nullptr;
}


template <typename T>
int LinkedStack<T>::size() const
{
    return count;
}


// =====================================================
// Instanciation explicite
// =====================================================

template class DynamicStack<char>;
template class DynamicStack<int>;

template class LinkedStack<char>;
template class LinkedStack<int>;
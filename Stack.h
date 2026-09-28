#ifndef STACK_H
#define STACK_H

#include <stdexcept>

// =====================================================
// Macro d'export/import pour la DLL (MSVC)
// =====================================================

#if defined(_WIN32) && defined(STACKDLL_SHARED)
    #ifdef STACKDLL_EXPORTS
        #define STACKDLL_API __declspec(dllexport)
    #else
        #define STACKDLL_API __declspec(dllimport)
    #endif
#else
    #define STACKDLL_API
#endif

// =====================================================
// Pile générique basée sur un tableau dynamique
// =====================================================

template <typename T>
class STACKDLL_API DynamicStack
{
private:
    T* data;
    int capacity;
    int topIndex;

    void resize();

public:
    DynamicStack(int initialCapacity = 10);
    ~DynamicStack();

    void push(const T& value);
    void pop();
    T top() const;

    bool isEmpty() const;
    int size() const;
};


// =====================================================
// Pile générique basée sur une liste chaînée
// =====================================================

template <typename T>
class STACKDLL_API LinkedStack
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& value, Node* nextNode = nullptr)
            : data(value), next(nextNode)
        {
        }
    };

    Node* topNode;
    int count;

public:
    LinkedStack();
    ~LinkedStack();

    void push(const T& value);
    void pop();
    T top() const;

    bool isEmpty() const;
    int size() const;
};


// =====================================================
// Instanciations utilisées par la DLL
// =====================================================

#ifndef STACKDLL_EXPORTS
extern template class DynamicStack<char>;
extern template class DynamicStack<int>;

extern template class LinkedStack<char>;
extern template class LinkedStack<int>;
#endif

#endif
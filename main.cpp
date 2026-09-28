#include <iostream>
#include <string>

#include "Stack.h"
#include "Expression.h"

using namespace std;


// =====================================================
// Test de la pile avec tableau dynamique
// =====================================================

void testDynamicStack()
{
    cout << "\n====================================\n";
    cout << " TEST PILE - TABLEAU DYNAMIQUE\n";
    cout << "====================================\n";

    DynamicStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Push : 10, 20, 30\n";

    cout << "Sommet : "
         << stack.top()
         << endl;

    stack.pop();

    cout << "Pop : 30\n";

    cout << "Nouveau sommet : "
         << stack.top()
         << endl;

    cout << "Taille : "
         << stack.size()
         << endl;
}


// =====================================================
// Test de la pile avec liste chaînée
// =====================================================

void testLinkedStack()
{
    cout << "\n====================================\n";
    cout << " TEST PILE - LISTE CHAINEE\n";
    cout << "====================================\n";

    LinkedStack<int> stack;

    stack.push(100);
    stack.push(200);
    stack.push(300);

    cout << "Push : 100, 200, 300\n";

    cout << "Sommet : "
         << stack.top()
         << endl;

    stack.pop();

    cout << "Pop : 300\n";

    cout << "Nouveau sommet : "
         << stack.top()
         << endl;

    cout << "Taille : "
         << stack.size()
         << endl;
}


// =====================================================
// Test parenthèses
// =====================================================

void testParentheses()
{
    cout << "\n====================================\n";
    cout << " VERIFICATION DES PARENTHESES\n";
    cout << "====================================\n";

    string expressions[] =
    {
        "(x+y)+5",
        "((x+y)*z)",
        "(x+y)+5)+z",
        "((x+y)",
        ")(x+y)"
    };

    for (const string& expression : expressions)
    {
        cout << expression << " -> ";

        if (isBalanced(expression))
        {
            cout << "VALIDE";
        }
        else
        {
            cout << "INVALIDE";
        }

        cout << endl;
    }
}


// =====================================================
// Test infixe -> préfixe
// =====================================================

void testPrefix()
{
    cout << "\n====================================\n";
    cout << " CONVERSION INFIXE -> PREFIXE\n";
    cout << "====================================\n";

    string expressions[] =
    {
        "(A+B)*C",
        "(A+B)*(C-D)",
        "A+B*C"
    };

    for (const string& expression : expressions)
    {
        cout << "Infixe  : " << expression << endl;

        cout << "Prefixe : "
             << infixToPrefix(expression)
             << endl;

        cout << endl;
    }
}


// =====================================================
// Programme principal
// =====================================================

int main()
{
    cout << "============================================\n";
    cout << "     APPLICATION DE LA BIBLIOTHEQUE DLL\n";
    cout << "          PILE GENERIQUE C++\n";
    cout << "============================================\n";

    testDynamicStack();

    testLinkedStack();

    testParentheses();

    testPrefix();

    cout << "\n============================================\n";
    cout << "              FIN DU PROGRAMME\n";
    cout << "============================================\n";

    return 0;
}
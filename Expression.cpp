#include "Expression.h"
#include "Stack.h"

#include <algorithm>
#include <cctype>

using namespace std;


// =====================================================
// Priorité des opérateurs
// =====================================================

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}


// =====================================================
// Vérification des parenthèses
// =====================================================

bool isBalanced(const string& expression)
{
    LinkedStack<char> stack;

    for (char c : expression)
    {
        if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            if (stack.isEmpty())
            {
                return false;
            }

            stack.pop();
        }
    }

    return stack.isEmpty();
}


// =====================================================
// Conversion infixe -> préfixe
// =====================================================

string infixToPrefix(const string& expression)
{
    string reversed = expression;

    // 1. Inversion
    reverse(reversed.begin(), reversed.end());

    // 2. Inversion des parenthèses
    for (char& c : reversed)
    {
        if (c == '(')
        {
            c = ')';
        }
        else if (c == ')')
        {
            c = '(';
        }
    }

    LinkedStack<char> operators;

    string result;

    // 3. Parcours de l'expression
    for (char c : reversed)
    {
        // Opérande
        if (isalnum(static_cast<unsigned char>(c)))
        {
            result += c;
        }

        // Parenthèse ouvrante
        else if (c == '(')
        {
            operators.push(c);
        }

        // Parenthèse fermante
        else if (c == ')')
        {
            while (!operators.isEmpty() &&
                   operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }

            if (!operators.isEmpty())
            {
                operators.pop();
            }
        }

        // Opérateur
        else if (c == '+' ||
                 c == '-' ||
                 c == '*' ||
                 c == '/')
        {
            while (!operators.isEmpty() &&
                   operators.top() != '(' &&
                   precedence(operators.top()) >
                   precedence(c))
            {
                result += operators.top();
                operators.pop();
            }

            operators.push(c);
        }
    }

    // 4. Vider la pile
    while (!operators.isEmpty())
    {
        result += operators.top();
        operators.pop();
    }

    // 5. Inverser le résultat
    reverse(result.begin(), result.end());

    return result;
}
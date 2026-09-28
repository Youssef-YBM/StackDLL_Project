#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

#include "Stack.h"

// Vérification des parenthèses
STACKDLL_API bool isBalanced(const std::string& expression);

// Conversion infixe -> préfixe
STACKDLL_API std::string infixToPrefix(const std::string& expression);

#endif
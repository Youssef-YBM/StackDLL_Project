#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

// Vérification des parenthèses
bool isBalanced(const std::string& expression);

// Conversion infixe -> préfixe
std::string infixToPrefix(const std::string& expression);

#endif
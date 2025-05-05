#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <stack>

class RPN
{
    private:
        std::stack<int> stack;

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(const std::string &input);
        bool isOperator(char c) const;
        bool isDigit(char c) const;
        bool executeOperation(char oper);
};

#endif
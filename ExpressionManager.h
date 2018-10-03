#pragma once
#include "ExpressionManagerInterface.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class ExpressionManager: public ExpressionManagerInterface{
    public:
    ExpressionManager() {}
    ~ExpressionManager() {}
    
	bool isBalanced(string expression);
	bool isPair(string a, string b);
	string postfixToInfix(string postfixExpression);
	string postfixEvaluate(string postfixExpression);
	string infixToPostfix(string infixExpression);
	
	protected:
	stack<int> evaluateStack;
	stack<char> ptoiStack;
	string inExpression;
	string evalAns;
	string newPostfix;
};
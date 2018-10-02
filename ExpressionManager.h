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
	string postfixToInfix(string postfixExpression);
	string postfixEvaluate(string postfixExpression);
	string infixToPostfix(string infixExpression);
	
	protected:
	stack<char> balancedStack;
	char x;
	string inExpression;
	string newInfix;
	string newPostfix;
};
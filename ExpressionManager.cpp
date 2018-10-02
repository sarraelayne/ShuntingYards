#include"ExpressionManager.h"
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
	
bool ExpressionManager::isBalanced(string expression) {
    if (expression.length() <= 1) {
        return false;
    }
    for (int i = 0; i < expression.length(); i++) { //creates stack
        if (expression.at(i) == '('||expression.at(i) == '[' || expression.at(i) == '{') {
            balancedStack.push(expression.at(i));
        }
        else if (expression.at(i) == ')'||expression.at(i) == ']' || expression.at(i) == '}') {
            switch(expression.at(i)) {
            case ')': 
                x = balancedStack.top();
                balancedStack.pop();
                if (x == '[' || x == '{') {
                    return false;
                }
                break;
            case ']':
                x = balancedStack.top();
                balancedStack.pop();
                if (x == '(' || x == '{') {
                    return false;
                }
                break;
            case '}':
                x = balancedStack.top();
                balancedStack.pop();
                if (x == '[' || x == '(') {
                    return false;
                }
                break;
            default: 
                return true;
            }
        }
    }
    if (balancedStack.size() != 0) {
        return false;
    }
}
string ExpressionManager::postfixToInfix(string postfixExpression) {
    return inExpression;
}	
string ExpressionManager::postfixEvaluate(string postfixExpression){
    /*istringstream ss(postfixExpression);
	string token;
	vector<string> tokenVector;
	while(getline(ss, token, ' ')) {
	    
		tokenVector.push_back(token);
	}*/
    
    return newInfix;
}
string ExpressionManager::infixToPostfix(string infixExpression){
    return newPostfix;
}
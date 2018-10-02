#include"ExpressionManager.h"
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>
#include<iterator>
#include<cctype>
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
            }
        }
    }
    if (!balancedStack.empty()) {
        return false;
    }
}
string ExpressionManager::postfixToInfix(string postfixExpression) {
    return inExpression;
}	
string ExpressionManager::postfixEvaluate(string postfixExpression){
    //get input
    vector<string> tokens; // everything into vector of strings
    int a;
    int b;
    int size = tokens.size();
    string pfE;
    for (int i = 0; i < size; i++) {
        //strings into int if digit
        string pfE = tokens.at(i);
        //check for operator
        if ((pfE == "+") || (pfE == "-") || (pfE == "*") || (pfE == "/") || (pfE == "%")) {
            int a = evaluateStack.top();
            evaluateStack.pop();
            int b = evaluateStack.top();
            evaluateStack.pop();
            switch (pfE[0]) {
            case '+':
                evaluateStack.push(a + b);
                break;
            case '-':
                evaluateStack.push(a - b);
                break;
            case '*':
                evaluateStack.push(a * b);
                break;
            case '/':
                evaluateStack.push(a / b);
                break;
            case '%':
                evaluateStack.push(a % b);
                break;
            }
        }
        //check for numeric
        else if (!isdigit(pfE)) {
            int num;
            istringstream(pfE) >> num;
            evaluateStack.push(num);
        }
        //check for invalid
        else {
            cout << "invalid expression" << endl;
        }
    }
        evalAns = balancedStack.top();
        cout << "Ans: " << evalAns << endl;
        balancedStack.pop();
    
    return evalAns;
}
string ExpressionManager::infixToPostfix(string infixExpression){
    return newPostfix;
}

//telnet towel.blinkenlights.nl
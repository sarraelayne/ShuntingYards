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
    stringstream ss;
    string myString;
    stack<string> balancedStack;
    ss << expression;
    while (ss >> myString) {
        if (myString == "(" || myString == "[" || myString == "{") {
            balancedStack.push(myString);
        }
        else if (myString == ")" || myString == "]" || myString == "}") {
            if (balancedStack.empty()) {
                return false;
            }
            if(isPair(balancedStack.top(), myString)){
                balancedStack.pop();
            }
            else {
                return false;
            }
        }
    }
    if (!balancedStack.empty()) {
        return false;
    }
    return true;
}
bool ExpressionManager::isPair(string a, string b) {
    if (a == "(" && b == ")") {
        return true;
    }
    else if (a == "[" && b == "]") {
        return true;
    }
    else if (a == "{" && b == "}") {
        return true;
    }
    else {
        return false;
    }
}
string ExpressionManager::postfixToInfix(string postfixExpression) {
    //Split string
    //check for digit
    //check for operator
    //append operators to postfix
    //test for valid postfix
    /*
    
    
    
    */
    return "";
}	
string ExpressionManager::postfixEvaluate(string postfixExpression){
    int a;
    int b;
    int size;
    stringstream ss;
    ss << postfixExpression;
    string pfE;
    while (ss >> pfE) {
        //check for operator
        if ((pfE == "+") || (pfE == "-") || (pfE == "*") || (pfE == "/") || (pfE == "%")) {
            if (evaluateStack.size() < 2) {
                return "invalid";
            }
            cout << "1";
            int a = evaluateStack.top();
            cout << "2";
            evaluateStack.pop();
            cout << "3";
            int b = evaluateStack.top();
            cout << "4";
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
                if (b == 0) {
                    return "invalid";
                }
                evaluateStack.push(a / b);
                break;
            case '%':
                if (b == 0) {
                    return "invalid";
                }
                evaluateStack.push(a % b);
                break;
            }
        }
        //check for numeric
        else if (isdigit(pfE[0])) {
            int num;
            num = stoi(pfE);
            evaluateStack.push(num);
        }
        else {
            cout << "invalid expression" << endl;
        }
    }
    if (evaluateStack.empty()) {
        return "invalid";
    }
    
    return to_string(evaluateStack.top());
}
string ExpressionManager::infixToPostfix(string infixExpression){
    return "";
}

//telnet towel.blinkenlights.nl
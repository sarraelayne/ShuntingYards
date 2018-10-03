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
    stringstream ss;
    ss << postfixExpression; 
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
    double c;
    int size;
    stringstream ss;
    ss << postfixExpression;
    string pfE;
    while (ss >> pfE) {
        //check for operator
        if ((pfE == "+") || (pfE == "-") || (pfE == "*") || (pfE == "/") || (pfE == "%")) {
            if (evaluateStack.size() < 2) {
                return "invalid: too small";
            }
            int a = evaluateStack.top();
            evaluateStack.pop();
            int b = evaluateStack.top();
            evaluateStack.pop();
            switch (pfE[0]) {
            case '+':
                evaluateStack.push(b + a);
                break;
            case '-':
                evaluateStack.push(b - a);
                break;
            case '*':
                evaluateStack.push(b * a);
                break;
            case '/':
                if (a == 0) {
                    return "invalid: div0";
                }
                evaluateStack.push(b / a);
                break;
            case '%':
                if (a == 0) {
                    return "invalid: mod0";
                }
                evaluateStack.push(b % a);
                break;
            }
        }
        //check for numeric
        else if (isdigit(pfE[0])) {
            double num;
            num = stoi(pfE);
            evaluateStack.push(num);
        }
        else {
            cout << "invalid expression" << endl;
        }
    }
    if (evaluateStack.empty()) {
        return "invalid: empty";
    }
    
    return to_string(evaluateStack.top());
}
string ExpressionManager::infixToPostfix(string infixExpression){
    stringstream ss;
    ss << infixExpression; 
    return "";
}

//telnet towel.blinkenlights.nl
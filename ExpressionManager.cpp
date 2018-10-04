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
    istringstream iss(postfixExpression);
    istream_iterator<string> beg(iss), end;
    vector<string> pfVector(beg, end);
    string postfixString = postfixExpression;
    stack<string> operandStack;
    int isDigitCheck;
    
    for (int i = 0; i < postfixExpression.size(); i++) {
        isDigitCheck = atoi(pfVector[i].c_str());
        cout << "isDigitCheck: " << isDigitCheck << endl;
        if (isdigit(isDigitCheck)) {
            cout << "isDigitCheck2: " << isDigitCheck << endl;
            cout << "Pushing: " << pfVector[i] << endl;
            operandStack.push(pfVector[i]);
        }
        else if (pfVector[i] == "+" || pfVector[i] == "-" || pfVector[i] == "*" 
            || pfVector[i] == "/" || pfVector[i] == "%") {
            cout << "size: " << operandStack.size() << endl;
            if (operandStack.size() < 2) {
                return "invalid: too small to convert";
            }
            else {
                string newString;
                
                string o1 = operandStack.top();
                operandStack.pop();
                string o2 = operandStack.top();
                operandStack.pop();
                newString = "( " + o2 + " " + pfVector[i] + " " + o1 + " )";
                cout << "newString: " << newString << endl;
                operandStack.push(newString);
            }
        }
    }
    cout << "top: " << operandStack.top() << endl;
    if (operandStack.size() == 1) {
        postfixString = operandStack.top();
        return postfixString;
    }
    else {
        return "invalid: not valid postfix string";
    }
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
                return "invalid: too small to eval";
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
bool ExpressionManager::process_operator(stack<string> &operatorStack, string &postfixString, string &op) {
    string top = operatorStack.top();
    string currOp = op;
    int opPrecedence;
    
    if (operatorStack.empty() || top == "(" || op == "(") {
        operatorStack(currOp);
        return true;
    }
    else if (currOp == ")") {
        while(operatorStack.top != "(") {
            top = operatorStack.top();
            postfixString.append(top);
            if(operatorStack.empty) {
                return false;
            }
            operatorStack.pop();
        }
        operatorStack.pop();
        return true;
    }
    else {
        if (operatorStack.top == "*" ||operatorStack.top == "/" || operatorStack.top == "%") {
            opPrecedence = 2;
        }
        else if (operatorStack.top == "+" ||operatorStack.top == "-") {
            opPrecedence = 1;
        }
        else {
            opPrecedence = 0;
        }
        while (opPrecedence <= topPrecedence) {
            postfixString.append(operatorStack.top());
        }
    }
}
string ExpressionManager::infixToPostfix(string infixExpression){
    stringstream ss(infixExpression);
    string token;
    string postfixString;
    string op;
    vector<string> tokens;
    stack<string> operatorStack;
    
    while (getline(ss, token, ' ')) {
        
        if(token == "+") || (token == "-") || (token == "*") || (token == "/") || (token == "%")) {
            process_operator(operatorStack, postfixString, op);
            if (process_operator == false) {
                return "error: false operator";
            }
        }
        else if (isdigit(token)) {
            postfixString.append(token);
            postfixString.append(" ");
        }
        else {
            return "string syntax error";
        }
    }
    while (!operatorStack.empty()) {
        op = operatorStack.top();
        operatorStack.pop();
        postfixString.append(op);
        postfixString.append(" ");
    }
    postfixEvaluate(string postfixString);
    if (postfixEvaluate() == true) {
        return postfixString;
    }
    else {
        return "syntax error: not valid";
    }
}

//telnet towel.blinkenlights.nl

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {

    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool balanced(const string& s) {

    stack<char> st;

    for (char c : s) {

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }

        else if (c == ')' || c == ']' || c == '}') {

            if (st.empty() || !isMatching(st.top(), c))
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main() {

    string expression = "{(a+b)*[c-d]}";

    cout << (balanced(expression) ? "Balanced" : "Not balanced");

    return 0;
}

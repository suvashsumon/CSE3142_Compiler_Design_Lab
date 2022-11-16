#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

bool isOperand(char c) {
  if (c >= '0' && c <= '9')
    return true;
  return false;
}

bool isOpeningBracket(char c) {
  if (c == '(')
    return true;
  return false;
}
bool isClosingBracket(char c) {
  if (c == ')')
    return true;
  return false;
}

bool isValidStream(stack<char> &st) {
  bool last = true;
  if (st.empty())
    return false;
  bool ok = false;
  while (st.top() != '(') {
    ok = true;
    char ch = st.top();
    st.pop();
    if (last && isOperator(ch))
      return false;
    last = isOperator(ch);
    if (st.empty())
      return false;
  }
  st.pop();
  return ok;
}
bool isValidString(string str) {
  stack<char> st;

  // i for id
  for (char ch : str) {
    if (isClosingBracket(ch)) {
      if (!isValidStream(st))
        return false;

      if (!st.empty() && !isOperator(st.top()))
        return false;
      st.push('1');
    } else
      st.push(ch);
  }
  bool last = !st.empty();
  while (!st.empty()) {
    char ch = st.top();
    if (isOpeningBracket(ch))
      return false;

    if (last && isOperator(ch))
      return false;
    st.pop();
    last = isOperator(ch);
  }
  return !last;
}

int main() {
  string str;
  cin >> str;
  if(isValidString(str)) cout << "VALID" << endl;
  else cout << "INVALID" << endl;
  return 0;
}
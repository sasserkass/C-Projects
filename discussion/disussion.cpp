#include <iostream>
#include <stack>
using namespace std;

int main() {

  // create a stack of strings
  stack<string> colors;

  // push element into the stack
  colors.push("Blue");
  colors.push("Green");
  colors.push("Purple");
  
  // get top element
  string top = colors.top();

  cout << "Top Element: " << top;
  
  return 0;
}
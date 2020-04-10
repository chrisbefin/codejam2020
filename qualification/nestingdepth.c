#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <string>
using namespace std; // since cin and cout are both in namespace std, this saves some text
int main() {
  int tests;
  cin >> tests; // read t. cin knows that t is an int, so it reads it as such.
  string input, output;
  int depth, current, length;
  for (int i = 1; i <= tests; ++i) {
    cin >> input;
    depth = 0;
    output = "";
    length = input.length();
    for (int k = 0; k < length; k++) {//loop through all numbers of input
      current = input[k] - '0';
      while (current > depth) {//add parentheses to get to correct depth
        output = output + "(";//add parentheses until you arrive at the correct depth
        depth++;
      }
      while (current < depth) {//remove parentheses to get to correct depth
        output = output + ")";
        depth--;
      }
      output = output + input[k];//insert number once parentheses have been added
    }
    while (depth != 0) {
      output = output + ")";
      depth--;
    }
    cout << "Case #" << i << ": " << " " << output << endl;
  }
  return 0;
}

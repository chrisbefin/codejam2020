#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text
string removeStar(string input) {
  string result;
  for (int i = 1; i < input.length(); i++) {
    result = result + input[i];
  }
  return result;
}
int isEndingSubstring(string s1, string s2) {//is s1 a substring of s2
  int M = s1.length();
  int N = s2.length();
  int count = 0;
  for (int i = N - M; i < N; i++) {
    if (s2[i] == s1[count]) {
      count++;
    }
    else return -1;
  }
  return 0;
}

int main() {
  int cases, N;
  cin >> cases; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= cases; i++) {
    cin >> N; // read N.
    string begin = "";
    string end = "";
    string middle = "";
    string current;
    bool flag;
    for (int j = 0; j < N; j++) {//loop through all strings of a test case
      cin >> current;
      flag = false;
      current = removeStar(current);//remove star
      if (end.length() == 0) {
        end = current;
      }
      if (isEndingSubstring(current, end) != -1) continue;//check if current is a substring of end
      if (isEndingSubstring(end,current) != -1) end = current;
      else{//invalid
        flag = true;
        break;
      }
    }
    if (flag == false && end.length()<= 100000) cout << "Case #" << i << ": " << end << endl;
    else cout << "Case #" << i << ": " << "*"<< endl;
  }
  return 0;
}

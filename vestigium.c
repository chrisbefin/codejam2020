#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text
bool duplicates(int size, int array[]) {
  for (int i = 0; i < size; i++) {
    for (int j = i+1; j < size; j++) {
      if (array[j] == array[i]) return true;
    }
  }
  return false;
}
int main() {
  int inputs, size;
  cin >> inputs; //read in the number of test cases that will be provided
  for (int i = 1; i <= inputs; i++) {
    cin >> size; // read in the size of the matrix
    int square[size][size];
    bool duplicate_rows[size] = {false};//tracks rows with repeated values
    short rows = 0;
    short columns = 0;
    bool duplicate_columns[size] = {false};//tracks columns with repeated values
    int trace = 0;//tracks the sum of the diagonal elements
    for (int j = 0; j < size; j++) {//loop through every row of the matrix
      for (int k = 0; k < size; k++) {//loop through every element in the row
        cin >> square[j][k];//read the element into the array
        if (j==k) trace += square[j][k];//if it a diagonal element add it to the trace sum
      }
    }
    int temp[size];
    for (int z = 0; z < size; z++) {//check all rows for duplicates
      if (duplicates(size,square[z]) == true) rows += 1;//check for duplicate rows
      for (int b = 0; b < size; b++) {//cycle through rows to make fill the temp array
        temp[b] = square[b][z];
      }
      if (duplicates(size,temp) == true) columns += 1;
    }
    cout << "Case #" << i << ": " << trace << " " << rows << " " << columns << endl;
  }
  return 0;
}

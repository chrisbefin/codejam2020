#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

struct activity {
  int start;
  int end;
  int index;
  char person;
};

bool isbusy(bool array[], int start, int end) {
  for (int i = start; i < end; i++) {//check if C has a conflicting event scheduled
    if (array[i] == true) return true;// C cannot take on this task
  }
  for (int i = start; i < end; i++) {//update array to reflect C's new schedule
    array[i] = true;
  }
  return false;//C can take on this task
}

int main() {
  int cases, size, start, end;
  cin >> cases; // read in data
  for (int i = 1; i <= cases; i++) {//loop through all test cases
    cin >> size;//read in number of activities
    char result[size + 1];//will store final answer
    result[size] = '\0';
    struct activity activities[size];//stores info for each activity
    for (int j = 0; j < size; j++) {//loop through all activities in a case
      cin >> start >> end;//read in data
      activities[j].start = start;//initialize structs before sorting
      activities[j].end = end;
      activities[j].index = j;
    }
    bool Cbusy[1440] = {false};//C's schedule
    bool Jbusy[1440] = {false};//J's schedule
    bool impossible_flag = false;
    for (int x = 0; x < size; x++) {
      if (isbusy(Cbusy, activities[x].start, activities[x].end) == true) {
        //C is busy so J must try to do it
        if (isbusy(Jbusy, activities[x].start, activities[x].end) == true) {
          impossible_flag = true;//C and J are busy so it is impossible
        }
        else {
          activities[x].person = 'J';//J can do the task
        }
      }
      else {//C can do the task
        activities[x].person = 'C';
      }
    }
    if (impossible_flag == true) {
      cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
    }
    else {
      for(int c = 0; c < size; c++) {//reorder output to fit original input
        result[activities[c].index] = activities[c].person;
      }
      cout << "Case #" << i << ": " << result << endl;
    }
  }
  return 0;
}

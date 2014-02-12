//Bug: Include string
//BUG: Detailess Comments
//BUG: Incorrect variable Declaration
#include <iostream>

using namespace std;

int main ()
{
  string strangle;
  string base="The quick brown fox jumps over a lazy dog.";

  // used in the same order as described above:

  str.assign(base);
  cout << str << endl;

  str.assign(base,10,9);
  cout << str << endl;         // ""

  str.assign("pangrams are cool",7);
  cout << str << endl;         // ""

  str.assign("c-string");
  cout << str << endl;         // ""

  str.assign(10,'*');
  cout << str << endl;         // ""

  str.assign<int>(10,0x2D);
  cout << str << endl;         // ""

  str.assign(base.begin()+16,base.end()-12);
  cout << str << endl;         // ""

  return 0;
}





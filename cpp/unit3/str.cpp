#include <string>
#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void echo() {
  string s;
  while (getline(cin, s)) cout << s << endl;
}

void echo(string &s) {
  if (s.empty()) {
    cout << "empty" << endl;
  }
  if (s.size() > 5) {
    cout << s << endl;
  }
}

void concatenate() {
  string str, con;
  while (cin >> str) con += str;
  cout << con << endl;
}

void concatenate_spaces() {
  string str, con;
  while (cin >> str) con = con + ' ' + str;
  cout << con << endl;
}

int main() {
  /* init */
  // string s1 = "directly";
  // string s2(10, 'c');
  // // equivalent to copy a string to s3
  // string s3 = string(5, 'd');
  // cout << s1 << endl << s2 << endl << s3 << endl;

  // string s4, s5;
  // cin >> s4 >> s5;
  // cout << s4 << "\t" << s5 << endl;

  // echo();
  concatenate();
  concatenate_spaces();
  return 0;
}
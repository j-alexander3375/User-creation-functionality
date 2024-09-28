#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> areaCodes;
  areaCodes["New York"] = 212;
  areaCodes["Los Angeles"] = 213;
  areaCodes["Chicago"] = 312;
  areaCodes["Dallas"] = 214;

  cout << "The area code for New York is " << areaCodes["New York"] << endl;
};
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> areaCodes;
  areaCodes["New York"] = 212;
  areaCodes["Los Angeles"] = 213;
  areaCodes["Chicago"] = 312;
  areaCodes["Dallas"] = 214;

  for (auto it = areaCodes.begin(); it != areaCodes.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
};
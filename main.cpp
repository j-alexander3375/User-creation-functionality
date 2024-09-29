#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * @brief Encodes a given string to Base64 format.
 * 
 * This function takes an input string and encodes it using the Base64 encoding scheme.
 * Base64 is commonly used to encode binary data as an ASCII string.
 * 
 * @param in The input string to be encoded.
 * @return A Base64 encoded string.
 */
string base64_encode(const string &in) {
  string out;
  int val = 0, valb = -6;
  for (unsigned char c : in) {
    val = (val << 8) + c;
    valb += 8;
    while (valb >= 0) {
      out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
      valb -= 6;
    }
  }
  if (valb > -6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
  while (out.size() % 4) out.push_back('=');
  return out;
}

void saveUser(const string &email, const string &name, const string &password) {
  string encryptedPassword = base64_encode(password);

  ofstream file("users.txt", ios::app);
  if (file.is_open()) {
    file << "Email: " << email << "\n";
    file << "Name: " << name << "\n";
    file << "Password: " << encryptedPassword << "\n";
    file << "--------------------------\n";
    file.close();
  } else {
    cerr << "Unable to open file";
  }
}

int main() {
  string email, name, password;

  cout << "Email: ";
  cin >> email;
  cin.ignore(); // Ignore the newline character left in the buffer
  cout << "Name: ";
  getline(cin, name);
  cout << "Password: ";
  cin >> password;

  saveUser(email, name, password);

  return 0;
}

//now I will begin adding various user interactions and validations to the program
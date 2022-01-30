#include <iostream>
#include <string>
#include "Encryption.h"

int main() {
  std::string testString = "eat my azz man !!@%&*%*&(%#%^";
  Encryption test;
  test.setKey(-1);
  std::cout << "Before Encryption: \t" << testString << '\n';
  testString = test.encrypt(testString);
  std::cout << "After Encryption: \t" << testString << '\n';
  testString = test.decrypt(testString);
  std::cout << "After Decryption: \t" << testString << '\n';
  
}
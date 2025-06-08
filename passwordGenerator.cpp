#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

int main(void) {
  std::string password;
  std::random_device rd;
  std::mt19937 mt(rd());

  std::string dict =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+-*/!@#$&=?";

  std::uniform_int_distribution<> d(0, dict.length());

  int length = 4;
  std::cout << "[*] Password length: ";
  std::cin >> length;

  for (auto i{length}; i; --i)
    password += dict[d(mt)];

  std::ofstream f_out{"password.txt"};
  f_out << password;
  f_out.close();

  std::cout << "[*] Generated password: " << password << std::endl
            << "Saved at `password.txt`" << std::endl;

  return 0;
}

#include <iostream>

#include <boost/version.hpp>

int main(int argc, char** argv)
{
  std::cout << BOOST_VERSION << '\n';

  std::cout << "Aurora Unit Testing\n";
  std::cin.ignore(1000, '\n');
  return 0;
}
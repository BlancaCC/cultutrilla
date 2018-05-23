/**
   @brief Ejemplillo de utilización de comandos de bash en un programa c++
 **/
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  system("ls -l >test.txt");
  system( "rm *~");
  system(" ls $HOME >> test.txt");
  cout << ifstream("test.txt").rdbuf();
}

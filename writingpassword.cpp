#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;




int main () {
  string line;
  std::vector<std::string> lines;
  ifstream MyReadFile ("passwords.txt");

  if (MyReadFile.is_open())
  {
     for (std::string line; std::getline(MyReadFile, line, ':');) 
        {
            lines.push_back(line); //adds to end of the vector

        }
    MyReadFile.close();
  }
  

 /** for (std::string line; std::getline(MyReadFile, line, ':');) 
{
    lines.push_back(line); //adds to end of the vector

}
  else cout << "Unable to open file"; 
    return 0;
    **/
}
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;




int main () {
  string username;
  string passwords;
  std::vector<std::string> usernameVec;
  std::vector<std::string> passwordVec;
  ifstream MyReadFile ("passwords.txt");

  if (MyReadFile.is_open())
  {
     for (std::string username; std::getline(MyReadFile, username, ':');) 
        {
            usernameVec.push_back(username); //adds to end of the username vector
            
        }


        for (std::string password; std::getline(MyReadFile, password);) 
        {
            passwordVec.push_back(password); //adds to end of the password  vector

        }
    MyReadFile.close();



   
  }
  

 /** for (std::string username; std::getline(MyReadFile, username, ':');) 
{
    usernameVec.push_back(username); //adds to end of the vector

}
  else cout << "Unable to open file"; 
    return 0;
    **/
}

#include <iostream>
#include "authlib.h"
#include <fstream>
#include<vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>

using namespace std;

string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main()

{



  string user;

  string userPassword;

  int i = 0;

  bool auth = false;

  int loginAttempt = 0;



  string line;

  std::vector<std::string> lines;

  ifstream MyReadFile("passwords.txt");



  if (MyReadFile.is_open())

  {

    for (std::string line; std::getline(MyReadFile, line, ':');)

    {

      lines.push_back(line); //adds to end of the vector

    }

    MyReadFile.close();

  }



  while (i < sizeof(lines) && auth == false)

  {



    while (loginAttempt < 3)

    {



      cout << "please enter usename: ";



      cin >> user;



      cout << "please enter password: ";



      cin >> userPassword;


      if (user != line)
      { 
        auth == false;
        i++;
      }


      if //stored hash == sha256(userPassword)
      {
        auth = true;
      }

    

      loginAttempt = loginAttempt + 1;

    }



  } 



  //todo read in password when users are correct



  //TODO optional after rest is done salt before hashing



  //todo hash the passwords



  //to do compare passwords



  if (auth)

    authenticated("user");



  //sign in



  else

    rejected("user");



}



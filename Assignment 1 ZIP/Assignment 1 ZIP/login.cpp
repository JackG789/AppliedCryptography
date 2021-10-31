#include <iostream>

#include "authlib.h"

#include <fstream>

#include<vector>

using namespace std;



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



  while (i < sizeof(line) && auth == false)

  {



    while (loginAttempt < 3)

    {



      cout << "please enter usename: ";



      cin >> user;



      cout << "please enter password: ";



      cin >> userPassword;



      auth == true;



      if (user != line)

      { 

        auth == false;

        i++;

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




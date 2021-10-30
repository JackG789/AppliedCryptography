#include <iostream>

#include "authlib.h"

#include <fstream>



using namespace std;



int main() {

  std::string user;

  std::string userPassword;

  std::string storedUserData;

 

  //std::string MyReadFile ="Desktop/passwords.txt";

  int i=0;

  

  bool auth = false;

  int loginAttempt =0;

  //todo read names from file into users array(split might not work)

  

  

  ifstream MyReadFile("passwords.txt");





  if(MyReadFile.is_open()){

  while (getline(MyReadFile, storedUserData)){

   std:: cout << storedUserData;//TODO only usenames read in 

  }



  MyReadFile.close();

  while(i<sizeof(storedUserData)&& auth == false){

    while(loginAttempt < 3){

      std:: cout << "please enter usename: ";

      std::cin >> user;

      std:: cout << "please enter password: ";

     std::cin >> userPassword;

     auth == true;  

      if(  user != storedUserData){ //compare users entered to users from file

         auth == false;     

          i++;

      }

      loginAttempt = loginAttempt +1;

    }   

  } //add to sign in attempt

 //todo read in password when users are correct  

 //TODO optional after rest is done salt before hashing

 //todo hash the passwords 

 //to do compare passwords 

  if (auth) authenticated("user");

 //sign in

  else rejected("user");

  }

  else cout << "unable to open file";

}

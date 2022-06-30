/**************************************************************************
 * Author:
 *    Michael Fisher
 * Project:
 *    Bit calculator for the bit security of a password
 **************************************************************************/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void getPassword(char* password);
void getCombinations(long long int& combinations, const char* password);

/**********************************************
 * main
 **********************************************/
int main()
{ 
   while (true)
   {
      char password[256];
      long long int combinations = 0;

      getPassword(password);

      getCombinations(combinations, password);

      cout << "There are " << combinations << " combinations" << endl;

      cout << "That is equivalent to a key of " << floor(log2(combinations)) << " bits" << endl << endl;

   }

   return 0;
}

/**********************************************
 * getPassword
 * will prompt the user for the password the
 * password and will then return it back to main
 **********************************************/
void getPassword(char* password)
{
   cout << "Please Enter the password: ";
   cin.getline(password, 256);

}

/**********************************************
 * getCombinations
 * Will iterate through the string and will
 * see what the ascii values fall between.
 **********************************************/
void getCombinations(long long int& combinations, const char* password)
{
   bool lowerCase = false;
   bool upperCase = false;
   bool digits    = false;
   bool specailC  = false;
   int size = 0;


   for (int i = 0; password[i]; i++)
   {
      if (97 <= (int)password[i] && (int)password[i] <= 122)
         lowerCase = true;
      
      if (65 <= (int)password[i] && (int)password[i] <= 90)
         upperCase = true;

      if (48 <= (int)password[i] && (int)password[i] <= 57)
         digits = true;
      if ((32 <= (int)password[i] && (int)password[i] <= 47) || 
         (58 <= (int)password[i] && (int)password[i] <= 64) || 
         (91 <= (int)password[i] && (int)password[i] <= 96) || 
         (123 <= (int)password[i] && (int)password[i] <= 127))
         specailC = true;

      size += 1;
   }

   if (lowerCase == true)
      combinations += 26;
   if (upperCase == true)
      combinations += 26;
   if (digits == true)
      combinations += 10;
   if (specailC == true)
      combinations += 32;

   combinations = pow(combinations, size);
}
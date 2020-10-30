#include "functions.h"

int main() 
{
  string option;

  do
  {
    menu();
    
    option = validateString(option);
    userOption(option);

  } while(option != "Q" && option != "q");

  return 0;
}
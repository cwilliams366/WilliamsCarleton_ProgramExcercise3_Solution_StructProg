/*
Name: Carleton Williams II
Student ID: @30328817
Date: April 2nd, 2024
Course: Structures of Programming
Professor: Dr. Linwei Niu
Homework 3: Programming Exercise 3
Assignment: Write and test the code to implement the state diagram of Problem 1.
*/
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include "errors.h"

    //Global Variables
    //Slash Essentials
    int SLASH_ERROR = -1;
    int CLOSE_SLASH_ERROR = -3;
    char  SLASH_ERR_MESSAGE [500] = { "Error! Invalid character entry. Must begin comment with a forward slash character.\n"};
char  CLOSE_SLASH_ERR_MESSAGE [500] = { "Error! Invalid character entry. Must end with the forward slash character.\n"};

    //Asterisk Essentials
    int ASTERISK_ERROR = -2;
    int CLOSE_ASTERISK_ERROR = -4;
    char  ASTERISK_ERR_MESSAGE [500] = {"Error! Expecting a succeeding asterisk character, after the first initial forward slash!\n"};
    char  CLOSE_ASTERISK_ERR_MESSAGE [500] = {"Error! Expecting preceeding asterisk character, before the final forward slash !\n"};

    //Create a variable for upcoming comment
   char userComment [5000];

int main()
{
 
  //Obtain the result of the syntax analyzer
  int result = GetComment("/**This is the comment that will be used for the homework assignment. Also, God is good all the time!**/");
  
    //Call the function to evaluate the comment string
    if(result == SLASH_ERROR) 
    {
        //Print the slash error message
        perror(SLASH_ERR_MESSAGE);
    }
    else if(result == ASTERISK_ERROR)
    {
        //Print the asterisk error message
        perror(ASTERISK_ERR_MESSAGE);
    }
    else if(result == CLOSE_SLASH_ERROR)
    {
        //Print the slash error message
        perror(CLOSE_SLASH_ERR_MESSAGE);
    }
    else if(result == CLOSE_ASTERISK_ERROR)
    {
      //Print the asterisk error message
      perror(CLOSE_ASTERISK_ERR_MESSAGE);
    }
  else
    {
      //Print the comment
    }
  
  return 0;
}

/*
Function checks ensures that the incoming string 
follows the syntax rules for making comments starting
with the  forward slash '/' first, followed by an asterisk '*',
filled with any combinations of characters, that ends with another
asterisk and forward slash. 
*/
int GetComment(char* comment)
{
  //User's decision
  char decision = ' ';
  
  //Set size of comment
  size_t stringLength = 0;
  
  //Prompt user if they wish to enter their own comment or not and take input
  printf("Are you entering a comment?\n");
  scanf("%c",&decision);
  
  //Ensure that Y or N has been entered
  while((decision < 'N' || decision > 'Y') && (decision < 'n' || decision > 'y'))
    {
        printf("Please enter either 'Y', 'y', 'n' or 'N'\n");
        scanf("%c",&decision);
        getchar();
    }
  
    //If the user wishes to enter their own comment, prompt them to enter it
    //Evaluate the decision, if yes
    if(decision == 'y' || decision == 'Y')
    {

        printf("Enter the comment: ");
        scanf("%s",userComment);
       

        //Get size of comment
        stringLength = strlen(userComment);

        //Check for the forward slash '/' for the first character in string
        if(userComment[0] != '/') 
        {
            return SLASH_ERROR;
        }
        //Check for the asterisk in the second character in the string
        else if(userComment[1] != '*')
        {
            return ASTERISK_ERROR;
        }

        //Check for the asterisk '*' for the second last character in string
        if(userComment[stringLength-2] != '*')
        {
          return CLOSE_ASTERISK_ERROR;
        }
        
      //Check for the forward slash '/' for the last character in string
        if(userComment[stringLength-1] != '/')
        {
          return CLOSE_SLASH_ERROR;
        }
      
        //Print the comment afterwards
        printf("%s",userComment);

    }//If decision is no
    else
    {
        //Get size of comment
        stringLength = strlen(comment);
    
      //Check for the forward slash '/' for the first character in string
        if(comment[0] != '/') 
        {
            return SLASH_ERROR;
        }
        //Check for the asterisk in the second character in the string
        else if(comment[1] != '*')
        {
            return ASTERISK_ERROR;
        }

        //Check for the asterisk '*' for the second last character in string
        if(comment[stringLength-2] != '*')
        {
          return CLOSE_ASTERISK_ERROR;
        }

      //Check for the forward slash '/' for the last character in string
        if(comment[stringLength-1] != '/')
        {
          return CLOSE_SLASH_ERROR;
        }
      
        //Print the comment afterwards
       printf("%s",comment);
  }
  
  return 1;
}
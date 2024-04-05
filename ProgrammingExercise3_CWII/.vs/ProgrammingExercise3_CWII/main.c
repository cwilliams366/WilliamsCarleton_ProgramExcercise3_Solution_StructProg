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
#include "errors.h"

    //Global Variables
    //Slash Essentials
    int SLASH_ERROR = -1;
    char * SLASH_ERR_MESSAGE [] = { "Error! Invalid character entry. Must be the forward slash character."};

    //Asterisk Essentials
    int ASTERISK_ERROR = -2;
    char * ASTERISK_ERR_MESSAGE [] = {"Error! Expecting an asterisk character!"};

    //Comment
    char * COMMENT [];
    //Create a variable for upcoming comment
    char * userComment [];
    
int main()
{
    //Call the function to evaluate the comment string
    if(GetComment("/**This is the comment that will be used for the homework assignment. Also, God is good all the time!**/") == SLASH_ERROR) 
    {
        //Print the slash error message
        perror(SLASH_ERR_MESSAGE);
    }
    else if(GetComment("/**This is the comment that will be used for the homework assignment. Also, God is good all the time!**/") == ASTERISK_ERROR)
    {
        //Print the asterisk error message
        perror(ASTERISK_ERR_MESSAGE);
    }
    else
    {
        //Print the comment out to console
        printf(COMMENT);
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
    int stringLength = 0;
    //Prompt user if they wish to enter their own comment or not and take input
    printf("Are you entering a comment?\n");
    scanf("%c",&decision);
    //Ensure that Y or N has been entered
    while(decision != isupper('y') || decision != islower('y') || decision != isupper('n') || decision != isupper('n'))
    {
        printf("Please enter either 'Y' or 'N'\n");
        scanf("%c",&decision);
    }
    //Evaluate the decision, if yes
    if(decision == isupper('y') || decision == islower('y'))
    {

        printf("Enter the comment: ");
        scanf("%s",&userComment);

        //Get size of comment
        stringLength = strlen(comment);
        //Get more characters
        char input =  ' ';
            
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

        //Get all character input from user and check for asterisks
        do
        {
            //Get input
            scanf("%c",&input);
            strcat(userComment, input);
            while(input =! '*')
             {
                scanf("%c",&input);
                strcat(userComment, input);
             }
        }while(input != '/');
        
        //Print the comment afterwards
       strcpy(&COMMENT,&userComment);
        return 1;

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

        //Check for the asterisk in the second last character in the string
        if(comment[stringLength-2] != '*')
        {
            return ASTERISK_ERROR;
        }
           //Check for the forward slash '/' for the last character in string
        else if(comment[stringLength-1] != '/')
        {
            return SLASH_ERROR;
        }

        //Print the comment afterwards
       strcpy(&COMMENT,&comment);

       return 1;
}
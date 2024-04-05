/**
 * Header for the possible error values.
*/
//Error Types and respective messages
#ifndef ERRORS_H
#define ERRORS_H

//Slash error values and messages
extern int SLASH_ERROR;
extern int ClOSE_SLASH_ERROR;
extern char SLASH_ERR_MESSAGE [];
extern char CLOSE_SLASH_ERR_MESSAGE [];

//Asterisk error values and messages
extern int ASTERISK_ERROR;
extern int CLOSE_ASTERISK_ERROR;
extern char ASTERISK_ERR_MESSAGE [];
extern char CLOSE_ASTERISK_ERR_MESSAGE [];

//Function prototype for comment evaluation
int GetComment(char *comment);
#endif
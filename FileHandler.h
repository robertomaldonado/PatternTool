/* 
 * File:   FileHandler.h
 * Author: robertomaldonado
 *
 * Created on June 29, 2015, 12:15 PM
 */

#ifndef FILEHANDLER_H
#define	FILEHANDLER_H

class FileHandler
{

public:
    //Methods for the class
void welcomeUser();
int askDebug();
int getPubNumber();
std::string makeName(int textosPrevios);
int askMode();
bool askEnable();

    //Class variables
public:
    int debugMode;

};

#endif	/* FILEHANDLER_H */


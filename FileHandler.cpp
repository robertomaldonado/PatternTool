#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "FileHandler.h"
#include <algorithm>

using namespace std;

//Se puede pedir el nombre del autor principal que se analiza
int FileHandler::getPubNumber(){
    int numberPubs = 1;
    cout << "Textos previos del mismo autor: ";
    cin >> numberPubs;
    return numberPubs; //Pedir ingreso al usuario
}

string FileHandler::makeName(int textosPrevios){
    string titulo = "files/default";
    titulo.append("_");
    string t = to_string(textosPrevios);
    titulo.append(t);
    titulo.append(".txt");
    return titulo;
}

void FileHandler::welcomeUser(){
    
    cout << endl;
    cout << "#####################################################" << endl;
    cout << "##                                                 ## " << endl;
    cout << "##            BIENVENIDO AL PROGRAMA               ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##                PATTERN RECOGNITION              ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##            AUTOR: ROBERTO MALDONADO             ## " << endl;
    cout << "##                                                 ## " << endl;
    cout << "##################################################### " << endl;

}

int FileHandler::askDebug(){
    
    int dMode = 0;
    cout << endl;
    cout << "Mode de debugging. (0)off (1)on: ";
    cin >> dMode;
    return dMode;
    
}

int FileHandler::askMode(){

    int mode = 0;
    cout << endl;
    cout << "Percentaje mode. (0)off (1)on: ";
    cin >> mode;
    return mode;
    
}


/* 
 * File:   main.cpp
 * Author: robertomaldonado
 *
 * Created on June 28, 2015, 10:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "TextParser.h"
#include "FileHandler.h"

using namespace std;

/*
 * Debugging de la implementacion para obtener resulados relacionados a la puntuacion del texto
 * Metodos llamados desde fuera, olvidar colocar todo junto en el metodo de lectura
 */

int main(int argc, char** argv) {
    
    int mode = 0;
    int debugMode = 0;

    FileHandler manager;
    TextParser reader;
    
    
    manager.welcomeUser();
    debugMode = manager.askDebug();
    mode = manager.askMode();

    //Conocer cantidad de textos previos
    int prevText = manager.getPubNumber(); //Devuelve 1

    //Lista de nombres a cargar
    std::vector<std::string> listNames;

    //Enlistar titulos de archivos para el usuario
    for(int i = prevText; i > 0; i--){

        string name = manager.makeName(i);
        listNames.push_back(name);

        cout << "Archivo(s) Cargado(s): " << name << endl; //Debugging
    }//end for
    
    for(int i = prevText; i > 0 ; i--){
  
        reader.ReadWordsAndChars(listNames[i-1]);//Llenar wordsAndCharsVector
        reader.LoadWordVector(listNames[i-1]); // Llenaer wordsVector
        reader.LoadWholeText(listNames[i-1]);
        string name = listNames[i-1];
        
       //Caracteres matematicos y linguisticos de puntuacion y agrupacion 
        reader.generateCharacters(); //genera vectores: int commonCharsCount , char commonChars
        reader.generateAcuteChars();
        reader.generateOutputChars();//Cargar en memoria notacion reconocible
        reader.generateAcuteOutputChars();
        reader.generateMultipleChars();
        
        reader.compareChars(reader.wordsVector); //Utiliza variable tipo size_t y compara con npos
        reader.compareAcuteChars(reader.wordsVector); //Utiliza variable tipo size_t y compara con npos  
        
        reader.countSpaces(listNames[i-1]);
        reader.countTildes(reader.acuteCharsCount);
        
        if(mode!=0){
            
            reader.refineResults();    
            reader.writeFilePlot2(reader.outputCommonChars, reader.commonCharsCountDec, name);//Escribir al archivo plot.txt
            reader.writeFilePlotTildes2(reader.outputAcuteChars, reader.acuteCharsCountDec, name);
            
        }else{
        
        reader.writeFilePlot(reader.outputCommonChars, reader.commonCharsCount, name);//Escribir al archivo plot.txt
        reader.writeFilePlotTildes(reader.outputAcuteChars, reader.acuteCharsCount, name);
        }
        if(debugMode == 1){
            
                reader.printStr(reader.wholeText);
                reader.printVectorStr(reader.wordsVector);
                reader.printVectorCombined(reader.acuteChars,reader.acuteCharsCount);//Debug
                reader.printVectorCombined(reader.commonChars,reader.commonCharsCount);//Debug
                reader.printVectorCombined(reader.multipleChars,reader.multipleCharsCount);//Debug
                cout << "Cuenta de espacios: " << reader.whiteSpacesCount << ". Cuenta de tildes: " << reader.tildesCount << endl;
        }
        
        
        
        cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot.txt" << endl; //Debugging
        cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_tildes.txt" << endl; //Debugging
        
        reader.resetVariables(); // Limpieza de variables del programa

    }//end for
    
    return 0;
}
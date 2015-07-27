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
#include <cmath>
#include "TextParser.h"
#include "FileHandler.h"
#include "Analyzer.h"

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
    int aux = 1;
    
    std::vector <std::vector<double> > commonCharResults; 
    std::vector <std::vector<double> > averageResults;
    std::vector <std::vector<double> > totalResults;
    std::vector <std::vector<double> > tildesResults;
    std::vector <std::vector<double> > numericalResults;
    
    for(int i = prevText; i > 0 ; i--, aux++){
        
        
  
        reader.ReadWordsAndChars(listNames[i-1]);//Llenar wordsAndCharsVector
        reader.LoadWordVector(listNames[i-1]); // Llenaer wordsVector
        reader.LoadWholeText(listNames[i-1]);
        string name = listNames[i-1];
        
       //Caracteres matematicos y linguisticos de puntuacion y agrupacion 
        
        reader.generateNumericalCharacters();
        reader.generateCharacters(); //genera vectores: int commonCharsCount , char commonChars
        reader.generateAcuteChars();
        reader.generateOutputChars();//Cargar en memoria notacion reconocible
        reader.generateAcuteOutputChars();
        reader.generateMultipleChars();
        reader.generateMultipleOutputChars();
        reader.generateKumarExpressions();//Debug
        
        reader.compareNumericalChars(reader.wordsVector);
        reader.compareChars(reader.wordsVector); //Utiliza variable tipo size_t y compara con npos
        reader.compareAcuteChars(reader.wordsVector); //Utiliza variable tipo size_t y compara con npos  
        reader.compareMultipleChars(reader.wordsVector);
        reader.compareKumarExpressions(reader.wordsVector);
        
        //reader.whiteSpacesCount = 0;
        reader.countSpaces(listNames[i-1]);
        //reader.countTildes(reader.acuteCharsCount);
        
        reader.generateOutputAverageVector();
        reader.getAverages();
        
        reader.generateOutputTotalsVector();
        reader.getTotals();
        
        reader.generateNumericalOutputChars();
        
        if(mode!=0){
            
            reader.refineResults();  
            
            reader.writeFilePlot2(reader.outputCommonChars, reader.commonCharsCountDec, name, "plot.txt");//Escribir al archivo plot.txt
            reader.writeFilePlot2(reader.outputAverageVector, reader.averageVectorCountDec, name, "plot_averages.txt");
            reader.writeFilePlot2(reader.outputTotalsVector, reader.totalsVectorCountDec , name, "plot_totales.txt");
            reader.writeFilePlot2(reader.outputAcuteChars, reader.acuteCharsCountDec , name, "plot_tildes.txt");
           reader.writeFilePlot2(reader.outputNumericalChars, reader.numericalCharsCountDec, name, "plot_numbers.txt");
            
        }else{
        
            reader.writeFilePlot(reader.outputCommonChars, reader.commonCharsCount, name);//Escribir al archivo plot.txt
            reader.writeFilePlotTildes(reader.outputAcuteChars, reader.acuteCharsCount, name);
        }
        
        if(debugMode == 1){
            
                //reader.printStr(reader.wholeText);
                //reader.printVectorStr(reader.wordsVector);
                //reader.printVectorCombined(reader.acuteChars,reader.acuteCharsCount);//Debug
                //reader.printVectorCombined(reader.commonChars,reader.commonCharsCount);//Debug
                //reader.printVectorCombined(reader.multipleChars,reader.multipleCharsCount);//Debug
                //reader.printVectorCombined(reader.kumarExpressions,reader.kumarExpressionsCount);//Debug
              
                //  cout << "Cuenta de espacios: " << reader.whiteSpacesCount << ".\n Cuenta de tildes: " << reader.tildesCount << endl;
                //cout << "Cuenta de parrafos "<< reader.getParagraphs(reader.wholeText) << endl; 
                //cout << "Cuenta de palabras: "<< reader.getNumberWords() << endl; 
                //cout << "Long. promedio palabra: "<< reader.getAvgWordLength() << endl;
                //cout << "Oraciones identificadas: "<< reader.getSentencesMessage() << endl;
                //cout << "Puntos por parrafo: " << reader.getDotPerPar();
                //cout << "Probando calculador: " << calculator.get_kNN(reader.totalsVectorCountDec, reader.totalsVectorCountDec) << endl;
        }
        
        cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot.txt" << endl; //Debugging
        cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_totales.txt" << endl; //Debugging
        cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_averages.txt" << endl;
        
        
        Analyzer calculator[prevText];
        
        calculator[i-1].setId(aux);
        
        cout << "Identificador es: " << calculator[i-1].getId() << " para archivo: " << listNames[i-1] << endl;
        //calculator[i-1].mergeVectors(reader.commonCharsCountDec, reader.averageVectorCountDec, reader.totalsVectorCountDec);
        
        //reader.mergeVectors(reader.mainVector, reader.commonCharsCountDec, reader.averageVectorCountDec, reader.totalsVectorCountDec);
        
        
        commonCharResults.push_back(reader.commonCharsCountDec);
        averageResults.push_back(reader.averageVectorCountDec);
        totalResults.push_back(reader.totalsVectorCountDec);
        tildesResults.push_back(reader.acuteCharsCountDec);
        numericalResults.push_back(reader.numericalCharsCountDec);
        //commonCharResults.push_back(reader.averageVectorCountDec);
        
        reader.resetVariables(); // Limpieza de variables del programa

    }//end for
    
    std::vector<double> arch0;
    std::vector<double> arch1;
    std::vector<double> arch2;
    std::vector<double> arch3;
    
    std::vector<double> promedios;
    std::vector<double> equival;
    std::vector<double> vector_w;
    std::vector<double> vector_xw;
    
    double result = 0;
    std::vector<double> results;
    Analyzer calculator ;
    //Calcular similitud con commonCharResult
    arch0 = commonCharResults[0];
    arch1 = commonCharResults[1];
    arch2 = commonCharResults[2];
    arch3 = commonCharResults[3];

    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);    
    results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, promedios, equival,vector_w, vector_xw);
   
    
    //Calcular similitud con averageResults
    arch0 = averageResults[0];
    arch1 = averageResults[1];
    arch2 = averageResults[2];
    arch3 = averageResults[3];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, promedios, equival,vector_w, vector_xw);
    
     //Calcular similitud con totalResults
    arch0 = totalResults[0];
    arch1 = totalResults[1];
    arch2 = totalResults[2];
    arch3 = totalResults[3];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, promedios, equival,vector_w, vector_xw);
    
    
    //Calcular similitud con totalResults
    arch0 = tildesResults[0];
    arch1 = tildesResults[1];
    arch2 = tildesResults[2];
    arch3 = tildesResults[3];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, promedios, equival,vector_w, vector_xw);
    
    
    //Calcular similitud con totalResults
    arch0 = numericalResults[0];
    arch1 = numericalResults[1];
    arch2 = numericalResults[2];
    arch3 = numericalResults[3];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, promedios, equival,vector_w, vector_xw);

    double totalEstimado = 0; 
    
    
    for(int i = 0 ; i < results.size(); i ++){
        cout << "Valor porcentual, en posicion: " << i << " es: "<< results[i] <<endl;
        totalEstimado += results[i]/results.size();    
    }
    
    
    cout << "Resultado total es: " << totalEstimado <<"% de similitud."<<endl;
    return 0;
}
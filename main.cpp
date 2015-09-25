/* 
 * File:   main.cpp
 * Author: robertomaldonado
 *
 */

/** Include libraries used by Pattern Recognition Tool **/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "TextParser.h"
#include "FileHandler.h"
#include "Analyzer.h"
using namespace std;
/** Include libraries used by Pattern Recognition Tool **/

int main(int argc, char** argv) {
    
    FileHandler manager; //Declare a manager
    TextParser reader;   //Declare a reader
    Analyzer calculator ;
    
    /*
    * Debugging de la implementacion para obtener resulados relacionados a la puntuacion del texto
    */ 
    int mode = 0, debugMode = 0;
    
    manager.welcomeUser(); //Welcome message and menu
    debugMode = 0; //Set to be 0 when in production
    //debugMode = manager.askDebug();
    mode = 1; //Paramtro para extrar todas las estadistacas con promedio
    
    //Variables boolenas de control
    bool enableCC = false, enableAV = false, enableTR = false, enableTLR = false, enableNUMS = false, enableMAYUS = false, enableMINUS = false, enableGTNG = false;
    
    /*
    * Debugging de la implementacion para obtener resulados relacionados a la similitud entre textos
    */ 
    if(debugMode == 1){
        cout<<"Common Characters: ";  enableCC = manager.askEnable(); cout<<endl;
        cout<<"Averages to length: "; enableAV  = manager.askEnable(); cout<<endl;
        cout<<"Totals global: "; enableTR  = manager.askEnable(); cout<<endl;
        cout<<"Tilde Chars: "; enableTLR  = manager.askEnable(); cout<<endl;
        cout<<"Numerical Chars: "; enableNUMS  = manager.askEnable(); cout<<endl;
        cout<<"Mayus Characters: "; enableMAYUS  = manager.askEnable(); cout<<endl;
        cout<<"Minus Characters: "; enableMINUS  = manager.askEnable(); cout<<endl;
        cout<<"Greeting Expr.: "; enableGTNG  = manager.askEnable(); cout<<endl;
    }else{
          enableCC = true; enableAV = true; enableTR = true; enableTLR = true;
          enableNUMS = true; enableMAYUS = true; enableMINUS = true; enableGTNG = true;
    }//end if
    
    int prevText = 5;//Conocer cantidad de textos previos
    //int prevText = manager.getPubNumber(); //Devuelve 1
    prevText++; //Incrementar en 1, considerando el texto que es extrano

    //Referencia a lista de nombres, llamada listNames
    std::vector<std::string> listNames;

    /*
     Generar nombres para cada uno de los archivos
     */
    for(int i = prevText; i > 0; i--){

        string name = manager.makeName(i); 
        listNames.push_back(name);
        
        cout << "Archivo(s) Cargado(s): " << name << endl; //Debugging
    }//end for
    int aux = 1; //Variable de conteo

    /*
     * Referencia a cada uno de los vectores que contienen informacion del analisis
     * Cada agrupación contiene vectores del tipo double.
     */
    std::vector <std::vector<double> > commonCharResults,  averageResults, totalResults, tildesResults;
    std::vector <std::vector<double> > numericalResults, mayusResults, minusResults, greetingResults;
    
    for(int i = prevText; i > 0 ; i--, aux++){

        reader.LoadWordVector(listNames[i-1]); // Llenaer wordsVector
        reader.LoadWholeText(listNames[i-1]);
        string name = listNames[i-1];
        
       //Caracteres matematicos y linguisticos de puntuacion y agrupacion 
        reader.generateMinusCharacters();
        reader.generateMayusCharacters();
        
        reader.generateLowerCases();
        reader.generateUpperCases();
        
        reader.generateOutputMayusChars();
        reader.generateOutputMinusChars();
       
        reader.generateGreetings();
        reader.generateNumericalCharacters();
        reader.generateCharacters(); //genera vectores: int commonCharsCount , char commonChars
        reader.generateAcuteChars();
        reader.generateOutputChars();//Cargar en memoria notacion reconocible
        reader.generateAcuteOutputChars();
        reader.generateMultipleChars();
        reader.generateMultipleOutputChars();
        reader.generateKumarExpressions();//Debug
        
        reader.compareGreetings(reader.wordsVector);
        reader.compareMinusCharsImproved(reader.wordsVector);
        reader.compareMayusCharsImproved(reader.wordsVector);
        reader.compareNumericalChars(reader.wordsVector);
        reader.compareChars(reader.wordsVector); //Utiliza variable tipo size_t y compara con npos
        reader.compareAcuteChars(reader.wordsVector); //Utiliza variable tipo size_t y compara con npos  
        reader.compareMultipleChars(reader.wordsVector);
        reader.compareKumarExpressions(reader.wordsVector);
               
        reader.generateOutputAverageVector();
        reader.getAverages();
        
        reader.generateOutputTotalsVector();
        reader.getTotals();
        
        reader.generateOutputGreetings();
        reader.generateNumericalOutputChars();
        
//        if(mode!=0){
            
            reader.refineResults();  
      
            reader.writeFilePlot2(reader.outputCommonChars, reader.commonCharsCountDec, name, "plot.txt");//Escribir al archivo plot.txt
            reader.writeFilePlot2(reader.outputAverageVector, reader.averageVectorCountDec, name, "plot_averages.txt");
            reader.writeFilePlot2(reader.outputTotalsVector, reader.totalsVectorCountDec , name, "plot_totales.txt");
            reader.writeFilePlot2(reader.outputAcuteChars, reader.acuteCharsCountDec , name, "plot_tildes.txt");
            reader.writeFilePlot2(reader.outputNumericalChars, reader.numericalCharsCountDec, name, "plot_numbers.txt");
            reader.writeFilePlot2(reader.outputMayus, reader.mayusCountDec2, name, "plot_mayus.txt");
            reader.writeFilePlot2(reader.outputMinus, reader.minusCountDec2, name, "plot_minus.txt");
            reader.writeFilePlot2(reader.outputGreeting, reader.greetingCountDec, name, "plot_greeting.txt");
            
            //cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot.txt" << endl; //Debugging
            //cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_totales.txt" << endl; //Debugging
            //cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_averages.txt" << endl;
            
//        }else{        
//            cout << "Los parametros no estan siendo refinados. Lo sentimos!" <<endl;
//        }
        
       // if(debugMode == 1){
            
                //reader.printStr(reader.wholeText);
                //reader.printVectorStr(reader.wordsVector);
                //reader.printVectorCombined(reader.acuteChars,reader.acuteCharsCount);//Debug
                //reader.printVectorCombined(reader.commonChars,reader.commonCharsCount);//Debug
                //reader.printVectorCombined(reader.multipleChars,reader.multipleCharsCount);//Debug
                //reader.printVectorCombined(reader.kumarExpressions,reader.kumarExpressionsCount);//Debug
            
      //  }
        
        Analyzer calculator[prevText];
       
        calculator[i-1].setId(aux);
        
        cout << "File identifier number is: " << calculator[i-1].getId() << " for file: " << listNames[i-1] << endl;
        
        /*Colocar resultados en vector de resultados asociado a la categoria descrita*/
        commonCharResults.push_back(reader.commonCharsCountDec);
        averageResults.push_back(reader.averageVectorCountDec);
        totalResults.push_back(reader.totalsVectorCountDec);
        tildesResults.push_back(reader.acuteCharsCountDec);
        numericalResults.push_back(reader.numericalCharsCountDec);
        mayusResults.push_back(reader.mayusCountDec2);
        minusResults.push_back(reader.minusCountDec2);
        greetingResults.push_back(reader.greetingCountDec);
        
        reader.resetVariables(); // Limpieza de variables del programa

    }//end for
    /*
     *Fin del lazo de control para extraccion de datos 
     */
    cout<<endl<< "Proceso de carga finalizado"<<endl;
    
    /*Referencia a objetos del tipo vector para almacenar los valores de distintas categorias*/
    std::vector<double> arch0, arch1, arch2,arch3,arch4,arch5;
    
    /*Referencia a objetos del tipo vector double para almacenar los resultados y dependencias del mismo*/
    std::vector<double> promedios, equival, vector_w, vector_xw;
    std::vector<double> results;
    
    double temporalResult = 0;
    
    /*Declarar objeto del tipo Analyzer para realizar los calculos*/

  if(enableCC){ /*Validar si el conjunto de parametros fue seleccionado por el usuario*/
    
    //Cargar datos de los archivos del tipo commononChar
    calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,commonCharResults);

    //Analizar los datos por medio del metodo especificado
    temporalResult = 
            calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw,0);
            //calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 6);
    results.push_back(temporalResult);  
  }
    
  if(enableAV){ //Calcular similitud con averageResults
      
     calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,averageResults);

      temporalResult = 
              //calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);
              calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw,0);
      results.push_back(temporalResult);
  }
    
  if(enableTR){ //Calcular similitud con totalResults
      
     calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,totalResults);
    
     temporalResult = 
             calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw,0);
             //calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);
     results.push_back(temporalResult);
  }
    
  if(enableTLR){  //Calcular similitud con totalResults
      
    calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,tildesResults);
     
     temporalResult = 
             calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw, 1);
             //calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);  
     
     results.push_back(temporalResult);
  }
    
  if(enableNUMS){
      
    calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,numericalResults);
    
    temporalResult = 
      calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw, 1);
        //calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);
    
    results.push_back(temporalResult);
  }
    
  if(enableMAYUS){
      
    calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,mayusResults);
    
    temporalResult = 
           // calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);
         calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw,0);
    results.push_back(temporalResult);
        
  }
    
  if(enableMINUS){
      
    calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,minusResults);
    
    temporalResult =  
            calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5,promedios,equival,vector_w, vector_xw,0);
       // calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);
            results.push_back(temporalResult);
  }
    
  if(enableGTNG){
      
    calculator.loadVectors(arch0,arch1,arch2,arch3,arch4,arch5,greetingResults);
    
    temporalResult = 
            //calculator.applyMinkowski(arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 4);
            calculator.applyWeightedArithmeticMean(  arch0, arch1, arch2,arch3, arch4, arch5, promedios,equival,vector_w, vector_xw, 2); //Identificar cuando uso cual metodo para agregar extra coincidencia
    results.push_back(temporalResult);
  }
   
    manager.calculateVectorResultsAndPrint(results);
    
    return 0;
} /*END MAIN PROGRAM*/
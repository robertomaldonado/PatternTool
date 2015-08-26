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
    
    FileHandler manager;
    TextParser reader;
    
    int mode = 0;
    int debugMode = 0;
    
    manager.welcomeUser();
    debugMode = manager.askDebug();
    mode = 1;
    
    bool enableCC = false;
    bool enableAV = false;
    bool enableTR = false;
    bool enableTLR = false;
    bool enableNUMS = false;
    bool enableMAYUS = false;
    bool enableMINUS = false;
    bool enableGTNG = false;
    
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
          enableCC = true;
          enableAV = true;
          enableTR = true;
          enableTLR = true;
          enableNUMS = true;
          enableMAYUS = true;
          enableMINUS = true;
          enableGTNG = true;
    }
    
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
    std::vector <std::vector<double> > mayusResults;
    std::vector <std::vector<double> > minusResults;
    std::vector <std::vector<double> > greetingResults;
    
    for(int i = prevText; i > 0 ; i--, aux++){
        
        reader.ReadWordsAndChars(listNames[i-1]);//Llenar wordsAndCharsVector
        reader.LoadWordVector(listNames[i-1]); // Llenaer wordsVector
        reader.LoadWholeText(listNames[i-1]);
        string name = listNames[i-1];
        
       //Caracteres matematicos y linguisticos de puntuacion y agrupacion 
        reader.generateMinusCharacters();
        reader.generateMayusCharacters();
        
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
        
        reader.whiteSpacesCount = 0;
        reader.countSpaces(listNames[i-1]);
        //reader.countTildes(reader.acuteCharsCount);
        
        reader.generateOutputAverageVector();
        reader.getAverages();
        
        reader.generateOutputTotalsVector();
        reader.getTotals();
        
        reader.generateOutputGreetings();
        
        reader.generateNumericalOutputChars();
        
        if(mode!=0){
            
            reader.refineResults();  
            
            reader.writeFilePlot2(reader.outputCommonChars, reader.commonCharsCountDec, name, "plot.txt");//Escribir al archivo plot.txt
            reader.writeFilePlot2(reader.outputAverageVector, reader.averageVectorCountDec, name, "plot_averages.txt");
            reader.writeFilePlot2(reader.outputTotalsVector, reader.totalsVectorCountDec , name, "plot_totales.txt");
            reader.writeFilePlot2(reader.outputAcuteChars, reader.acuteCharsCountDec , name, "plot_tildes.txt");
            reader.writeFilePlot2(reader.outputNumericalChars, reader.numericalCharsCountDec, name, "plot_numbers.txt");
            reader.writeFilePlot2(reader.outputMayus, reader.mayusCountDec2, name, "plot_mayus.txt");
            reader.writeFilePlot2(reader.outputMinus, reader.minusCountDec2, name, "plot_minus.txt");
            reader.writeFilePlot2(reader.outputGreeting, reader.greetingCountDec, name, "plot_greeting.txt");
            
        }else{
        
            cout << "Los parametros no estan siendo refinados. Lo sentimos!" <<endl;
        }
        
       // if(debugMode == 1){
            
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
      //  }
        
        //cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot.txt" << endl; //Debugging
        //cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_totales.txt" << endl; //Debugging
        //cout << endl <<  "Archivo(s) Procesado(s): " << name <<"plot_averages.txt" << endl;
        
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
        mayusResults.push_back(reader.mayusCountDec2);
        minusResults.push_back(reader.minusCountDec2);
        greetingResults.push_back(reader.greetingCountDec);
        //commonCharResults.push_back(reader.averageVectorCountDec);
        
        reader.resetVariables(); // Limpieza de variables del programa

    }//end for
    
    cout<<endl<< "Proceso de carga finalizado"<<endl;
    
    std::vector<double> arch0;
    std::vector<double> arch1;
    std::vector<double> arch2;
    std::vector<double> arch3;
    std::vector<double> arch4;
    std::vector<double> arch5;
    
    
    std::vector<double> promedios;
    std::vector<double> equival;
    std::vector<double> vector_w;
    std::vector<double> vector_xw;
    
    double result = 0;
    std::vector<double> results;
    Analyzer calculator ;
    
  if(enableCC){
    //Calcular similitud con commonCharResult
    
    arch0 = commonCharResults[0];
    arch1 = commonCharResults[1];
    arch2 = commonCharResults[2];
    arch3 = commonCharResults[3];
    arch4 = commonCharResults[4];
    arch5 = commonCharResults[5];

    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);    
    //if(result !=0)
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
    
  if(enableAV){ 
    //Calcular similitud con averageResults
    arch0 = averageResults[0];
    arch1 = averageResults[1];
    arch2 = averageResults[2];
    arch3 = averageResults[3];
    arch4 = averageResults[4];
    arch5 = averageResults[5];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    //if(result !=0)
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
  if(enableTR){
     //Calcular similitud con totalResults
    arch0 = totalResults[0];
    arch1 = totalResults[1];
    arch2 = totalResults[2];
    arch3 = totalResults[3];
    arch4 = totalResults[4];
    arch5 = totalResults[5];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    //if(result !=0)
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5,promedios, equival,vector_w, vector_xw);
  }
  if(enableTLR){
    
    //Calcular similitud con totalResults
    arch0 = tildesResults[0];
    arch1 = tildesResults[1];
    arch2 = tildesResults[2];
    arch3 = tildesResults[3];
    arch4 = tildesResults[4];
    arch5 = tildesResults[5];
     
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXWNumerical(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    //if(result !=0)
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
  if(enableNUMS){
    
    //Calcular similitud con totalResults
    arch0 = numericalResults[0];
    arch1 = numericalResults[1];
    arch2 = numericalResults[2];
    arch3 = numericalResults[3];
    arch4 = numericalResults[4];
    arch5 = numericalResults[5];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performBinaryAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXWNumerical(equival, vector_w, vector_xw, arch0);
  
    
//    calculator.printVectorCount(arch0);
//    cout << " ******** "<<endl;
//    calculator.printVectorCount(promedios);
//
//    cout << " NUmeros "<<endl;
//    
//    for(int o = 0; o < vector_xw.size() ; o++){
//        cout << "Numeros: " << vector_xw[o] <<endl;
//    }
    result = calculator.get_sum(vector_xw);
    //if(result !=0)
    if(result > 100)
          result = 100;
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
  if(enableMAYUS){
    //Calcular similitud con mayusResults
    arch0 = mayusResults[0];
    arch1 = mayusResults[1];
    arch2 = mayusResults[2];
    arch3 = mayusResults[3];
    arch4 = mayusResults[4];
    arch5 = mayusResults[5];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
    //if(result !=0)
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
  if(enableMINUS){
    //Calcular similitud con mayusResults
    arch0 = minusResults[0];
    arch1 = minusResults[1];
    arch2 = minusResults[2];
    arch3 = minusResults[3];
    arch4 = minusResults[4];
    arch5 = minusResults[5];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXW(equival, vector_w, vector_xw, arch0);

    result = calculator.get_sum(vector_xw);
   // if(result !=0)
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
  if(enableGTNG){
        //Calcular similitud con mayusResults
    arch0 = greetingResults[0];
    arch1 = greetingResults[1];
    arch2 = greetingResults[2];
    arch3 = greetingResults[3];
    arch4 = greetingResults[4];
    arch5 = greetingResults[5];
    
    calculator.initializeResults(promedios, equival, vector_w, vector_xw, arch0 );
    calculator.performBinaryAverages(promedios, arch1, arch2, arch3, arch4, arch5);
    calculator.performEquival(promedios, equival ,arch0);
    calculator.performVectorW(promedios, vector_w ,arch0);
    calculator.performVectorXWGreeting(equival, vector_w, vector_xw, arch0);
    
//    cout << " ******** "<<endl;
//    calculator.printVectorCount(arch0);
//    cout << " ******** "<<endl;
//    calculator.printVectorCount(promedios);

    result = calculator.get_sum(vector_xw);
  //  if(result !=0)
      if(result > 100)
          result = 100;
        results.push_back(result);
    
    calculator.performClean( arch0, arch1, arch2, arch3, arch4, arch5, promedios, equival,vector_w, vector_xw);
  }
   
    //SUMATORIA FINAL
    double count = 0;
    double totalEstimado = 0; 
    double totalGlobal = 0; 
    double totalPonderado = 0; 
    
    cout << "ATRIBUTO:  CARACTERES.  PROMEDIOS.  TOTALES.    TILDES.   NUMEROS.   MAYUSC.   MINUSC.   SALUDO" << endl;
    cout << "PORCENRAJE: ";
        
    for(int i = 0 ; i < results.size(); i ++){
        
        std::cout <<results[i] <<"     ";
        if(results[i] > 1){
                count += 1; 
        }    
    }
    cout << endl;
    
    for(int i = 0 ; i < results.size(); i ++){
      totalEstimado +=  results[i]/count;
    }
    
    for(int i = 0 ; i < results.size(); i ++){
      totalGlobal +=  results[i]/results.size();
    }
    
    totalPonderado = totalPonderado + results[0]*0.20 + results[1]*0.20 ;
    totalPonderado = totalPonderado + results[2]*0.20 + results[3]*0.10 ;
    totalPonderado = totalPonderado + results[4]*0.07 + results[5]*0.06 ;
    totalPonderado = totalPonderado + results[6]*0.07 + results[6]*0.10 ;
    
    cout << endl << "######     ######      ######      ######      ######      ######      ######      ###### " <<endl;
    cout << endl << "Total considerando resultados != 0 : " << totalEstimado <<"% de similitud."<<endl;
    cout << endl << "Total considerando todos los resultados es: " << totalGlobal <<"% de similitud."<<endl;
    cout << endl << "Total con ponderacion manual es: " << totalPonderado <<"% de similitud."<<endl;
    cout << endl << "######     ######      ######      ######      ######      ######      ######      ###### " <<endl;
    
    cout << "RESULTADO: ";
    
    if(totalEstimado >= 60 && totalGlobal >=60 ){
        cout << " Se trata del mismo autor" <<endl;
    }else if(totalEstimado < 60 && totalEstimado > 55 ){
        cout << " Se requieren nuevos textos" <<endl;
    }else{
        cout << " No se trata del mismo autor" <<endl;
    }
    
    return 0;
}
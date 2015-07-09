
/*
 TextParser

 En la clase se presentan varias formas de abrir el archivo y cargar los datos a un vector.
 Los métodos son los siguientes:
 ReadParagraphs()
 ReadLines()
 ReadWords()
 */

#include <iostream>

#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "TextParser.h"
#include <algorithm>  //Permite compilacion desde ubuntu
#include <clocale>

//#include <wchar>
//#pragma execution_character_set("utf-8")

using namespace std;

void TextParser::LoadWholeText(string fileName) //trabajando en esto
{
  std::string tempLine = ""; //String almacenalinea de texto de forma temporal
  
  ifstream inputFile (fileName);

  if (inputFile.is_open()) {
      
    while (std::getline(inputFile, tempLine)){  //Seguir tomando el siguiente caracter del archivo de texto\
          
        wholeText = wholeText + tempLine + "\n"; //Concatenar palabra y nueva linea.
             // cout << "Leido " + tempLine << endl;    // Debug          
          }//end else
  }else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else

}

void TextParser::LoadWordVector(string fileName) //trabajando en esto
{
  string word = ""; //String almacenalinea de texto de forma temporal
  
  ifstream inputFile (fileName);

  if (inputFile.is_open()) {
      
    while ( inputFile >> word ){  //Seguir tomando el siguiente caracter del archivo de texto
              wordsVector.push_back(word); //insertar palabra
          }//end else

  }else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else

}

void TextParser::ReadWordsAndChars(string fileName) //trabajando en esto
{
  string word = ""; //String almacenalinea de texto de forma temporal
  string p1 = "";
  string p2 = "";
  char singleCharacter; //Caracter siguiente a ser analizado
    
  ifstream inputFile (fileName);
    
    //inputFile.imbue(utf8_locale);

  if (inputFile.is_open()) {
      
    while ( inputFile.get(singleCharacter) ){  //Seguir tomando el siguiente caracter del archivo de texto
    
        
      if( isspace(singleCharacter) ){  //Hay un espacio

          if( !isalpha(word.back()) ){ //Caracter no es alfabetico

            //while(!isalpha(word.back()) && word.length() > 2){

              breakUpWords(word);  //Llama al metodo que agrega la palabra
              word = "";
            //}

          }else{// Se debe analizar caso de ENTER y EOF

              wordsAndCharsVector.push_back(word); //insertar palabra
              word = "";

          }//end else

      }else{ //Caracter es alfabetico

          word += singleCharacter;
          //////////////////
          
          if(inputFile.eof()){
              cout << endl << "Encontre un fin de archivo" << endl;
          }
          
          /////////////////
      }//end if-else

    } //end while

    breakUpWords(word);

      if(!true){
          wordsAndCharsVector.push_back(word);
      }

    inputFile.close();  //Cerrar archivo

    cout << endl << "Archivo cargado en forma de palabras y caracteres" << endl;
  } //end if
  else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else

}

//Romper la palabra y agregarla a un vecotr
void TextParser::breakUpWords(string word){
    string p1 = "";
    string p2 = "";
    
    if(word.length() > 2){ //Trabajar cuando hay mas de dos caracteres en la palabra
        
        int separator = word.length()-1 ;  //Indice de caracter a sacar
        
        p1 = word.substr(0, separator);  //Obtener palabra
        
        p2 = word.substr(separator, word.length()); //Obtener el signo de puntuacion
        
        if (isalpha(p1.back()))
            wordsAndCharsVector.push_back(p1); //Agregar p1
        
    }//end if
    
    if( p1.length() > 2  && !isalpha(p1.back())){ //Significa que hay mas simbolos seguidos
        breakUpWords(p1); //Lanzar cadena p1, a BreakUpWords nuevamente
    }
    
    wordsAndCharsVector.push_back(p2); //
}


 void TextParser::countTildes(std::vector<int> & v){
  
     for (int i = 0; i < v.size(); i++)
        {
          tildesCount = tildesCount + v[i];
         // cout << "Valor de tildes: " << tildesCount << endl;
        }
     
 }

void TextParser::countSpaces(std::string fileName){
    
   ifstream inputFile (fileName);
   
   string line = ""; 
   
  if (inputFile.is_open()) {
      
    while (getline(inputFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ' )
                whiteSpacesCount++;
            
        }
    }

  }
    else
  {
    cout << "No se puede abrir el archivo " << endl; //error
  }//end if-else
   
 // cout << "La cuenta de espacios es: " << count << endl; 
 }
  

//Funcion imprime los valores de un vector del tipo string
void TextParser::printStr( std::string st){

    //Desplegar contenido del vector de lineas
    cout << "Contenido completo del archivo: "  << endl;
    cout << st ;

    cout << endl << "Fin de contenido del archivo." << endl;

}

//Funcion imprime los valores de un vector del tipo string
void TextParser::printVectorStr( std::vector<std::string>& v  ){

    //Desplegar contenido del vector de lineas
    cout << "Contenido del archivo: " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl << endl;
    }//end for

    cout << endl << "Fin de contenido del archivo." << endl;

    cout << "Informacion: ";
    cout << v.size() << endl;

}

//Funcion imprime los valores de un vector del tipo int
void TextParser::printVectorInt( std::vector<int> & v ){

    //Desplegar contenido del vector de lineas
    cout << "Contenido del archivo: " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout <<  v[i] << endl << endl;

    }//end for

    cout << endl << "Fin de contenido del archivo." << endl;

    cout << "Informacion: ";
    cout << v.size() << endl;

}

//Impresion a consola del vector combinado de palabras unicas y su conteo
void TextParser::printVectorCombined( std::vector<std::string>& v1 , std::vector<int> & v2 ){

    //Desplegar contenido del vector de lineas
    cout << "Contenido del archivo: " << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ": " << v2[i]<< endl << endl;
    }//end for
    cout << "Cuenta palabras: ";
    cout << v1.size() << endl;

}

//Almacenar en CommonChars los caracteres existentes (31)
void TextParser::generateCharacters(){
    
    //Puntuacion
    commonChars.push_back("."); //
    commonChars.push_back(":"); //
    commonChars.push_back(","); //
    commonChars.push_back(";"); //
    
    //Exclam y Pregunta
    commonChars.push_back("¡");  //
    commonChars.push_back("!"); //
    commonChars.push_back("¿"); //
    commonChars.push_back("?"); //
    
    //Operador Matematico
    commonChars.push_back("+"); //
    commonChars.push_back("-"); //
    commonChars.push_back("*"); //
    commonChars.push_back("%"); //
    commonChars.push_back("="); //
    commonChars.push_back(">"); //
    commonChars.push_back("<"); //
    commonChars.push_back("/"); //
    
    //Operador agrupacion
    commonChars.push_back("("); //
    commonChars.push_back(")"); //
    commonChars.push_back("{"); //
    commonChars.push_back("}"); //
    commonChars.push_back("["); //
    commonChars.push_back("]"); //
    
    //Signos altos
    commonChars.push_back("\""); //

    //Otros
    commonChars.push_back("@"); //
    commonChars.push_back("#"); //
    commonChars.push_back("$"); //
    commonChars.push_back("^"); //
    commonChars.push_back("&"); //
    commonChars.push_back("|"); //
    commonChars.push_back("'"); //
    commonChars.push_back("_"); //
    
    
    for (int i = 0; i < commonChars.size() ; i++){
        commonCharsCount.push_back(0);  //Inicializar todo a cero
        commonCharsCountDec.push_back(0); 
    }
    
}

void TextParser::generateAcuteChars(){
    
    //Mayus
    acuteChars.push_back("Á"); //
    acuteChars.push_back("É"); //
    acuteChars.push_back("Í"); //
    acuteChars.push_back("Ó"); //
    acuteChars.push_back("Ú");  //
    
    //Minus
    acuteChars.push_back("á");  //
    acuteChars.push_back("é"); //
    acuteChars.push_back("í"); //
    acuteChars.push_back("ó"); //
    acuteChars.push_back("ú");  //
    
   for (int i = 0; i < acuteChars.size() ; i++){     
        acuteCharsCount.push_back(0);  //Inicializar todo a cero
        acuteCharsCountDec.push_back(0);
    }
    
}


void TextParser::generateMultipleChars(){
    
    //Mayus
    multipleChars.push_back("???"); //
    multipleChars.push_back("!!!"); //
    multipleChars.push_back("..."); //

   for (int i = 0; i < multipleChars.size() ; i++){     
        multipleCharsCount.push_back(0);  //Inicializar todo a cero
        multipleCharsCountDec.push_back(0);
    }

}

void TextParser::compareChars(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    for (int i = 0; i < toCompare.size() ; i++)
    {
        for(int j=0; j < commonChars.size() ; j++){
                std::size_t found = toCompare[i].find(commonChars[j]);
                if (found!=std::string::npos)
                {
                commonCharsCount[j] =  commonCharsCount[j]+1;
                }
                
//        for(int k=0; k < multipleChars.size() ; k++){
//                std::size_t found2 = toCompare[i].find(multipleChars[k]);
//                if (found2!=std::string::npos)
//                {
//                multipleCharsCount[k] =  multipleCharsCount[k]+1;
//                }
        }
      }
    }   

void TextParser::compareAcuteChars(std::vector<std::string>& toCompare){ //Metodo mejorado de compareCharactersToFile

    for (int i = 0; i < toCompare.size() ; i++){
        
         //std::cout << " Iterando en metodo" <<endl;//Debug
         
        for(int j= 0; j < acuteChars.size() ; j++){
            
               // std::cout << "          Dentro de metodo" <<endl;//Debug
                
                  std::size_t found = toCompare[i].find(acuteChars[j]);
                        if (found!=std::string::npos)
                        {
                 //       std::cout <<acuteChars[j]<< " es un match con " << wordsAndCharsVector[i] <<endl;//Debug
                        acuteCharsCount[j] =  acuteCharsCount[j]+1;
                        //break;
                        }
        }
    }

}

//Dar formato al archivo de plot. Notacion reconocible por programas del shellScripting
void TextParser::generateOutputChars(){
    
    //Puntuacion
    outputCommonChars.push_back("PPD"); //
    outputCommonChars.push_back("PCN"); //
    outputCommonChars.push_back("PCA"); //
    outputCommonChars.push_back("PCS"); //
    
    //Exclam y Pregunta
    outputCommonChars.push_back("EEO");  //
    outputCommonChars.push_back("EEC"); //
    outputCommonChars.push_back("EQO"); //
    outputCommonChars.push_back("EQC"); //
    
    //Operador Matematico
    outputCommonChars.push_back("MPS"); //
    outputCommonChars.push_back("MMS"); //
    outputCommonChars.push_back("MTS"); //
    outputCommonChars.push_back("MMO"); //
    outputCommonChars.push_back("MEQ"); //
    outputCommonChars.push_back("MGR"); //
    outputCommonChars.push_back("MLR"); //
    outputCommonChars.push_back("MDN"); //
    
    //Operador agrupacion
    outputCommonChars.push_back("GPO"); //
    outputCommonChars.push_back("GPC"); //
    outputCommonChars.push_back("GCO"); //
    outputCommonChars.push_back("GCC"); //
    outputCommonChars.push_back("GBO"); //
    outputCommonChars.push_back("GBC"); //
    
    //Signos altos
    outputCommonChars.push_back("OBS"); //
    
    //Otros
    outputCommonChars.push_back("OAA"); //
    outputCommonChars.push_back("ONS"); //
    outputCommonChars.push_back("ODS"); //
    outputCommonChars.push_back("OHO"); //
    outputCommonChars.push_back("ONP"); //
    outputCommonChars.push_back("OVD"); //
    outputCommonChars.push_back("OPS"); //
    outputCommonChars.push_back("OUS"); //
}

//Dar formato al archivo de plot. Notacion reconocible por programas del shellScripting
void TextParser::generateAcuteOutputChars(){
    
    //Puntuacion
    outputAcuteChars.push_back("MAA"); //
    outputAcuteChars.push_back("MAE");
    outputAcuteChars.push_back("MAI");
    outputAcuteChars.push_back("MAO");
    outputAcuteChars.push_back("MAU");
    
    outputAcuteChars.push_back("MIA");
    outputAcuteChars.push_back("MIE");
    outputAcuteChars.push_back("MII");
    outputAcuteChars.push_back("MIO");
    outputAcuteChars.push_back("MIU");

}

void TextParser::refineResults(){
  
     for (int i = 0; i < acuteCharsCount.size() ; i++)
     {
         acuteCharsCountDec[i] = (acuteCharsCount[i]/(double)wordsVector.size())*100;
         //cout << "Se ha dividido para: " << wordsVector.size() << endl;
     }
     
     for (int i = 0; i < commonCharsCount.size() ; i++)
     {
         commonCharsCountDec[i] = (commonCharsCount[i]/(double)wordsVector.size())*100;
     }
     
     for (int i = 0; i < multipleCharsCount.size() ; i++)
     {
         multipleCharsCountDec[i] = (multipleCharsCount[i]/(double)wordsVector.size())*100;
     }
     
    
}

void TextParser::writeFilePlot(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append("plot.txt");
    
    //Abrir el archivo
    myfile.open(outputName);
    
    //Escribir en el archivo
    myfile << "##### CATEGORIA SIMBOLOS GLOBALES ####" << endl;
    
    myfile << "PPD: Punctuation Period\nPCN: Punctuation Colon\nPCA: Punctuation Comma\nPSC: Punctuation Semicolon\nEEO: Expression Exclamation Open\nEEC: Expression Exclamation Close\nEQO: Expression Question Open\nEQC: Expression Question Close\nMPS: Mathematical Plus\nMMS: Mathematical Minus\nMTS: Mathematical Times\nMMO: Mathematical Modulus\nMEQ: Mathematical Equals\nMGR: Mathematical Greater\nMLR: Mathematical Lesser\nMDN: Mathematical Division\nGPO: Grouping Parenthesis Open\nGPC: Grouping Parenthesis Close\nGCO: Grouping Curly Bracket Open\nGCC: Grouping XCurly Bracket Close\nGBO: Grouping Bracket Open\nGBC: Grouping Bracket Close\nOBS: Other Back Slash\nOAA: Other Arroba\nONS: Other Number Symbol\nODS: Other Dollar Sign\nOHO: Other Carret\nONP: Other Ampersand\nOVD: Other Pipe\n\n" << endl;
    
    myfile << "FILE " << name <<" ";
    for (int i = 0; i < v1.size(); i++) //Iterara sobre todas las palabras
    {
        myfile << v1[i] << " " << v2[i]<< " ";
    }//end for
    
    //Cerrar el archivo saliente
    myfile.close();   
}

void TextParser::writeFilePlotTildes(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append("plot_tildes.txt");
    
    //Abrir el archivo
    myfile.open(outputName);
    
    //Escribir en el archivo
    myfile << "##### CATEGORIA ACENTOS GLOBALES ####" << endl;
    
    //myfile << " Other Carret\nONP: Other Ampersand\nOVD: Other Pipe\n\n" << endl;
    
    myfile << "FILE " << name <<" ";
    for (int i = 0; i < v1.size(); i++) //Iterara sobre todas las palabras
    {
        myfile << v1[i] << " " << v2[i]<< " ";
    }//end for
    
    //Cerrar el archivo saliente
    myfile.close();   
}

void TextParser::writeFilePlot2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append("plot.txt");
    
    //Abrir el archivo
    myfile.open(outputName);
    
    //Escribir en el archivo
    myfile << "##### CATEGORIA SIMBOLOS GLOBALES ####" << endl;
    
    myfile << "PPD: Punctuation Period\nPCN: Punctuation Colon\nPCA: Punctuation Comma\nPSC: Punctuation Semicolon\nEEO: Expression Exclamation Open\nEEC: Expression Exclamation Close\nEQO: Expression Question Open\nEQC: Expression Question Close\nMPS: Mathematical Plus\nMMS: Mathematical Minus\nMTS: Mathematical Times\nMMO: Mathematical Modulus\nMEQ: Mathematical Equals\nMGR: Mathematical Greater\nMLR: Mathematical Lesser\nMDN: Mathematical Division\nGPO: Grouping Parenthesis Open\nGPC: Grouping Parenthesis Close\nGCO: Grouping Curly Bracket Open\nGCC: Grouping XCurly Bracket Close\nGBO: Grouping Bracket Open\nGBC: Grouping Bracket Close\nOBS: Other Back Slash\nOAA: Other Arroba\nONS: Other Number Symbol\nODS: Other Dollar Sign\nOHO: Other Carret\nONP: Other Ampersand\nOVD: Other Pipe\n\n" << endl;
    
    myfile << "FILE " << name <<" ";
    for (int i = 0; i < v1.size(); i++) //Iterara sobre todas las palabras
    {
        myfile << v1[i] << " " << v2[i]<< " ";
    }//end for
    
    //Cerrar el archivo saliente
    myfile.close();   
}

void TextParser::writeFilePlotTildes2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append("plot_tildes.txt");
    
    //Abrir el archivo
    myfile.open(outputName);
    
    //Escribir en el archivo
    myfile << "##### CATEGORIA ACENTOS GLOBALES ####" << endl;
    
    //myfile << " Other Carret\nONP: Other Ampersand\nOVD: Other Pipe\n\n" << endl;
    
    myfile << "FILE " << name <<" ";
    for (int i = 0; i < v1.size(); i++) //Iterara sobre todas las palabras
    {
        myfile << v1[i] << " " << v2[i]<< " ";
    }//end for
    
    //Cerrar el archivo saliente
    myfile.close();   
}

void TextParser::resetVariables(){
    
    cout << endl << "Cleared Variables... Ready for next text..." << endl;
    wordsAndCharsVector.clear();
    wordsVector.clear();
    wholeText = "";
   // uniqueWordsVector.clear();
    //uniqueWordsVectorCount.clear();
    //clonedVector.clear();
    commonCharsCount.clear();
    commonCharsCountDec.clear();
    commonChars.clear();
    
    acuteCharsCount.clear();
    acuteCharsCountDec.clear();
    acuteChars.clear();
    
    multipleCharsCount.clear();
    multipleChars.clear();
    multipleCharsCountDec.clear();
    
    outputCommonChars.clear();
    outputAcuteChars.clear();
    
    whiteSpacesCount = 0 ;
    tildesCount = 0 ;
}
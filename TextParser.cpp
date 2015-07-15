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


 double TextParser::countTildes(std::vector<int> & v){
     double tildes = 0 ; 
     
     for (int i = 0; i < v.size(); i++)
        {
          tildes = tildes + v[i];
        }
     return tildes;
     
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
    multipleChars.push_back("Tilde");
    multipleChars.push_back("Whitespace");
    multipleChars.push_back("???"); //
    multipleChars.push_back("!!!"); //
    multipleChars.push_back("..."); //

   for (int i = 0; i < multipleChars.size() ; i++){     
        multipleCharsCount.push_back(0);  //Inicializar todo a cero
        multipleCharsCountDec.push_back(0);
   }
}
void TextParser::generateKumarExpressions(){

    kumarExpressions.push_back("Bueno");
    kumarExpressions.push_back("Sin embargo");
    kumarExpressions.push_back("Basicamente");

   for (int i = 0; i < kumarExpressions.size() ; i++){     
        kumarExpressionsCount.push_back(0);  //Inicializar todo a cero
        kumarExpressionsCountDec.push_back(0);
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
                found = 0;
                }        
      }
    } 
}

void TextParser::compareMultipleChars(std::vector<std::string>& toCompare){
       
    for(int i = 0 ; i < acuteCharsCount.size() ; i++){
        multipleCharsCount[0] += acuteCharsCount[i];
    }
       multipleCharsCount[1] = 9 ; //Correguir
        
    for (int i = 0; i < toCompare.size() ; i++){
        for (int k=0; k < multipleChars.size() ; k++){
                std::size_t pos = toCompare[i].find(multipleChars[k]);
                if (pos!=std::string::npos)
                {
                multipleCharsCount[k] =  multipleCharsCount[k]+1;
                //pos = 0;
                //break;
                }
        }
    }
       // cout << "PARRAFOS: " << getParagraphs() <<endl;
 
}
void TextParser::compareKumarExpressions(std::vector<std::string>& toCompare){
       
    for(int i = 0 ; i < acuteCharsCount.size() ; i++){
        multipleCharsCount[0] += acuteCharsCount[i];
    }
        multipleCharsCount[1] = 9 ; //Correguir
        
    for (int i = 0; i < toCompare.size() ; i++){
        
        for (int k=0; k < kumarExpressions.size() ; k++){
                std::size_t pos = toCompare[i].find(kumarExpressions[k]);
                if (pos!=std::string::npos)
                {
                    kumarExpressionsCount[k] =  kumarExpressionsCount[k]+1;
                }
        }
    }
       // cout << "PARRAFOS: " << getParagraphs() <<endl;
 
}

void TextParser::addKumarAvg(){
    
        kumarExpressionsCount.push_back(kumarExpressionsCount[0]/wordsVector.size());
        kumarExpressionsCount.push_back(kumarExpressionsCount[1]/wordsVector.size());
        kumarExpressionsCount.push_back(kumarExpressionsCount[2]/wordsVector.size());

}

int TextParser::getParagraphs(std::string text){
    
    int number_of_p = 0;
    string comp = "";
    
     for(unsigned int i=0; i < text.length(); i++){
       //     cout << "Text: "<<text[i] << endl;
         
           if ( text[i]== '\n')
                        number_of_p++;
         }
    
    return number_of_p;
}

int TextParser::getNumberWords(){
    return wordsVector.size();
}

int TextParser::getAvgWordLength(){
    int sum = 0;
    int avg = 0;
    
    for (unsigned int i=0; i < wordsVector.size(); i++){
        
        sum += wordsVector[i].size();
    }
    avg = sum/wordsVector.size(); 
    
    return avg;
}

int TextParser::getSentencesMessage(){
    int sentences = commonCharsCount[0] + commonCharsCount[5] + commonCharsCount[7] ;
    return sentences;
}

double TextParser::getDotPerPar(){
    double dotsPP = commonCharsCount[0] / (double)getParagraphs(wholeText) ;
    return dotsPP;
}

double TextParser::getCommaPerPar(){
    double commaPP = commonCharsCount[2] / (double)getParagraphs(wholeText) ;
    return commaPP;
}

double TextParser::getColonPerPar(){
    double colonPP = commonCharsCount[1] / (double)getParagraphs(wholeText) ;
    return colonPP;
}

double TextParser::getSemicolonPerPar(){
    double semicolonPP = commonCharsCount[3] / (double)getParagraphs(wholeText) ;
    return semicolonPP;
}
double TextParser::getQosPerPar(){
    double qosPP = commonCharsCount[3] / (double)getParagraphs(wholeText) ;
    return qosPP;
}
double TextParser::getMultipleQosPerPar(){
    double mqosPP = commonCharsCount[7] / (double)getParagraphs(wholeText) ;
    return mqosPP;
}
double TextParser::getWordsPerPar(){
    double wordsPS = wordsVector.size() / (double)getParagraphs(wholeText) ;
    return wordsPS;
}
double TextParser::getWordsPerSent(){
    double wordsPS = wordsVector.size() / (double)getSentencesMessage() ;
    return wordsPS;
}
double TextParser::getWsPerSent(){
    double wsPS = wordsVector.size() / (double)getSentencesMessage() ;
    return wsPS;
}
double TextParser::getSpaceBeforeComma(std::vector<std::string>& v ){
    
    double cBs = 0;
    for(int i = 0 ; i < v.size(); i++){
       // cout<< "CUIDADO: " << v[i].compare(",") << endl; 
        if(v[i].compare(",") == 0){
          cBs +=1; 
        }
        
    }
    return cBs;
    
}
double TextParser::getSpaceAfterComma(std::vector<std::string>& v ){
    
    double sAc = 0;
//    for(int i = 0 ; i < v.size(); i++){
//        if(v[i].compare(",") == 0){
//          cBs +=1; 
//        }
//        
//    }
    return sAc;
    
}
double TextParser::getSpaceBeforeCommaAvg(){
    double cBs = getSpaceBeforeComma(wordsVector) / (double) wordsVector.size() ;
    return cBs;
}

void TextParser::getAverages(){
    
    averageVectorCountDec.push_back( getAvgWordLength() );
    averageVectorCountDec.push_back( getWordsPerSent() );
    averageVectorCountDec.push_back( getWordsPerPar() );
    averageVectorCountDec.push_back( getDotPerPar() );
    averageVectorCountDec.push_back( getCommaPerPar()  );
    averageVectorCountDec.push_back( getColonPerPar() );
    averageVectorCountDec.push_back( getSemicolonPerPar()  );
    averageVectorCountDec.push_back( getQosPerPar() );
    averageVectorCountDec.push_back( getMultipleQosPerPar() );
    averageVectorCountDec.push_back( 0 );//51
    averageVectorCountDec.push_back( kumarExpressionsCount[0]/(double)wordsVector.size() );    
    averageVectorCountDec.push_back( kumarExpressionsCount[1]/(double)wordsVector.size() );
    averageVectorCountDec.push_back( kumarExpressionsCount[2]/(double)wordsVector.size() );
    averageVectorCountDec.push_back( (double)commonCharsCount[0] );
    averageVectorCountDec.push_back( (double)commonCharsCount[2] );
    averageVectorCountDec.push_back( getSpaceBeforeCommaAvg() );
    
}
void TextParser::getTotals(){
    
        totalsVectorCountDec.push_back( 0 );
        totalsVectorCountDec.push_back(0);
        totalsVectorCountDec.push_back( getNumberWords() );
        totalsVectorCountDec.push_back( getSentencesMessage() );
        totalsVectorCountDec.push_back( getParagraphs(wholeText) );
        totalsVectorCountDec.push_back( countTildes(acuteCharsCount) );
        totalsVectorCountDec.push_back( whiteSpacesCount );
        totalsVectorCountDec.push_back( multipleCharsCount[2]);
        totalsVectorCountDec.push_back( multipleCharsCount[3]);
        totalsVectorCountDec.push_back(multipleCharsCount[4]);
        totalsVectorCountDec.push_back(0);
        totalsVectorCountDec.push_back( (double)kumarExpressionsCount[0] );
        totalsVectorCountDec.push_back((double)kumarExpressionsCount[1]);
        totalsVectorCountDec.push_back((double)kumarExpressionsCount[2]);
        totalsVectorCountDec.push_back( getSpaceAfterComma(wordsVector) );
        totalsVectorCountDec.push_back( getSpaceBeforeComma(wordsVector) );

}
//void TextParser::compareMultipleChars(std::string toCompare){
//    
//    std::string comp = "";
//            
//    for (int i = 0; i+2 < toCompare.size() ; i++)
//    {
//         comp = toCompare.substr(i,i+2);
//        
//        //cout << comp;
//        
//        for(int k=0; k < multipleChars.size() ; k++){
//           
//               // cout<<"Compare " << multipleChars[k] << " against " << comp << endl;
//               // cout << "Valore de salida son : " <<i << ", " << k << endl; 
//                
//                if(comp.compare(multipleChars[k]) == 0){
//        
//                        multipleCharsCount[k] =  multipleCharsCount[k]+1;
//                //        cout<<"Success!!!!!!" << multipleChars[k] << endl;
//                }
//                std::size_t pos = comp.find("...");
//                
//          //  }
//        }
//    }
//}
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

void TextParser::generateMultipleOutputChars(){
    
    //Puntuacion
    outputAcuteChars.push_back("TLD"); // Tildes
    outputAcuteChars.push_back("WSM"); // Whitespaces in message
    outputAcuteChars.push_back("MQM"); // Multiple Question
    outputAcuteChars.push_back("MQM"); // Multiple Exclamation
    outputAcuteChars.push_back("MEL"); // Multiple Dots ...
//    
//    outputAcuteChars.push_back("MIA");
//    outputAcuteChars.push_back("MIE");
//    outputAcuteChars.push_back("MII");
//    outputAcuteChars.push_back("MIO");
//    outputAcuteChars.push_back("MIU");

}

void TextParser::generateOutputAverageVector(){

    outputAverageVector.push_back( "AWL");
    outputAverageVector.push_back("AWPS");
    outputAverageVector.push_back("AWPP");
    outputAverageVector.push_back("ADPP");
    outputAverageVector.push_back("ACPP");
    outputAverageVector.push_back("ACOPP");
    outputAverageVector.push_back("ASCPP");
    outputAverageVector.push_back("AQPP");
    outputAverageVector.push_back("AMQPP");
    outputAverageVector.push_back("AWSPS");
    outputAverageVector.push_back("AK1");
    outputAverageVector.push_back("AK2");
    outputAverageVector.push_back("AK3");
    outputAverageVector.push_back("AWS");
    outputAverageVector.push_back("ACAS");
    outputAverageVector.push_back("ACBS");

}

void TextParser::generateOutputTotalsVector(){
    
        outputTotalsVector.push_back("TUS");
        outputTotalsVector.push_back("TLS");
        outputTotalsVector.push_back("TNW");
        outputTotalsVector.push_back("TNS");
        outputTotalsVector.push_back("TNP");
        outputTotalsVector.push_back("TNT");
        outputTotalsVector.push_back("TNWS");
        
        outputTotalsVector.push_back("TNMQ");
        outputTotalsVector.push_back("TNME");
        outputTotalsVector.push_back("TNE");
        outputTotalsVector.push_back("TNWAP");
        outputTotalsVector.push_back("TNK1");
        outputTotalsVector.push_back("TNK2");
        outputTotalsVector.push_back("TNK3");
        outputTotalsVector.push_back("TNCBS");
        outputTotalsVector.push_back("TNCAS");

}

void TextParser::refineResults(){
  
     for (int i = 0; i < acuteCharsCount.size() ; i++)
     {
         acuteCharsCountDec[i] = (acuteCharsCount[i]/(double)wordsVector.size())*100;
         //cout << "Se ha dividido para: " << wordsVector.size() << endl;
     }
     
     for (int j = 0; j < commonCharsCount.size() ; j++)
     {
         commonCharsCountDec[j] = (commonCharsCount[j]/(double)wordsVector.size())*100;
     }
     
     for (int k = 0; k < multipleCharsCount.size() ; k++)
     {
         multipleCharsCountDec[k] = (multipleCharsCount[k]/(double)wordsVector.size())*100;
     }
     
     for (int m = 0; m < kumarExpressions.size() ; m++)
     {
         kumarExpressionsCountDec[m] = (kumarExpressionsCount[m]/(double)wordsVector.size())*100;
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

void TextParser::writeFilePlot2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name, std::string ext){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append(ext);
    
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

void TextParser::writeFilePlotTildes2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name, std::string ext){
    //Manjeador de archivo
    ofstream myfile;
    
    //Nombre del archivo de salida generado
    string outputName = name; //cambiar a default
    outputName.append(ext);
    
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
    averageVectorCountDec.clear();
    
    acuteCharsCount.clear();
    acuteCharsCountDec.clear();
    acuteChars.clear();
    
    multipleCharsCount.clear();
    multipleChars.clear();
    multipleCharsCountDec.clear();
    
    outputCommonChars.clear();
    outputAcuteChars.clear();
    outputAverageVector.clear();
    outputTotalsVector.clear();
    
    kumarExpressions.clear();
    kumarExpressionsCount.clear();
    kumarExpressionsCountDec.clear();
    
    totalsVectorCountDec.clear();
    //totalsVector.clear();
    
    whiteSpacesCount = 0 ;
    tildesCount = 0 ;
}
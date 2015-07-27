/* 
 * File:   TextParser.h
 * Author: robertomaldonado
 *
 * Created on June 26, 2015, 3:08 PM
 */
#ifndef TEXTPARSER_H
#define	TEXTPARSER_H

class TextParser
{
public:
    //Methods for the class
    void ReadWordsAndChars(std::string );
    void LoadWordVector(std::string );
    void LoadWholeText(std::string);
    
    //Debugging (Mostrar datos en  consola) 
    double countTildes( std::vector<int> & v );
    void countSpaces(std::string);
    void printStr( std::string st );
    void printVectorStr( std::vector<std::string>& v );
    void printVectorInt( std::vector<int>& v );
    void printVectorCombined( std::vector<std::string>& v1 , std::vector<int> & v2 );
    void printVectorCombined( std::vector<std::string>& v1 , std::vector<double> & v2 );
    
    //Recursivo para almacenar palabras temporales 
    void breakUpWords(std::string );
    
    //void generateUniques();
    
    //void generateUniquesCount();
    //void generateSpecialCharacters();
    void generateNumericalCharacters();
    void generateCharacters(); //Genera caracteres de puntuacion 
    void generateAcuteChars(); //Caracteres tildados
    void generateMultipleChars(); //Caracteres multiples
    void generateKumarExpressions(); //Caracteres tildados
    
    int getParagraphs(std::string text);
    int getNumberWords();
    int getAvgWordLength();
    int getSentencesMessage();
    double getDotPerPar();
    double getCommaPerPar();
    double getColonPerPar();
    double getSemicolonPerPar();
    double getQosPerPar();
    double getMultipleQosPerPar();
    double getWordsPerPar();
    double getWordsPerSent();
    double getWsPerSent();
    double getSpaceBeforeCommaAvg();
    double getSpaceBeforeComma(std::vector<std::string>& v );
    double getSpaceAfterComma(std::vector<std::string>& v );
    void getAverages();
    
    
    void getTotals();
    
    //void compareCharactersToFile();
    void compareNumericalChars(std::vector<std::string>& toCompare);
    void compareChars(std::vector<std::string>& toCompare); //Compara los caracteres comunes 
    void compareAcuteChars(std::vector<std::string>& toCompare); //Compara los caracteres acentuados
    void compareMultipleChars(std::vector<std::string>& toCompare);
    void compareKumarExpressions(std::vector<std::string>& toCompare);
    
    void addKumarAvg();
    
    void generateNumericalOutputChars();
    void generateOutputChars(); //Almacena nombres representativos para los graficos
    void generateAcuteOutputChars(); //Almacena nombres representativos para los graficos
    void generateMultipleOutputChars();
    void generateOutputAverageVector();
    
    //void generateTotalsVector();
    void generateOutputTotalsVector();
    
    void refineResults();
   
    void writeFilePlot(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name); //Escribe al file para lectura
    void writeFilePlotTildes(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name);
    //int inspectChars(std::vector<std::string>& p);
    
    void writeFilePlot2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name,  std::string ext); //Escribe al file para lectura
    void writeFilePlotTildes2(std::vector<std::string>& v1 , std::vector<double> & v2, std::string name,  std::string ext);
    
    //void writeFile(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name);
    //void writeFile2(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name);
    //void writeFilePlot(std::vector<std::string>& v1 , std::vector<int> & v2, std::string name);
    void mergeVectors(std::vector<double>& v0, std::vector<double>& v1, std::vector<double>& v2 , std::vector<double>& v3);
    void resetVariables();  //Utilizado para reiniciar variables, en manejo de archivos múlitples

    //Class variables
public:
    int whiteSpacesCount ;
    int tildesCount;
    
    std::string wholeText;
    std::vector<std::string> wordsAndCharsVector; //Toda la lectura del archivo en vector
    std::vector<std::string> wordsVector;
    //std::vector<std::string> clonedVector;  //Vector temporal para ordenar los contenidos
    
    //std::vector<std::string> uniqueWordsVector; //Vector de palabras  o simbolos unicos
    //std::vector<int> uniqueWordsVectorCount; //Cuenta de palabras para cada uno de las palabras o simbolos
    
    
    std::vector<std::string> averagesVector; 
    
    std::vector<std::string> numericalChars;
    std::vector<std::string> acuteChars; //Caracteres acentuados
    std::vector<std::string> commonChars; //Cualquier otro caracter. Puntuacion o matematico.
    std::vector<std::string> multipleChars; //Cualquier otro caracter. Puntuacion o matematico.
    std::vector<std::string> kumarExpressions;
    
    std::vector<std::string> outputNumericalChars; 
    std::vector<std::string> outputCommonChars; //Cualquier otro caracter. Puntuacion o matematico.
    std::vector<std::string> outputAcuteChars;
    std::vector<std::string> outputAverageVector;
    std::vector<std::string> outputTotalsVector;
    
    std::vector<int> commonCharsCount; //Cuenta de todos los caracteres asi sean 0.
    std::vector<int> acuteCharsCount; //Cuenta de todos los caracteres asi sean 0.
    std::vector<int> multipleCharsCount; //Cuenta de todos los caracteres asi sean 0.
    std::vector<int> kumarExpressionsCount;
  //  averageVectorCount
    std::vector<double>  numericalCharsCountDec;
    std::vector<double> commonCharsCountDec; //Cuenta de todos los caracteres asi sean 0.
    std::vector<double> acuteCharsCountDec; //Cuenta de todos los caracteres asi sean 0.
    std::vector<double> multipleCharsCountDec; //Cuenta de todos los caracteres asi sean 0.
    std::vector<double> kumarExpressionsCountDec;
    std::vector<double> averageVectorCountDec;
    std::vector<double> totalsVectorCountDec;
    std::vector<double> mainVector;
};
#endif	/* TEXTPARSER_H */


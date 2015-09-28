#define DEBUGMODEOFF
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include "Analyzer.h"
#include <algorithm>
#include <math.h>

using namespace std;

void Analyzer::setId(int n){

    identifier = n;
}

int Analyzer::getId(){

    return identifier;
    
}

double Analyzer::get_kNN( std::vector<double> v1, std::vector<double> v2 ){
    
    double value = 0;
    
    for(int i = 0; i < v1.size() ; i++)
    {
        value = value + pow((v1[i] - v2[i]), 2.0);
    }    
    
    return sqrt(value);

}

double Analyzer::get_sum( std::vector<double>& v1 ){
    
    double value = 0;
    
    for(int i = 0; i < v1.size() ; i++)
    {
        value += v1[i] ;
    }    
    
    return value;

}

void Analyzer::performBinaryAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c, std::vector<double> d, std::vector<double> e){

    for(int i = 0 ; i < a.size() ;i++){ 
        
        v[i] = (a[i] + b[i] + c[i]+ d[i]+e[i])/(double)5 ;
        
        if( v[i] > 0 ){
            v[i] = 1;
        }
    }
    
}


void Analyzer::performAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c, std::vector<double> d, std::vector<double> e){

    for(int i = 0 ; i < a.size() ;i++){ 
        
        v[i] = (a[i] + b[i] + c[i]+ d[i] + e[i])/(double)5 ;  
    }
    
}


void Analyzer::performEquival(std::vector<double>& p, std::vector<double>& e, std::vector<double> d){

    for(int i = 0 ; i < d.size() ;i++){ 
        
        if(p[i]!=0){
                e[i] = (100 * d[i])/ p[i] ;
        }else{
                e[i] = 0;
        }
        
        if(e[i] > 100 && e[i] < 200){
           e[i] = abs(e[i] - 200);
        }else if(e[i] >= 200){
           e[i] = 0;
        }
       
    }
}

void Analyzer::performMinkowski(std::vector<double>& p, std::vector<double>& e, std::vector<double>& d, double exp){

    for(int i = 0 ; i < d.size() ;i++){ 
        
        e[i] = abs( std::pow((p[i] - d[i]),exp));
        
    }
    
    for(int i = 0 ; i < d.size() ;i++){ 
        
        p[i] = abs( std::pow(p[i],exp));
        
    }
 
}

void Analyzer::printVectorCount(std::vector<double>& v){

    for(int i = 0 ; i < v.size() ;i++){ 
        
        cout << "Contenido: " << v[i]<<endl;
    }
}


void Analyzer::performVectorW(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d){
    
    double sum = 0;
    //promedios, vector_w ,arch0
    
    for(int i = 0; i < p.size() ; i++)
    {
        sum += p[i] ;
    }    
   
    for(int i = 0 ; i < d.size() ;i++){ 
        
        if( sum!=0 ){
                vw[i] =  ((p[i])/sum) ;
        }else{
               vw[i] = 0;
        }
    }

}

void Analyzer::performVectorXW(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d){
    
    //equival, vector_w, vector_xw, arch0
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
    }
    
}

void Analyzer::performVectorXWNumerical(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d){
    
    double items = e.size();
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
                if(d[i] > 0){
                    wx[i] += 100/items; //Verify
                      //  break;
                }
    }
  
}

void Analyzer::performVectorXWGreeting(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d){
    
    //equival, vector_w, vector_xw, arch0
    double items = e.size();
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
                if(d[i] > 0)
                        wx[i] += 25 ; //Verify
    
    }
    
}

void Analyzer::initializeResults(std::vector<double>& p,  std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d ){

    for(int i = 0 ; i < d.size() ;i++){ 
        
        p.push_back(0);e.push_back(0);w.push_back(0); wx.push_back(0);
    }
    
}

void Analyzer::performClean( std::vector<double>& z, std::vector<double>& a,  std::vector<double>& b,std::vector<double>& c, std::vector<double>& d, std::vector<double>& e, std::vector<double>& p, std::vector<double>& ee,std::vector<double>& w, std::vector<double>& wx){
   
    a.clear(); b.clear();c.clear(); d.clear();e.clear();
    z.clear();p.clear();ee.clear();w.clear();wx.clear();  
    
}

void Analyzer::loadVectors( std::vector<double>& file0, std::vector<double>& file1, std::vector<double>& file2, std::vector<double>& file3,std::vector<double>& file4, std::vector<double>& file5, std::vector <std::vector<double> >& toAssign ){
     
    file0 = toAssign[0]; file1 = toAssign[1];file2 = toAssign[2];file3 = toAssign[3];file4 = toAssign[4];file5 = toAssign[5];
    
}

double Analyzer::performMinEquival(std::vector<double>& a, std::vector<double>& b, double exp){
    
    double returnVal;
    double maxAwayDist = get_sum(a);
    double root = 1/exp;
    double sumMaxAwayDist = std::pow(maxAwayDist,root);
    
    double var = get_sum(b);
    double totalMin = std::pow(var,root);
    
#ifndef DEBUGMODEOFF
    cout <<" returning" << abs(((totalMin/sumMaxAwayDist)*100))  <<endl;
#endif
    
    if((totalMin/sumMaxAwayDist)*100 > 100){
          returnVal = abs((totalMin/sumMaxAwayDist)*100-200);
    }else{
        returnVal = 100-(totalMin/sumMaxAwayDist)*100;
    }
    
   
    
    return returnVal;
}
    
double Analyzer::applyWeightedArithmeticMeanDistance( 
                                         std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& equivalRef,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef,
                                         int extraAtribution){
     
    double returnScore = 0;
    
    loadVectors(file0, file1, file2, file3, file4, file5, toAssign);
            
    initializeResults(promediosRef, equivalRef, vector_wRef, vector_xwRef, file0 );
    
    if(extraAtribution==0 || extraAtribution==1 ){
       performAverages(promediosRef, file1, file2, file3, file4, file5); 
    }
    else if(extraAtribution==2){
        performBinaryAverages(promediosRef, file1, file2, file3, file4, file5);
    }
    performEquival(promediosRef, equivalRef ,file0);
    performVectorW(promediosRef, vector_wRef ,file0);
    
    if(extraAtribution==0){
        performVectorXW(equivalRef, vector_wRef, vector_xwRef, file0);
    }else if(extraAtribution==1){
        performVectorXWNumerical(equivalRef, vector_wRef, vector_xwRef, file0);
    }else if(extraAtribution==2){
        performVectorXWGreeting(equivalRef, vector_wRef, vector_xwRef, file0);
    }
    
    if(get_sum(vector_xwRef) <= 100){
        returnScore = get_sum(vector_xwRef); 
    }else{
        returnScore = 100;
    }
    
    performClean( file0, file1, file2, file3, file4, file5, promediosRef, equivalRef,vector_wRef, vector_xwRef);
    
     cout << "Weighted mean distance has been applied" <<endl; 
    
    return returnScore;
}

double Analyzer::applyMinkowskiDistance( std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5,
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& minkowskiDistance,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef,
                                         double exp){
     
    double returnScore = 0;
    
       loadVectors(file0, file1, file2, file3, file4, file5, toAssign);
        
       initializeResults(promediosRef, minkowskiDistance, vector_wRef, vector_xwRef, file0 );
    
       performAverages(promediosRef, file1, file2, file3, file4, file5); 
       
       performMinkowski(promediosRef, minkowskiDistance ,file0, exp);
       
       returnScore = performMinEquival(promediosRef, minkowskiDistance, exp );
    
        performClean( file0, file1, file2, file3, file4, file5, promediosRef, minkowskiDistance,vector_wRef, vector_xwRef);
        
#ifndef DEBUGMODEOFF
        cout << "Minkowski distance has been applied" <<endl;
#endif
    
    return returnScore;
}

double Analyzer::applyChebyshevDistance( std::vector <std::vector<double> >& toAssign,
                                         std::vector<double>& file0, std::vector<double>& file1, 
                                         std::vector<double>& file2, std::vector<double>& file3,
                                         std::vector<double>& file4, std::vector<double>& file5, 
                                         std::vector<double>& promediosRef,
                                         std::vector<double>& minkowskiDistance,
                                         std::vector<double>& vector_wRef,
                                         std::vector<double>& vector_xwRef){
     
    double returnScore = 0;
    
       loadVectors(file0, file1, file2, file3, file4, file5, toAssign);
    
       initializeResults(promediosRef, minkowskiDistance, vector_wRef, vector_xwRef, file0 );
    
       performAverages(promediosRef, file1, file2, file3, file4, file5); 
//       
//       performMinkowski(promediosRef, minkowskiDistance ,file0, exp);
//       
//       returnScore = performMinEquival(promediosRef, minkowskiDistance, exp );
//    
//        performClean( file0, file1, file2, file3, file4, file5, promediosRef, minkowskiDistance,vector_wRef, vector_xwRef);
//        
        cout << "Chebyshev distance has been applied" <<endl;
    
    return returnScore;
}

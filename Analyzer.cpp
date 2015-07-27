
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


void Analyzer::mergeVectors(std::vector<double> v1, std::vector<double> v2 , std::vector<double> v3){

    v1.insert(v1.end(), v2.begin(), v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());

    double sum = 0;
    
        std::vector<double>::const_iterator it = v1.begin();
        for(; it != v1.end(); ++it) {
                std::cout << *it << ", ";
                //sum += v1[i];
        }
        for(int i =0; i < v1.size(); i++){
            sum += v1[i];
        }
        
      cout << "Sum is: "  << sum << endl; 
      
     std::vector<double> featuresCountVector(v1);
}

void Analyzer::setId(int n){

    identifier = n;
}

int Analyzer::getId(){

    return identifier;
    
}

void Analyzer::storeVectorValues( std::vector<double> v1 ){


}

double Analyzer::get_kNN( std::vector<double> v1, std::vector<double> v2 ){
    
    double value = 0;
    
    for(int i = 0; i < v1.size() ; i++)
    {
        value = value + pow((v1[i] - v2[i]), 2.0);
    }    
    
    return sqrt(value);

}

double Analyzer::get_sum( std::vector<double> v1 ){
    
    double value = 0;
    
    for(int i = 0; i < v1.size() ; i++)
    {
        value += v1[i] ;
    }    
    
    return value;

}

void Analyzer::performAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c){

    for(int i = 0 ; i < a.size() ;i++){ 
        
        v[i] = (a[i] + b[i] + c[i])/(double)3 ;
        
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


void Analyzer::performVectorW(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d){
    
    double sum = 0;
    
    
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
    
    for(int i = 0 ; i < d.size() ;i++){ 
                wx[i] =  e[i]*w[i] ;    
    }
    
}

void Analyzer::initializeResults(std::vector<double>& p,  std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d ){

    for(int i = 0 ; i < d.size() ;i++){ 
        p.push_back(0);
        e.push_back(0);
        w.push_back(0);
        wx.push_back(0);
        //de
    }

}

void Analyzer::performClean( std::vector<double>& d, std::vector<double>& a,  std::vector<double>& b,std::vector<double>& c, std::vector<double>& p, std::vector<double>& e,std::vector<double>& w, std::vector<double>& wx){
   
    a.clear();
    b.clear();
    c.clear();
    d.clear();
    p.clear();
    e.clear();
    w.clear();
    wx.clear();
    
}

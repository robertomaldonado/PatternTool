/* 
 * File:   Analyzer.h
 * Author: robertomaldonado
 *
 * Created on July 15, 2015, 10:15 AM
 */

#ifndef ANALYZER_H
#define	ANALYZER_H


class Analyzer{
    
    public:
        void setId(int n);
        int getId();
        
        void storeVectorValues( std::vector<double> v1 );
        double get_kNN( std::vector<double> v1, std::vector<double> v2 );
        void mergeVectors(std::vector<double> v1, std::vector<double> v2, std::vector<double> v3);
        double get_sum( std::vector<double> v1 );
        
        void initializeResults(std::vector<double>& p,  std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d );
        void performAverages(std::vector<double>& v, std::vector<double> a,std::vector<double> b, std::vector<double> c);
        void performEquival(std::vector<double>& p, std::vector<double>& e, std::vector<double> d);
        void performVectorW(std::vector<double>& p, std::vector<double>& vw, std::vector<double> d);
        void performVectorXW(std::vector<double>& e, std::vector<double>& w, std::vector<double>& wx, std::vector<double> d);
        void performClean( std::vector<double>& d, std::vector<double>& a,  std::vector<double>& b,std::vector<double>& c, std::vector<double>& p, std::vector<double>& e,std::vector<double>& w, std::vector<double>& wx);

public:
        int identifier;
        std::vector<double> featuresCountVector(); 
};
#endif	/* ANALYZER_H */


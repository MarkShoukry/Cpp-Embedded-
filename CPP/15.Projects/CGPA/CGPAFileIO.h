#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>



class CGPAFileIO
{
public:
    static CGPAFileIO& GetInstance() ;

    double ReadPreviousCGPA (const std::string& filename)  const ;

    void WriteCGPA(const std::string& filename, double CGPA) const ;

private:
//private constructor to prevent instantiation
    CGPAFileIO() {}    
};

double CalculateCGPA(double previousCGPA, int totalPreviousCredits, double currentGPA, int totalCurrentCredits) ;
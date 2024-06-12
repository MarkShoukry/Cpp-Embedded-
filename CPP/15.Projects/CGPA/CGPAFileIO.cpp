#include "CGPAFileIO.h"


CGPAFileIO& CGPAFileIO::GetInstance() 
{
    static CGPAFileIO instance; //static instance of CGPAFileIO
    return instance ;
}

double CGPAFileIO::ReadPreviousCGPA (const std::string& filename) const  
{
    std::ifstream CGPAFile(filename);
    if (!CGPAFile.is_open())
    {
        throw std::runtime_error("Error: couldn't open file for previous CGPA data.");
    }

    double CGPA;
    CGPAFile >> CGPA;
    CGPAFile.close();
    return CGPA;
}


void CGPAFileIO::WriteCGPA(const std::string& filename, double CGPA) const
{
    std::ofstream CGPAFile(filename);
    if (!CGPAFile.is_open())
    {
        throw std::runtime_error("Error: couldn't open file to write updated CGPA.");
    }

    CGPAFile << CGPA;
    CGPAFile.close();
}



double CalculateCGPA(double previousCGPA, int totalPreviousCredits, double currentGPA, int totalCurrentCredits) 
{
    return ((previousCGPA * totalCurrentCredits) + (currentGPA * totalCurrentCredits)) / (totalPreviousCredits + totalCurrentCredits) ;
}                     

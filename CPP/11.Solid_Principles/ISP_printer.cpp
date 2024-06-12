/*
ISP:- Interface Segregation Principle
Clients should not be forced to depend on 
methods that they don't need.
*/
#include <iostream>
#include <vector>

struct Documment ;

struct IPrinter
{
    virtual void Print(std::vector<Documment*> docs) = 0 ;
};

struct IScanner
{
    virtual void Scan(std::vector<Documment*> docs) = 0 ;
};

struct IFax
{
    virtual void Fax(std::vector<Documment*> docs) = 0 ;
};


struct IMachine : IPrinter,IScanner
{
    IPrinter& printer;
    IScanner& scanner;

    IMachine(IPrinter& printer , IScanner& scanner)
                :printer(printer), scanner(scanner)
    {
    }

    void Print (std::vector<Documment*> docs) override
    {
        printer.Print(docs) ;
    }
    void Scan(std::vector<Documment*> docs) override
    {
        scanner.Scan(docs) ;
    }

};


// (SRP): Single Responsibilit Principle
//The class has one reason to change

#include <iostream>
#include <string>
#include <vector>
#include <fstream>    //ofstream ofs(obj)


struct Journal
{
    std::string m_title;
    std::vector<std::string> m_entries ;

    explicit Journal(const std::string& title) : m_title(title)
    {
    }

    void Add(const std::string& entry)
    {
        m_entries.push_back(entry);
    }
    // void save(const std::string& filename) {}  //not single responsibility
};


// To fix the class (SRP):

struct  PrintEntirsManager
{
    static void Save(const Journal& j, const std::string& filename)
    {
        std::ofstream ofs(filename);

        //checks if the file stream ofs failed to open
        if(!ofs.is_open())
        {
            std::cerr << "Error: Failed to opne file " << filename << std::endl ;
            return;
        }

        for (const auto& s : j.m_entries)
        {
            ofs << s << std::endl ;
        }
        ofs.close() ; // close the file stream
        std::cout << "Journal entries saved to " << filename << std::endl;
    }
};


int main ()
{
    Journal Alahram { "Alahram" } ;
   // Journal Alahly { "Alahly" } ;

    Alahram.Add("There is was a visit for the prime minstar of Egypt to India \n") ;
    PrintEntirsManager::Save(Alahram, "Alahram.txt");
    


    return 0 ;
}



// ofs.is_open(): This member function of std::ofstream returns true if the file stream is open and false otherwise.
// !ofs.is_open(): The logical negation operator ! is used to check if the file stream is not open.
// {}: If the condition !ofs.is_open() evaluates to true, the code block inside the curly braces {} is executed.


// if (!ofs.is_open()) { line is used for error handling to ensure that the file stream is successfully opened 
// before attempting to write to the file. If the file stream couldn't be opened, 
// the program prints an error message and returns without writing to the file.
//allocation of object and dellocation of object 
//To can save storge of memory 

#include <iostream>
#include <vector>
#include <algorithm>

struct Book
{
    std::uint16_t Id;
    std::string Title;
};

class Library
{
public:
    Library()
    {

    }

    void addBook (Book& book)
    {
        list_of_book.push_back(book) ;
    }
    void removeBook (std::uint16_t book_id)
    {
        list_of_book.erase(std::remove_if(list_of_book.begin(), list_of_book.end(), [book_id](const Book& book)
        {
            return book.Id == book_id ;
        }),
        list_of_book.end());
        
    }

    void showLibrary ()
    {
        for (auto Book : list_of_book)
        {
            std::cout << "book id " << Book.Id << " ->book title : " << Book.Title << std::endl;
        }
    }

private:
    std::vector<Book>list_of_book;
    
};




int main ()
{
    Library *lib = new Library() ;

    Book tech_book;
    tech_book.Id = 1;
    tech_book.Title = "Working effectivy with legacy code " ;
    lib->addBook(tech_book);

    Book poarey_book ;
    poarey_book.Id = 2 ;
    poarey_book.Title = "poarey book" ;
    lib->addBook(poarey_book);

    Book Mark ;
    Mark.Id = 3;
    Mark.Title = "Mark Shokry" ;
    lib->addBook(Mark);

    lib->showLibrary();

    
    lib->removeBook(2);

    printf("\n") ;
    lib->showLibrary();

    delete lib ;


    return 0 ;
}
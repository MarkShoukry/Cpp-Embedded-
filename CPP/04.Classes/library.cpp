/*
create a library that has many books, each book has an Id
user can add a book ,delete a book and update book Id
search for a specific book using it's Id
*/

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
    void AddBook (Book& book)
    {
        list_books.push_back(book);
    }    

    void RemoveBook (std::uint16_t book_id)
    {
        //look for the id and then use erase
        for (auto index = 0 ; index < list_books.size(); ++index)
        {
            if (book_id == list_books[index].Id)
            {
            auto & removed_Book = list_books.at(index);
            removed_Book.Id = 0;
            removed_Book.Title = "";
            }
        }
    }

    void EraseBook (std::uint16_t book_id)
    {
        //Books.erase(first,last)
        list_books.erase(std::remove_if(list_books.begin(),list_books.end(), [book_id](const Book& book)
        {
            return book.Id == book_id ;
        }),
        list_books.end());
    }
    

    void ShowLibrary ()
    {
        for (auto book : list_books)
        {
            std::cout << "book id " << book.Id << " ->book title : " << book.Title << std::endl;
            
        }
    }


private:
    std::vector<Book>list_books;
};






int main ()
{
    Library library;
    Book tech_book;
    tech_book.Id = 1;
    tech_book.Title = "Working effectivy with legacy code " ;
    library.AddBook(tech_book);

    Book poarey_book ;
    poarey_book.Id = 2 ;
    poarey_book.Title = "poarey book" ;
    library.AddBook(poarey_book);


    library.ShowLibrary() ;

    library.EraseBook(2);
    
    library.ShowLibrary() ;

    return 0;
}
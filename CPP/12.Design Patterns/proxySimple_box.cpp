//create ile proxy
//Task:create a Box class and restrict the access through Authentication
 
#include <iostream>
#include <memory>
using namespace std;

class IBox
{
public:
    virtual ~IBox() = default ;
    virtual void Open() = 0 ;
};

class SimpleBox : public IBox
{
public:
    virtual void Open ()
    {
        cout << "Opening the box\n" ;
    }
};


class ProxyBox : public IBox
{
public:
    ProxyBox(string sUserName, string sPwd) 
            : m_UserName(sUserName) , m_Pwd(sPwd)
    {
    }

    void Open() 
    {
        if (iSAuthenticated())
            {
                cout << "\nAuthentication success\n" ;
                m_Box.Open() ;
                cout << "Open is called\n" ;
            }
            else
            cout << "\nAuthentication Failure , you can't open the Box";
    }


private:
    string m_UserName ;
    string m_Pwd;
    SimpleBox m_Box;


    bool iSAuthenticated()
        {
            bool bAuthenticated = false ;
            if(m_UserName == "Admin" && m_Pwd == "Test123")
            {
                bAuthenticated = true ;
            }
            return bAuthenticated;
        }
};


int main ()
{
    shared_ptr<IBox> box;
    box = make_shared<ProxyBox>("mn", "Te3");
    box->Open();
   
    cout << "\n\nCorrect username and password:" ;
    box = make_shared<ProxyBox>("Admin", "Test123");
    box->Open();




    return 0;
}
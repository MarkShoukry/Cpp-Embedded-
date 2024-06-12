#include <iostream>
#include <vector>
#include <string>
#include <memory>

class IFileSyListener
{
public:
    enum class FILE_CHANGE
    {
        FILE_ADDED,
        FILE_REMOVED,
        FILE_UPDATEED
    };

    virtual ~IFileSyListener() = default ;
    virtual void OnFileChange(FILE_CHANGE type) = 0 ;
};


class FileSyListener : public IFileSyListener
{
public:
    void OnFileChange(IFileSyListener::FILE_CHANGE type) override
    {
        std::cout << "File has been changed" << std::endl;
    }   
};


class FileSyMonitor
{
public:
    FileSyMonitor(const std::wstring& spath) : m_spath(spath)
    {
    }
    
    void OnFileAdd() 
    {
        for (auto& listener : m_Listeners)
        {
            listener->OnFileChange(IFileSyListener::FILE_CHANGE::FILE_ADDED);
        }
    } 
    void OnFileRemove()
    {
       for (auto& listener : m_Listeners)
       {
        listener->OnFileChange(IFileSyListener::FILE_CHANGE::FILE_REMOVED);
       }
    }

    void OnFileUpdate()
    {
       for (auto& listener : m_Listeners)
       {
        listener->OnFileChange(IFileSyListener::FILE_CHANGE::FILE_UPDATEED);
       }
    }
    void AddFileChangeListener(std::shared_ptr<IFileSyListener> listener)
    {   
        m_Listeners.push_back(listener);   
    }
    void RemoveChangeListener(std::shared_ptr<IFileSyListener> listener)
    {
      //  m_Listeners.erase(std::remove(m_Listeners.begin(),m_Listeners.end(), &listener));
    }

private:
    std::vector<std::shared_ptr<IFileSyListener>> m_Listeners ;
    std::wstring m_spath;
};



int main()
{
    //Listener Objects
    std::shared_ptr<IFileSyListener> pListener = std::make_shared<FileSyListener>();

    //Creating FileSystem Monitor
    FileSyMonitor monitor(L"C:\\log");
    //Ragistering file change listener
    monitor.AddFileChangeListener(pListener);

    //Explicittly calling file changes
    monitor.OnFileAdd();
    monitor.OnFileRemove();

    return 0 ;
}
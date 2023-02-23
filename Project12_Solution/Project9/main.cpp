#include <iostream>
#include <string>

using namespace std;

//인터페이스 클래스 : 순수 가상 함수로만 이루어진 클래스
class IErrorLog
{
public:
    virtual bool reportError(const char* errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Printing error to a console" << endl;
        return true;
    }
};

void doSometing(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}

int main()
{
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSometing(file_log);
    doSometing(console_log);

    return 0;
}
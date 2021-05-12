#include <iostream>
#include <memory>

class Singleton{
private:
    static Singleton *instance;
    int data;
    Singleton() {}
public:
    static Singleton *Instance()
    {
        if(instance==NULL)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void SetData (int value)
    {
        data = value;
    }

    int GetData()
    {
        return data;
    }

};

Singleton *Singleton::instance = NULL;

int main(int argc, char *argv[])
{
    Singleton::Instance()->SetData(13);
    std::cout << "Data = " << Singleton::Instance()->GetData() << std::endl;

    return 0;
}
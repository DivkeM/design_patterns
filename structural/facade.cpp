#include <iostream>
#include <memory>

class SubSystemClass1{
public:
    void Class1Method1()
    {
        std::cout<<"[I] using SubSystemClass1::Class1Method1()"<<std::endl;
    }
    void Class1Method2()
    {
        std::cout<<"[I] using SubSystemClass1::Class1Method2()"<<std::endl;
    }
};

class SubSystemClass2{
public:
    void Class2Method1()
    {
        std::cout<<"[I] using SubSystemClass2::Class2Method1()"<<std::endl;
    }
    void Class2Method2()
    {
        std::cout<<"[I] using SubSystemClass2::Class2Method2()"<<std::endl;
    }
};

class SubSystemClass3{
public:
    void Class3Method1()
    {
        std::cout<<"[I] using SubSystemClass3::Class3Method1()"<<std::endl;
    }
    void Class3Method2()
    {
        std::cout<<"[I] using SubSystemClass3::Class3Method2()"<<std::endl;
    }
};

class FacadeSystem{
    SubSystemClass1 *SubSysCls1;
    SubSystemClass2 *SubSysCls2;
    SubSystemClass3 *SubSysCls3;
public:
    FacadeSystem()
    {
        SubSysCls1 = new SubSystemClass1();
        SubSysCls2 = new SubSystemClass2();
        SubSysCls3 = new SubSystemClass3();
    }
    void Method1()
    {
        std::cout<<"Using FacadeSystem::Method1()"<<std::endl;
        SubSysCls1->Class1Method1();
        SubSysCls2->Class2Method1();
        SubSysCls3->Class3Method1();
    }
    void Method2()
    {
        std::cout<<"Using FacadeSystem::Method2()"<<std::endl;
        SubSysCls1->Class1Method2();
        SubSysCls2->Class2Method2();
        SubSysCls3->Class3Method2();       
    }
};

int main(int argc, char *argv[])
{
    std::unique_ptr<FacadeSystem> facadeSys(new FacadeSystem());
    facadeSys->Method1();
    facadeSys->Method2();

    return 0;
}
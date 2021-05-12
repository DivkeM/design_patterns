/*Observer design pattern is used to notify all the objects to update themselves 
when an object state gets changed. This is also known as Publish-Subscribe.*/

#include <iostream>
#include <memory>
#include <vector>

class Subject;

/*abstract with pure virtual*/
class Observer{
public:
    Subject *psub;
    virtual void Update() = 0;
};

class Subject {
public:
    std::vector <Observer *> observers;
    
    void Attach(Observer *obj)
    {
        observers.push_back(obj);
    }

    void Detach(Observer *obj)
    {
    }

    void Notify()
    {
        for(int i = 0; i < observers.size(); i++)
        {
            observers[i]->Update();
        }
    }

    virtual void SetState(int value) = 0;
    virtual int GetState() = 0;
};

class ConcreteSubject : public Subject
{
private:
    int state;
public:
    void SetState(int value)
    {
        state = value;
        Notify();
    }

    int GetState()
    {
        return state;
    }
};

class ConcreteObserverA : public Observer{
private:
    int state;
public:
    ConcreteObserverA(Subject *obj)
    {
        psub = obj;
        psub->Attach(this);
    }
    void Update()
    {
        std::cout << "ConcreteObserverA::Update()" <<std::endl;
        state = psub->GetState();
        std::cout << "state = " << state <<std::endl;
    }
};

class ConcreteObserverB : public Observer{
private:
    int state;
public:
    ConcreteObserverB(Subject *obj)
    {
        psub = obj;
        psub->Attach(this);
    }
    void Update()
    {
        std::cout << "ConcreteObserverB::Update()" <<std::endl;
        state = psub->GetState();
        std::cout << "state = " << state <<std::endl;
    }
};

int main(int argc, char *argv[])
{
    std::cout << "test observer" << std::endl;

    Subject *object = new ConcreteSubject();

    Observer *object1 = new ConcreteObserverA(object);
    Observer *object2 = new ConcreteObserverB(object);

    object->SetState(15);

    return 0;
}
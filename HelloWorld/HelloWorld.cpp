#include <iostream>
#include <vector>
#include <string>
#include <thread>

using namespace std;

#define MAX_LENGTH_A 10

#define MAX_A 20
#define MAX_LENGTH_ABC 30

class TestClass
{
public:
    void Hello_A();
    void Hello_B();
private:
    int i;
    int j;
};

void TestClass::Hello_A()
{
    int i = 10;
    cout << endl;
    cout << __FUNCTION__ << " >> " << i << endl;
}
void TestClass::Hello_B()
{
    int j = 20;
    cout << __FUNCTION__ << " >> " << j << endl;
}
void Hello()
{
    cout << "Hello Thread" << endl;
}
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    thread task(Hello);

    for (const string &word : msg)
    {
        cout << word << " ";
    }

    if (1)
    {
        int j = 0;
    }
    else
    {
        Hello();
    }

    TestClass anInstance;
    int i = 0;

    switch (i)
    {
    case 0:
        anInstance.Hello_A();
        break;

    case 1:
        anInstance.Hello_B();
        break;

    case 2:
        break;

    default:
        break;
    }

    cout << endl;
    task.join();
}
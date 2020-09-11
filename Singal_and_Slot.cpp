/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

// Reference from https://medium.com/brakulla

// Example program
#include <iostream>
#include <string>
#include <functional>
#include <vector>

template <typename ...Args> class slot;
template <typename ...Args>
class signal
{
public:
    signal(const signal &) = delete;
    signal(signal &&) = delete;
    signal &operator=(const signal &) = delete;

    signal() = default;
    ~signal() = default;

 
    void connect(slot<Args...> &slot)
    {
        _connectedSlots.push_back(&slot);
    }

    void disconnect(slot<Args...> &slot)
    {
        // using iterator for safe deletion
        for (auto it = _connectedSlots.begin(); it != _connectedSlots.end(); ) {
            if (*it == slot)
                it = _connectedSlots.erase();
            else ++it;
        }
    }
    void disconnect()
    {
        _connectedSlots.clear();
    }

 
    void emit(Args... parameters)
    {
        for (auto &el: _connectedSlots)
            (*el)(parameters...); // using () operator overloading
    }

private:
    std::vector<slot<Args...> *> _connectedSlots;
};


template <typename ...Args>
class slot
{
public:
    slot(const slot&) = delete;
    slot(slot &&) = delete;
    slot &operator=(const slot&) = delete;

    slot() : _init(false) {};
    slot(std::function<void(Args...)> callback) : _init(true), _callback(callback) {}
    ~slot() = default;
   
    void operator()(Args... parameters)
    {
        // just implement it in call function
        this->call(parameters...);
    }
    void call(Args... parameters)
    {
        if (_init)
            _callback(parameters...);
    }

    void setSlotFunction(std::function<void(Args...)> callback)
    {
        _init = true;
        _callback = callback;
    }

private:
    bool _init;
    std::function<void(Args...)> _callback;
};

int main()
{
    signal<int> mySignal;
    slot<int> mySlot([] (int input) {
        std::cout << "We received: " << input << std::endl;
    });
    mySignal.connect(mySlot);

    std::cout << "Emitting signal" << std::endl;
    mySignal.emit(5);
    return 0;
}

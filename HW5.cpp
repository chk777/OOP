#include <iostream>

using namespace std;
/// 1задание
template <typename T>
class Pair1
{
private:
    T a, b;
public:
    Pair1(T input1, T input2)
        : a(input1), b(input2) {};

    T first() const
    {
        return a;
    }

    T second() const
    {
        return b;
    }
};

/// 2задание
template <typename T1, typename T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    Pair() {}
    Pair(T1 inputA, T2 inputB)
        : a(inputA), b(inputB) {}

    T1 first() const
    {
        return a;
    }

    T2 second() const
    {
        return b;
    }
};

// 3задание
template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(std::string inputString, T inputValue)
        : Pair<std::string, T>(inputString, inputValue) {}
};

// 4задание

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const std::string& name = "");
    virtual ~GenericPlayer() = default;

    virtual bool IsHitting() const = 0; //еще нужно брать карту?
    bool IsBoosted() const;     // показывает перебор
    void Bust() const;    // объявляет перебор

private:
    std::string name;

};


int main()
{
   
    ///// 1задание
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    //// 2задание
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    // 3задание

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    // 4задание


    return 0;
}

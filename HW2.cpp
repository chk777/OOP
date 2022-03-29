#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    static int count; // счетчик 
protected:
    string n_name;
    int n_age;
    string n_sex;
    int n_wight;


public:
    static int GetCount() { return count; }
    //Person();
    Person(const string& name, const int& age, const string& sex, const int& wight)
        : n_name(name), n_age(age), n_wight(wight), n_sex(sex)
    {
        count++;
    }

    string GetName() { return n_name; }
    int GetAge() { return n_age; }
    int GetWighr() { return n_wight; }
    virtual void Print()   //  виртуальная функция перегружаемая в классе Student
    {
        cout << n_name << ' ' << n_age << ' ' << n_sex << ' ' << n_wight << endl;
    }
};

class Student : public Person
{
private:
    int n_year;
public:
    Student(int year, const string& name, const int age, const string& sex, const int wight)
        :Person(name, age, sex, wight), n_year(year)
    {}
    int GetYear() { return n_year; }
    void AddYear(int addValue)
    {
        n_year += addValue;
    }
    void AddYear()
    {
        n_year++;
    }

    void Print()
    {
        cout << n_year << ' ';
        Person::Print();
    }
};
int Person::count = 0; // инициализация счетчика

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Fruit
{
public:
    std::string name;
    std::string color;

    Fruit(std::string name, std::string color) : name(std::move(name)), color(std::move(color)) {}
};

class Banana : public Fruit
{
public:
    Banana(std::string name = "Banana", std::string color = "Yellow") : Fruit(std::move(name), std::move(color)) {}
};

class Apple : public Fruit
{
public:
    Apple(std::string name = "Apple", std::string color = "Red") : Fruit(std::move(name), std::move(color)) {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith(std::string name = "Granny Smith", std::string color = "Green") : Apple(std::move(name), std::move(color))) {}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    const int N = 2;
    Person* pers[N];
    for (int i = 0; i < N; i++)
    {
        int year, wight, age;
        string name, sex;
        cout << "Enter name age sex weight age:" << endl;
        cin >> name >> age >> sex >> wight >> year;
        pers[i] = new Student(year, name, age, sex, wight); // указатель на Person инициализируем классом Student
        cout << "Count=" << pers[i]->GetCount() << endl; // вывод количества созданных экземпляров
    }
    for (int i = 0; i < N; i++)
        pers[i]->Print();
    Student* s1 = static_cast<Student*>(pers[0]); // s1 теперь имеет тип Student*, иначе не вызвать AddYear
    s1->AddYear(2);
    cout << "New age of " << s1->GetName() << " = "
        << s1->GetAge() << endl;
    for (int i = 0; i < N; i++)
        delete pers[i]; // освобождение выделенной памяти

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

/*3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. 
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? 
Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы. */

/* Будет использовано 7 классов Card, Hand, Deck, GenericPlayer, Player, House, Game; 
Базовые классы: Card, Hand, Game. Производные классы: Deck, GenericPlayer, Player, House
*/

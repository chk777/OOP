#include <iostream>

using namespace std;
/*
Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).Для всех классов создать конструкторы.
Для класса Figure добавить чисто виртуальную функцию area() (площадь).Во всех остальных классах переопределить эту функцию, 
исходя из геометрических формул нахождения площади.
*/
class Figure
{
public:
    Figure() {};
    virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
    double a, h;

public:
    Parallelogram(double inputA, double inputH)
        : a(inputA), h(inputH) {};

    double area() override
    {
        return (a * h);
    }
};

class Circle : public Figure
{
private:
    double r;
public:
    Circle(double inputR)
        : r(inputR) {};

    double area() override
    {
        return (3.14 * r * r / 2);
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double inputA, double inputH)
        : Parallelogram(inputA, inputH) {};

    double area() override
    {
        return (a * h);
    }
};

class Square : public Parallelogram
{
public:
    Square(double inputA)
        : Parallelogram(inputA, inputA) {};

    double area() override
    {
        return (a * a);
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double inputA, double inputH)
        : Parallelogram(inputA, inputH) {};

    double area() override
    {
        return (a * h);
    }
};

/*Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.*/

class Car
{
protected:
    std::string company, model;
public:
    Car() {}
    Car(std::string inputCompany, std::string inputModel)
        : company(inputCompany), model(inputModel)
    {
        std::cout << "\nBase car constructor";
    }

    virtual ~Car()
    {
        std::cout << "\nBase car destructor";
    }
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar() {}
    PassengerCar(std::string inputCompany, std::string inputModel)
        : Car(inputCompany, inputModel)
    {
        std::cout << "\nPassenger car constructor";
        std::cout << "\n" << company << " " << model;
    }

    std::string getModel()
    {
        return model;
    }

    ~PassengerCar()
    {
        std::cout << "\nPassenger car destructor";
    }
};

class Bus : virtual public Car
{
public:
    Bus() {}
    Bus(std::string inputCompany, std::string inputModel)
        : Car(inputCompany, inputModel)
    {
        std::cout << "\nBus constructor";
        std::cout << "\n" << company << " " << model;
    }

    ~Bus()
    {
        std::cout << "\nBus destructor";
    }
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(std::string inputCompany, std::string inputModel)
        : Car(inputCompany, inputModel)
    {
        std::cout << "\nMinivan constructor";
        std::cout << "\n" << company << " " << model;
    }

    ~Minivan()
    {
        std::cout << "\nMinivan destructor";
    }
};


/*Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).

Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.

Продемонстрировать использование перегруженных операторов.*/
class Fraction
{
    int ch;
    int zn;
public:
    Fraction(int ch, int zn)
    {
        if (zn == 0)
            throw runtime_error("zero division error");
        this->ch = ch;
        this->zn = zn;
    }
    int get_ch() const
    {
        return ch;
    }

    int get_zn() const
    {
        return zn;
    }

    //+
    friend Fraction& operator + (const Fraction& f1, const Fraction& f2);

    // -
    friend  Fraction operator-(const Fraction& i);


    friend Fraction& operator + (const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.ch * f2.zn + f2.ch * f1.zn, f1.zn * f2.zn);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Создать класс Card, описывающий карту в игре БлэкДжек.У этого класса должно быть три поля : масть, значение карты и положение карты(вверх лицом или рубашкой).Сделать поля масть и значение карты типом перечисления(enum).Положение карты - тип bool.Также в этом классе должно быть два метода :
//метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//етод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum Suits {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Rank {
    Ace =1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

class Card
{
private:
    Suits suit;
    Rank rank;
    bool CardUp;
public:

    void Flip()
    {
        CardUp = !CardUp;
    }

    Ranks getValue()
    {
        return rank;
    }
};

int main()
{
    //1задания
    double parallelorgamHeight(3), parallelogramBase(5.1);
    Parallelogram parallelogram(parallelogramBase, parallelorgamHeight);
    std::cout << parallelogram.area() << "\n";

    double circleRadius(2.8);
    Circle circle(circleRadius);
    std::cout << circle.area() << "\n";

    double squareBase(5);
    Square square(squareBase);
    std::cout << square.area() << "\n";

    double rectangleBase(3), rectangleHeight(3);
    Rectangle rectangle(rectangleBase, rectangleHeight);
    std::cout << rectangle.area() << "\n";

    double rhombusBase(2), rhombusHeight(5);
    Rhombus rhombus(rhombusBase, rhombusHeight);
    std::cout << rhombus.area() << "\n";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //2задание
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Car* car = new Car("LADA", "Granta");
    std::cout << "\n==============================";
    PassengerCar* passengerCar = new PassengerCar("Mersedes", "X5");
    std::cout << "\n==============================";
    Bus* bus = new Bus("PAZ", "3201");
    std::cout << "\n==============================";
    Minivan* minivan = new Minivan("Volkswagen", "Caravelle");
    std::cout << "\n==============================";
    delete minivan;
    std::cout << "\n==============================";
    delete bus;
    std::cout << "\n==============================";
    delete passengerCar;
    std::cout << "\n==============================";
    delete car;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //3задание


    Fraction f1(2, 3);
    Fraction f2(1, 3);
    Fraction f_result = f1 + f2;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 

    system("pause");
    return 0;
}


#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
// Добавить в контейнерный класс, который был написан в этом уроке, методы:
// для удаления последнего элемента массива(аналог функции pop_back() в векторах)
// для удаления первого элемента массива(аналог pop_front() в векторах)
// для сортировки массива
// для вывода на экран элементов.
using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;
    // для удаления последнего элемента массива(аналог функции pop_back() в векторах)
    void deleteLatEl()
    {
        a = m_length;
        for (int i = 0; i < m_length; i++)
            if (a[i] % 2 != 0)
                a[i] = a[m_length];
    }
    //для удаления первого элемента массива(аналог pop_front() в векторах)
    void deleteFrstEl()
    {
        s = m_length;
        int s[];
        for (i = 1; i <= m_length; i++)
            s += s[i];
    }
    // для сортировки массива для вывода на экран элементов.
    void quickSort()
    {
        int const lenD = m_length;
        int pivot = 0;
        int ind = lenD / 2;
        int i, j = 0, k = 0;
        if (lenD > 1) {
            int* L = new int[lenD];
            int* R = new int[lenD];
            pivot = data[ind];
            for (i = 0; i < lenD; i++) {
                if (i != ind) {
                    if (data[i] < pivot) {
                        L[j] = data[i];
                        j++;
                    }
                    else {
                        R[k] = data[i];
                        k++;
                    }
                }
            }
            quickSort(L, j);
            quickSort(R, k);
            for (int cnt = 0; cnt < lenD; cnt++) {
                if (cnt < j) {
                    data[cnt] = L[cnt];;
                }
                else if (cnt == j) {
                    data[cnt] = pivot;
                }
                else {
                    data[cnt] = R[cnt - (j + 1)];
                }
            }
        }
    }
    void printArrayInt()
    {

        for (int i = 0; i < m_length; i++)
        std::cout << m_length[i] << "\t";     //вывод на экран
        std::cout << std::endl;
        std::cin.get();
    }


    int getLength() { return m_length; }


public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }
    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt()
    {
        delete[] m_data;
    }

};

//Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.

int chis()
{
    return rand() % 10 + 1;
}

//Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: вектор указателей карт (удобно использовать вектор, 
// т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
// метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
// метод Clear, который очищает руку от карт
// метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).



class Hand
{
public:
    Hand();
    virtual ~Hand();
    // Добавляет карту в руку
    void Add(Card* pCard);
    // Очищает руку от карт
    void Clear();
    // Получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetValue() const;
protected:
    // Коллекция карт
    std::vector<Card*> m_Cards;
};

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    // Проходит по вектору, освобождая всю память в куче
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete* iter;
        *iter = nullptr;
    }
    // Очищает вектор указателей
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    // Если в руке нет карт
    if (m_Cards.empty())
    {
        return 0;
    }
    // Если первая карта имеет значение 0, то она лежит рубашкой вверх;
    // Вернуть значение 0
    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }
    // Находит сумму очков всех карт, каждый туз (Card::ACE == 1) дает 1 очко
    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }
    // Определяет. держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    // Если сумма очков всех карт в руке меньше 11
    // то туз учитывается, как 11 очков (1 + 10)
    if (containsAce && total <= 11)
    {
        total += 10;
    }

    return total;
}

int main()
{
    //2задние
    int N;
    cout << "N="; 
    cin >> N; //вводим длину вектора
    vector<int> v(N);
    generate(v.begin(), v.end(), chis);
    set<int> s(v.begin(), v.end());
    cout << "Total different numbers=" << s.size() << endl << "They are: ";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    system("pause");
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}



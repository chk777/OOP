// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

class Power {
protected:
    int x, y;
 
public:
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int calcucate()
    {
        int c;
        c = pow(x,y);

        return c;
    }
};

class RGBA {
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;

public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {}

    RGBA(unit8_t red, unit8_t green, unit8_t blue, unit8_t alpha) :
        m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

    void print()
    {
        std::cout << "(" << static_cast<int>(m_red) << ", ";
        std::cout << "(" << static_cast<int>(m_green) << ", ";
        std::cout << "(" << static_cast<int>(m_blue) << ", ";
        std::cout << "(" << static_cast<int>(m_alpha) << ") " << std::endl;
    }


};

class Stack {
public:
    init-deinit
        stack(int n)
        :size(n), items(0), insert_ind(-1)
    {
        if (n <= 0)
        {
            size = base_size;
        }

        data = new T[size];
    }

    stack()
        :data(nullptr), size(0), items(0), insert(-1){}

    ~stack
    {
        delete[] data;
    }

  access [1, 2]
        void push(T elem)
    {
        if (items == size || data == nullptr)
        {
            realloc();
        }

        data[++insert_ind] = elem;
        ++items;
    }
    T pop()
    {
        if (!items)
        {
            std::cerr << "\n\nStack emty. Returning base value of stack`s type.\n\n ";
        return T();
        }

        T temp = data[insert_ind--];
        --items;

        return temp;
    }

    void print()
    {
        std::cout << "(";
        if (items != 0)
        {
            for (int i = items - 1; i > -1; --i)
            {
                std::cout << data[i] << ", ";
            }
        }
        std::cout << ")\n";
    }

 other
     void reset()
 {
     if (data != nullptr)
     {
         size = 0;
         items = 0;
         insert_ind = -1;

         delete[] data;
         data = nullptr;
     }
 }

 int amount() 
     const { return itrms; }

 bool is_empty() 
     const { return items == 0; }


private:

    void realloc()
    {
        int new_size = size + 5;
        T* temp = new T[new_size];

        for (int i = 0; i < size; ++i)
        {
            temp[i] = data[i];
        }
        
        delete[] data;
        size = new_size;
        data = temp; 
    }

    T* data;

    static int base_size;
    int size;
    int items;
    int insert_ind;
};

int main()
{
    Power pt;
    pt.set(1, 4);

    return 0;
}

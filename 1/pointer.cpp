#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    char *name;
    Rectangle()
    {
        width = 5;
        height = 5;
        name = new char[10];
        strcpy(name, "My Rectangle");
    }
    Rectangle(int w, int h, char *n)
    {
        width = w;
        height = h;
        name = new char[10];
        strcpy(name, n);
    }
    ~Rectangle()
    {
        delete[] name;
        cout << "Destructor called" << endl;
    }
    void display() { cout << "Width: " << width << ", Height: " << height << name << endl; }
};

int main()
{
    char name[] = "Rectangle 1";
    Rectangle rect(10, 20, name);
    rect.display();
    return 0;
}
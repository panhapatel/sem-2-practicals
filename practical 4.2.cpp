#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:

    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }


    Point& move(int dx, int dy)
    {
        this->x = this->x + dx;
        this->y = this->y + dy;
        return *this;
    }


    void display()
    {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};


void update(Point *p)
{
    p->move(5, 5);
}

int main()
{
    Point p(1, 2);

    cout << "Original: ";
    p.display();


    p.move(2, 3).move(-1, 4);

    cout << "After Chain Move: ";
    p.display();


    update(&p);

    cout << "After Update: ";
    p.display();

    return 0;
}

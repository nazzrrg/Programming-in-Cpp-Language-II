#include <iostream>
#include <iomanip>
#include "task_4.h"
#include "circle.h"
#include "task_7.h"
#include "Matrix.h"

int main()
{
    // Task 4
    std::cout << std::endl << "Task 4:" << std::endl;
    float c = 12.345000000000;
    double d = 3.141592623794;
    std::cout << std::setprecision(15) << "Before: c = " << c << " d = " << d << std::endl;
    floory(&c);
    floory(&d);
    std::cout << "After pointers: c = " << c << " d = " << d << std::endl;
    c = 12.345000000000;
    d = 3.141592623794;
    floory(c);
    floory(d);
    std::cout << "After references: c = " << c << " c = " << d << std::endl;

    //Task 7
    std::cout << std::endl << "Task 7:" << std::endl;
    int a = 1;
    c = 12.345000000000;
    d = 3.141592623794;
    std::cout << std::setprecision(15) << "Before: a = " << a << " c = " << c <<" d = " << d << std::endl;
    minus(&a);
    minus(&c);
    minus(&d);
    std::cout << "After pointers: a = " << a << " c = " << c <<" d = " << d << std::endl;
    minus(a);
    minus(c);
    minus(d);
    std::cout << "After references: a = " << a << " c = " << c <<" d = " << d << std::endl;


    //Task 12
    std::cout << std::endl << "Task 12:" << std::endl;
    Circle cir(10, 0, 0);
    std::cout << "Before: x = " << cir.getCenterX() << " y = " << cir.getCenterY() << " r = " << cir.getRadius() << std::endl;
    moveCenter(&cir, 1, 1);
    std::cout << "After pointers: x = " << cir.getCenterX() << " y = " << cir.getCenterY() << " r = " << cir.getRadius() << std::endl;
    moveCenter(cir, -1, 1);
    std::cout << "After references: x = " << cir.getCenterX() << " y = " << cir.getCenterY() << " r = " << cir.getRadius() << std::endl;

    // Task 15
    std::cout << std::endl << "Task 15:" << std::endl;
    Matrix m(4, 3);
    std::cout << "Before: " << std::endl << m << std::endl;
    mat_mult(&m, 5);
    std::cout << "After pointers: " << std::endl << m << std::endl;
    mat_mult(m, 2);
    std::cout << "After references: " << std::endl << m << std::endl;

    return 0;
}

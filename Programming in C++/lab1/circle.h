#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H


class Circle {
private:
    struct Center{
        double x;
        double y;
    };
    Center center{};
    double radius;
public:
    Circle();
    Circle(double, double, double);
    double getRadius();
    void setRadius(double);
    double getCenterX();
    double getCenterY();
    void setCenter(double, double);
    double getLength();
    double getSquare();
};

void moveCenter(Circle&, double, double);
void moveCenter(Circle*, double, double);

#endif //LAB1_CIRCLE_H

//
// Created by Егор Назаров on 25.02.2020.
//

#ifndef LAB4_INTERFACE_H
#define LAB4_INTERFACE_H


#include <string>

class IGeoFig {
public:
    virtual double getSquare() const = 0;
    virtual double getPerimeter() const = 0;
};

class Vector2D {
public:
    double x, y;

    Vector2D (){
        x = y = 0;
    }
};

class IPhysObject {
public:
    virtual double getMass() const = 0;
    virtual Vector2D getPosition() const = 0;
    virtual bool operator==(const IPhysObject& ob) const = 0;
    virtual bool operator<(const IPhysObject& ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() const = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class IBaseObject {
public:
    virtual std::string getClassName() const = 0;
    virtual uint64_t getSize() const = 0;
};

class IFigure: public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public IBaseObject {};

class Rectangle : public IFigure {
private:
    const std::string name = "Rectangle";
    double a, b;
    double mass;
    Vector2D position{};
public:

    bool operator==(const IPhysObject& x) const override;

    bool operator<(const IPhysObject& x) const override;

    double getSquare() const override;

    double getPerimeter() const override;

    double getMass() const override;

    Vector2D getPosition() const override;

    void draw() const override;

    void initFromDialog() override;

    std::string getClassName() const override;

    uint64_t getSize() const override;

    Rectangle();

    Rectangle(const double& a_, const double& b_,
              const double& mass_, const Vector2D& position_);

    Rectangle(const Rectangle& x);
};

class Trapeze : public IFigure {
private:
    const std::string name = "Trapeze";
    double a, b;
    double mass;
    Vector2D position{};
public:

    bool operator==(const IPhysObject& x) const override;

    bool operator<(const IPhysObject& x) const override;

    double getSquare() const override;

    double getPerimeter() const override;

    double getMass() const override;

    Vector2D getPosition() const override;

    void draw() const override;

    void initFromDialog() override;

    std::string getClassName() const override;

    uint64_t getSize() const override;

    Trapeze();

    Trapeze(const double& a_, const double& b_,
              const double& mass_, const Vector2D& position_);

    Trapeze(const Rectangle& x);
};


#endif //LAB4_INTERFACE_H

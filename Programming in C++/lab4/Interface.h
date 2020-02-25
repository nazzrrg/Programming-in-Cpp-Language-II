//
// Created by Егор Назаров on 25.02.2020.
//

#ifndef LAB4_INTERFACE_H
#define LAB4_INTERFACE_H


#include <string>

class IGeoFig {
public:
    [[nodiscard]] virtual double getSquare() const = 0;
    [[nodiscard]] virtual double getPerimeter() const = 0;
};

class Vector2D {
public:
    double x, y;

    Vector2D (){
        x = y = 0;
    }
    Vector2D (double x_, double y_){
        x = x_;
        y = y_;
    }
};

class IPhysObject {
public:
    [[nodiscard]] virtual double getMass() const = 0;
    [[nodiscard]] virtual Vector2D getPosition() const = 0;
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
    [[nodiscard]] virtual std::string getClassName() const = 0;
    [[nodiscard]] virtual uint64_t getSize() const = 0;
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

    [[nodiscard]] double getSquare() const override;

    [[nodiscard]] double getPerimeter() const override;

    [[nodiscard]] double getMass() const override;

    [[nodiscard]] Vector2D getPosition() const override;

    void draw() const override;

    void initFromDialog() override;

    [[nodiscard]] std::string getClassName() const override;

    [[nodiscard]] uint64_t getSize() const override;

    Rectangle();

    Rectangle(const double& a_, const double& b_,
              const double& mass_, const Vector2D& position_);

    Rectangle(const Rectangle& x);
};

class Trapeze : public IFigure {
private:
    const std::string name = "Trapeze";
    double a, b, h;
    double mass;
    Vector2D position{};
public:

    bool operator==(const IPhysObject& x) const override;

    bool operator<(const IPhysObject& x) const override;

    [[nodiscard]] double getSquare() const override;

    [[nodiscard]] double getPerimeter() const override;

    [[nodiscard]] double getMass() const override;

    [[nodiscard]] Vector2D getPosition() const override;

    void draw() const override;

    void initFromDialog() override;

    [[nodiscard]] std::string getClassName() const override;

    [[nodiscard]] uint64_t getSize() const override;

    Trapeze();

    Trapeze(const double& a_, const double& b_, const double& h_,
            const double& mass_, const Vector2D& position_);

    Trapeze(const Trapeze& x);
};


#endif //LAB4_INTERFACE_H

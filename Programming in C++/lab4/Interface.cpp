//
// Created by Егор Назаров on 25.02.2020.
//
#include <iostream>
#include <cmath>
#include "Interface.h"
bool Rectangle::operator==(const IPhysObject& x) const {
    return getMass() == x.getMass();
}

bool Rectangle::operator<(const IPhysObject& x) const {
    return getMass() < x.getMass();
}

double Rectangle::getSquare() const {
    return a * b;
}

double Rectangle::getPerimeter() const {
    return (a + b) * 2.;
}

double Rectangle::getMass() const {
    return mass;
}

Vector2D Rectangle::getPosition() const {
    return position;
}

void Rectangle::draw() const {
    std::cout << "Name = " << name << std::endl <<"a = " << a << ", b = " << b << std::endl;
    std::cout << "Mass = " << mass << std::endl << "size = " << getSize() << std::endl;
    std::cout << "Position: x = " << position.x << ", y = " << position.y << std::endl << std::endl;
}

void Rectangle::initFromDialog() {
    double a_, b_, mass_;
    Vector2D position_;
    std::cout << "Enter Rectangles sides: a, b; Then enter mass and position (x and y)" << std::endl;
    std::cin >> a_ >> b_ >> mass_ >> position_.x >> position_.y;
    a = a_; b = b_;
    mass = mass_;
    position = position_;
    std::cout << "Created successfully." << std::endl;
}

std::string Rectangle::getClassName() const {
    return name;
}

uint64_t Rectangle::getSize() const {
    return sizeof(*this);
}

Rectangle::Rectangle() {
    a = b = mass = 0;
    position.x = position.y = 0;
}

Rectangle::Rectangle(const double& a_, const double& b_, const double& mass_, const Vector2D& position_) {
    a = a_; b = b_;
    mass = mass_;
    position = position_;
}

Rectangle::Rectangle(const Rectangle& x) {
    a = x.a, b = x.b;
    mass = x.mass;
    position = x.position;
}



bool Trapeze::operator==(const IPhysObject& x) const {
    return getMass() == x.getMass();
}

bool Trapeze::operator<(const IPhysObject& x) const {
    return getMass() < x.getMass();
}

double Trapeze::getSquare() const {
    return (a + b) * h / 2;
}

double Trapeze::getPerimeter() const {
    return (a + b) + 2 * std::sqrt((a-b)*(a-b)/4 + h*h);
}

double Trapeze::getMass() const {
    return mass;
}

Vector2D Trapeze::getPosition() const {
    return position;
}

void Trapeze::draw() const {
    std::cout << "Name = " << name << std::endl <<"a = " << a << ", b = " << b << ", h = " << h << std::endl;
    std::cout << "Mass = " << mass << std::endl << "size = " << getSize() << std::endl;
    std::cout << "Position: x = " << position.x << ", y = " << position.y << std::endl << std::endl;
}

void Trapeze::initFromDialog() {
    double a_, b_, h_, mass_;
    Vector2D position_;
    std::cout << "Enter Trapeze's sides: a, b; Height: h; Then enter mass and position (x and y)" << std::endl;
    std::cin >> a_ >> b_ >> h_ >> mass_ >> position_.x >> position_.y;
    a = a_; b = b_; h = h_;
    mass = mass_;
    position = position_;
    std::cout << "Created successfully." << std::endl;
}

std::string Trapeze::getClassName() const {
    return name;
}

uint64_t Trapeze::getSize() const {
    return sizeof(*this);
}

Trapeze::Trapeze() {
    a = b = h = mass = 0;
    position.x = position.y = 0;
}

Trapeze::Trapeze(const double& a_, const double& b_, const double& h_, const double& mass_, const Vector2D& position_) {
    a = a_; b = b_; h = h_;
    mass = mass_;
    position = position_;
}

Trapeze::Trapeze(const Trapeze& x) {
    a = x.a, b = x.b; h = x.h;
    mass = x.mass;
    position = x.position;
}

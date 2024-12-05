//
// Created by mckeem on 12/5/2024.
//

#ifndef SHAPES_H
#define SHAPES_H
#include <string.h>
// Concrete product class - Circle
// Abstract product classAdvantages of the Factory Method
/*
Below are the main advantages of factory method design pattern: Separates
creation logic from client code, improving flexibility
.
New product types can be added easily
.
Simplifies unit testing by allowing mock product creation
.
Centralizes object creation logic across the application
.
Hides specific product classes from clients, reducing dependency
.
Disadvantages of the Factory
Method
Below are the main advantages of factory method design pattern: Adds
more classes and interfaces, which can complicate maintenance
.
Slight performance impacts due to polymorphism
.
Concrete creators are linked to their products
.
Clients need knowledge of specific subclasses
.
May lead to unnecessary complexity
if
 applied too broadly
.
Factory logic can be harder to test
*/
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {} // Virtual destructor for polymorphism
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout<<"Drawing a Circle"<< std::endl;
    }
};

// Concrete product class - Square
class Square : public Shape {
public:
    void draw() override {
        std::cout<<"Drawing a Square"<<std::endl;
    }
};

// Abstract creator class
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {} // Virtual destructor for polymorphism
};

// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};

class RandomFactory {
public:
    // Will return random shape
    Shape * randomShape(const char *strShapeType) {
        if (strcmp("Circle", strShapeType) == 0) {
            return new Circle();
        }
        else if (strcmp("Square", strShapeType) == 0) {
            return new Square();
        }
        else {
            return nullptr;
        }
    }
};

#endif //SHAPES_H

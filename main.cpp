#include <iostream>
#include "Shapes.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    circle->draw(); // Output: Drawing a Circle
    square->draw(); // Output: Drawing a Square
    delete circleFactory;
    delete squareFactory;
    delete circle;

    // Lets build a factory without knowing ANYTHING about Circle or Square
    // We will let the factory figure it out. Perhaps we'll use a random  number

    RandomFactory* randomFactoryObj = new RandomFactory();
    randomFactoryObj->randomShape("Circle");
    randomFactoryObj->randomShape("Square");
    return 0;
}

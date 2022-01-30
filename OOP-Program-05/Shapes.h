//Catherine Stringfellow  AND Zachary Kingcade
//Shapes.h declares AND DEFINES an inheritance hierarchy of shapes: Shape, Oval, Circle, Rectangle, Square

#pragma once
#include <iostream>
#include <string>
using namespace std;

//Abstract class Shape - has a name only
class Shape {
  public:
    //Constructors & Destructor
	Shape() {name = "Shape";}
	Shape(string s) { name = s;}
	Shape (const Shape & other) {name = other.name;}
	~Shape();
	
	//getters and setters
	string getName() { return name; }
	void setName(string s) { name = s; }
	
	//methods to override
	virtual double getArea() = 0;
	virtual string toString() {return "Shape is " + name + ".\t Area is undeterminable.\n";}

  private:
	string name;
};

class Rect : public Shape{
public:
	//---------Constructors and Destructor----------
	Rect():Shape("Rectangle"){}
	Rect(string name,int length, int width):Shape(name){this->length = length;this->width = width;}
	Rect(Rect &other):Shape(other.getName()){length = other.length; width = other.width;}
	~Rect(){};

	//----------Getters/Setters----------
	double getWidth(){return width;}
	void setWidth(double width){this->width = width;}
	double getLength(){return length;}
	void SetLength(double length){this->length = length;}

	//----------Methods being Overridden---------
	double getArea(){return length * width;}
	string toString(){return "Shape is " + getName() + ".\t Area is " + to_string(getArea()) + '.';}	

	//----------Memeber Data----------
private:
	double width;
	double length;
};

class Square : public Shape {
public:
	//---------Constructors and Destructor----------
	Square(){setName("Square");}
	Square(string name, double length):Shape(name){this->length = length;}
	Square(Square &other):Shape(other.getName()){length = other.length;}
	~Square(){}

	//----------Getters/Setters---------
	double getLength(){return length;}
	void SetLength(double length){this->length = length;}

	//----------Methods being Overridden----------
	virtual double getArea(){return length * length;}
	string toString(){return "Shape is " + getName() + ".\t Area is " + to_string(getArea()) + '.';}	


	//---------member varibles---------
private:
	double length;
};

class Oval : public Shape {
public:
	Oval():Shape("Oval"){}
	Oval(string s, double l, double w) :Shape(s) { len = l; wid = w; }
	Oval ( Oval &other):Shape(other.getName()) {len = other.len; wid = other.wid;}
	virtual double getArea() { return len * wid * 3.14; }
	virtual string toString() { return "Shape is " + getName() + ".   \t Area is " + to_string(getArea()) + '.';}
private:
	double len, wid;
};

class Circle : public Shape {
public:
	//---------Constructors and Destructor----------
	Circle(string name):Shape(name){}
	Circle(string name, double radius):Shape(name){this->radius = radius;}
	Circle(Circle &other):Shape(other.getName()){radius = other.radius;}
	~Circle(){}

	//----------Getters/Setters----------
	double getRadius(){return radius;}
	void setRadius(double radius){this->radius = radius;}

	//----------Methods being Overridden---------
	virtual double getArea(){return 3.14 * (radius * radius);}
	string toString(){return "Shape is " + getName() + ".\t Area is " + to_string(getArea()) + '.';}	

	//----------Memeber Data---------
private:
	double radius;
};


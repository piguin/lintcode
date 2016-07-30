/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/shape-factory
@Language: C++
@Datetime: 16-07-28 08:20
*/

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
    virtual void draw() const {
        cout << " ---- " << endl;
        cout << "|    |" << endl;
        cout << " ---- " << endl;
    }
};

class Square: public Shape {
    virtual void draw() const {
        cout << " ---- " << endl;
        cout << "|    |" << endl;
        cout << "|    |" << endl;
        cout << " ---- " << endl;
    }
};

class Triangle: public Shape {
    virtual void draw() const {
        cout << "  /\\  " << endl;
        cout << " /  \\ " << endl;
        cout << "/____\\" << endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        if (shapeType == "Square")
            return new Square();
        else if (shapeType == "Triangle")
            return new Triangle();
        else if (shapeType == "Rectangle")
            return new Rectangle();
    }
};





/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/toy-factory
@Language: C++
@Datetime: 16-07-28 08:15
*/

/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    virtual void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    virtual void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        if (type == "Dog") {
            return new Dog();
        }
        else if (type == "Cat") {
            return new Cat();
        }
        return NULL;
    }
};
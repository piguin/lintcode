/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-07-25 19:03
*/

class MinStack {
public:
    std::vector<int> mins;
    std::vector<int> elems;

    MinStack() {
    }
    
    void push(int number) {
        elems.push_back(number);
        
        if (mins.size() == 0 || mins.back() >= number) {
            mins.push_back(number);
        }
    }

    int pop() {
        int back = elems.back();
        elems.pop_back();
        
        if (back == mins.back()) {
            mins.pop_back();
        }
        
        return back;
    }

    int min() {
        return mins.back();
    }
};

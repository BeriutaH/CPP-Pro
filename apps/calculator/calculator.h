//
// Created by Beriuta on 2024/6/14.
//

#ifndef CPPNEW_CALCULATOR_H
#define CPPNEW_CALCULATOR_H

// 计算器抽象类
class AbstractCalculator {
public:
    explicit AbstractCalculator(int num1 = 0, int num2 = 0): c_num1(num1), c_num2(num2) {}
    virtual ~AbstractCalculator() = default;  // 虚析构函数  如果该基类没有虚析构函数，会导致未定义行为
    virtual int get_result() = 0;  // 纯虚函数
    int c_num1;
    int c_num2;
};

// 加法
class AddCalculator: public AbstractCalculator {
public:
    using AbstractCalculator::AbstractCalculator;  // 继承构造函数
    int get_result() override;
};
// 减法
class SubCalculator: public AbstractCalculator {
public:
    using AbstractCalculator::AbstractCalculator;  // 继承构造函数
    int get_result() override;
};
// 乘法
class MultiplicationCalculator: public AbstractCalculator {
public:
    using AbstractCalculator::AbstractCalculator;  // 继承构造函数
    int get_result() override;
};



#endif //CPPNEW_CALCULATOR_H

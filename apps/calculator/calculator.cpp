//
// Created by Beriuta on 2024/6/14.
//

#include "calculator.h"

int AddCalculator::get_result() {
    return c_num1 + c_num2;
}

int SubCalculator::get_result() {
    return c_num1 - c_num2;
}

int MultiplicationCalculator::get_result() {
    return c_num1 * c_num2;
}

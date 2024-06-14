//
// Created by Beriuta on 2024/6/14.
//

#include "drinks.h"

void Tea::boil() {
    cout << "煮收集的清晨的露水" << endl;
}

void Tea::brew() {
    cout << "冲泡茶叶" << endl;
}

void Tea::pour_in_cup() {
    cout << "将茶水倒入杯中" << endl;
}

void Tea::put_sth() {
    cout << "加入枸杞" << endl;
}

void Coffee::boil() {
    cout << "煮龙泉水" << endl;
}

void Coffee::brew() {
    cout << "冲泡咖啡" << endl;
}

void Coffee::pour_in_cup() {
    cout << "将咖啡倒入杯中" << endl;
}

void Coffee::put_sth() {
    cout << "加入糖喝牛奶" << endl;
}

void do_work(Drinks* drink) {
    drink->make_drink();
    delete drink;
}

//
// Created by Beriuta on 2024/6/14.
//

#ifndef CPPNEW_DRINKS_H
#define CPPNEW_DRINKS_H


class Drinks {
public:
    virtual ~Drinks() = default;
    virtual void boil() = 0;  // 煮茶
    virtual void brew() = 0;  // 冲泡
    virtual void pour_in_cup() = 0;  // 倒入杯中
    virtual void put_sth() = 0;  // 加入辅料
    // 制作饮品
    virtual void make_drink() {
        boil();
        brew();
        pour_in_cup();
        put_sth();
    }
};

class Tea: public Drinks {
public:
    using Drinks::Drinks;
    void boil() override;
    void brew() override;
    void pour_in_cup() override;
    void put_sth() override;
};

class Coffee: public Drinks {
public:
    using Drinks::Drinks;
    void boil() override;
    void brew() override;
    void pour_in_cup() override;
    void put_sth() override;
};
// 统一加工
void do_work(Drinks* drink);


#endif //CPPNEW_DRINKS_H

#include <iostream>


class Strategy {
public:
    virtual ~Strategy() {}
    virtual void execute() const = 0;
};


class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "��������� ������㳿 A" << std::endl;
    }
};


class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "��������� ������㳿 B" << std::endl;
    }
};


class Context {
private:
    Strategy* strategy;
public:
    Context(Strategy* strategy = nullptr) : strategy(strategy) {}

    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }

    void executeStrategy() const {
        if (strategy) {
            strategy->execute();
        }
        else {
            std::cout << "�������� �� �����������" << std::endl;
        }
    }
};

int main() {
    Context context;


    ConcreteStrategyA strategyA;
    context.setStrategy(&strategyA);
    context.executeStrategy();


    ConcreteStrategyB strategyB;
    context.setStrategy(&strategyB);
    context.executeStrategy();

    return 0;
}

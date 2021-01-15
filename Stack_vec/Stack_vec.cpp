
#include <iostream>
#include <vector>
#include<thread>

typedef int func(void);
std::vector<func*> functions;

class FunMembers {
public:
    void addFuncToVec(func* f, std::vector<func*>& vect) {
        vect.push_back(f);
    }
    FunMembers() {
        func* f = (func*)0x000000;
    }
};
int getA() {
    std::cout << "GetA" << std::endl;
    return 0;
}

int getB() {
    std::cout << "GetB" << std::endl;
    return 0;
}
int getC() {
    std::cout << "GetC" << std::endl;
    return 0;
}
int getD() {
    std::cout << "GetD" << std::endl;
    return 0;
}
int getE() {
    std::cout << "GetE" << std::endl;
    return 0;
}

int nothing() {
    std::cout << " Nothing" << std::endl;
    return 0;
}

int main()
{

    std::unique_ptr<FunMembers> fm;
    fm->addFuncToVec(getA,functions);
    fm->addFuncToVec(getB, functions);
    fm->addFuncToVec(getC, functions);
    fm->addFuncToVec(getD, functions);
    fm->addFuncToVec(getE, functions);

    for (auto funcs : functions) {
        funcs();
    }
   
}


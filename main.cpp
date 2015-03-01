#include "train.h"
#include <cstdio>
using namespace std;

int main(int argc, char const* argv[])
{
    train train(5, 40);
    for (int i = 0; i < 20; i++){
        train.display();
        train.move(19);
    }
    train.setDirection(1);
    for (int i = 0; i < 20; i++){
        train.display();
        train.move(1);
    }
    return 0;
}

#include "train.h"
#include <cstdio>

int main(int argc, char const* argv[])
{
    train train(3, 12);
    for (int i = 0; i < 20; i++){
        train.display();
        train.move(2);
    }
    train.setDirection(1);
    for (int i = 0; i < 20; i++){
        train.display();
        train.move(2);
    }
    return 0;
}

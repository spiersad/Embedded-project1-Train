#include <cstdio>
#include <stdexcept>
using namespace std;

long int mod(long int a, long int b){
    long int c = a % b;
    if (c < 0)
        c = c + b;
    return c;
}

class train {
    int trainLength, speed, trackLength, trainHead;
    bool direction;
    int* trainArray;
    void initialize(int x);
  public:
    train();
    train(int trainLength, int trackLength);
    void move(int distance);
    void display();
    void setSpeed(int speed);
    void setDirection(int direction);
    int getTrainLength();
    int getTrackLength();
    int getSpeed();
    int getDirection();
};

train :: train() {
    trainLength = 3;
    trainHead = 3;
    direction = 0;
    speed = 1;
    trackLength = 16;
    initialize(trackLength);
    for (int i = 0; i < trainLength; i++){
        trainArray[i] = 1;
    }
}

train :: train(int x, int y) {
    if (x >= y)
        throw invalid_argument("train must be longer than the track");
    trainLength = x;
    trainHead = x;
    direction = 0;
    speed = 1;
    trackLength = y;
    initialize(trackLength);
    for (int i = 0; i < trainLength; i++){
        trainArray[i] = 1;
    }
}

void train::initialize(int x){
    trainArray = new int[x];
    for (int i = 0; i < x; i++)
        trainArray[i] = 0;
}

void train::display(){
    for (int i = 0; i < trackLength; i++){
        if (trainArray[i] == 1)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

void train::move(int distance){
    distance = mod(distance, trackLength);
    if (direction == 0){
        for (int i = trainHead; i < trainHead + distance; i++){
            trainArray[mod(i, trackLength)] = 1;
        }

        for (int i = trainHead - trainLength; i < trainHead - trainLength + distance; i++){
            trainArray[mod(i, trackLength)] = 0;
        }
    trainHead = trainHead + distance;
    }

    else if (direction == 1) {
        for (int i = trainHead; i > trainHead - distance; i--){
            trainArray[mod(i, trackLength)] = 1;
        }

        for (int i = trainHead + trainLength; i > trainHead + trainLength - distance; i--){
            trainArray[mod(i, trackLength)] = 0;
        }
    trainHead = trainHead - distance;
    }
}

void train::setDirection(int x){
    if (direction == 0 && x == 1){
        trainHead = trainHead - trainLength;
    }
    else if (direction == 1 && x == 0){
        trainHead = trainHead + trainLength;
    }
    direction = x;
}
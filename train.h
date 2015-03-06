#include <cstdio>
#include <stdexcept>

class train {
  private:
    int trainLength, trackLength, trainHead;
    bool direction;
    int* trainArray;
    void initialize(int trackLength, int trainLength);
    long int mod(long int a, long int b);
  public:
    train();
    train(int trainLength, int trackLength);
    void move(int distance);
    void display();
    void setDirection(int direction);
    int getTrainLength();
    int getTrackLength();
    int getDirection();
};

train :: train() {
    trainLength = 3;
    trainHead = 3;
    direction = 0;
    trackLength = 16;
    initialize(trackLength, trainLength);
}

train :: train(int x, int y) {
    if (x >= y)
        throw std::invalid_argument("train must be longer than the track");
    trainLength = x;
    trainHead = x;
    direction = 0;
    trackLength = y;
    initialize(trackLength, trainLength);
}

void train::initialize(int x,int y){
    trainArray = new int[x];
    for (int i = 0; i < x; i++)
        trainArray[i] = 0;
    for (int i = 0; i < y; i++){
        trainArray[i] = 1;
    }
}

long int train::mod(long int a, long int b){
    long int c = a % b;
    if (c < 0)
        c = c + b;
    return c;
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
//    distance = mod(distance, trackLength);
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

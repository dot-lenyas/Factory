#include <iostream>
#include <vector>

using namespace std;

enum VideoCard {
    GTX1050,
    GTX1060,
    GTX1070,
    GTX1080,
    GTX1670,
    GTX1680,
    GTX3080,
};
string GetKindOfVideoCard(VideoCard KindOfVideoCard) {
    switch(KindOfVideoCard) {
        case VideoCard::GTX1050:
            return "GTX1050";
        case VideoCard::GTX1060:
            return "GTX1060";
        case VideoCard::GTX1070:
            return "GTX1070";
        case VideoCard::GTX1080:
            return "GTX1080";
        case VideoCard::GTX1670:
            return "GTX1670";
        case VideoCard::GTX1680:
            return "GTX1680";
        case VideoCard::GTX3080:
            return "GTX3080";
    }
}

class Computer {
    string model;
    string firm;
    VideoCard KindOfVideoCard;
    unsigned int OpMemory;
    unsigned int VideoMemory;
public:
    Computer(string model, string firm, unsigned int OpMemory,VideoCard KindOfVideoCard, unsigned int VideoMemory ):
        model(model), firm(firm), OpMemory(OpMemory),KindOfVideoCard(KindOfVideoCard), VideoMemory(VideoMemory) {

    }
    const string &getModel() const {
        return model;
    }
    const string &getFirm() const {
        return firm;
    }
    VideoCard GetKindOfVideoCard() const {
        return KindOfVideoCard;
    }

    string getDescription() {
        return firm + " " + model + " " + to_string(OpMemory) + "gb, " + ::GetKindOfVideoCard(KindOfVideoCard) + " " +  to_string(VideoMemory) + "gb";
    }
    static Computer *createAsusLapTop() {
        return new Computer("LapTop", "Asus", 16,VideoCard::GTX1060, 4);
    }
    static Computer *createHyperXComputer(unsigned  int OpMemory = 16, VideoCard KindOfVideoCard = VideoCard::GTX1680 ) {
        return new Computer("PC","HyperX",OpMemory,KindOfVideoCard, 8);
    }
    static Computer *createMacBookComputer(unsigned  int OpMemory = 8) {
        return new Computer("MacBook", "Apple",OpMemory,VideoCard::GTX1080,2);
    }

};
int main() {
    vector<Computer *> ComputerOne;

    ComputerOne.push_back(Computer::createAsusLapTop());
    ComputerOne.push_back(Computer::createHyperXComputer(32, VideoCard::GTX3080));
    ComputerOne.push_back(Computer::createMacBookComputer(32));
    for (int i = 0; i <=3; i++) {
        ComputerOne.push_back(Computer::createHyperXComputer(i+4, VideoCard::GTX3080));
    }
    //Вывод первых пяти в ComputerOne
    cout << "Computer1: " << endl;
    for (int i = 0; i<=6; i++) {
        cout << ComputerOne[i]->getDescription() << endl;
    }


    return 0;
}

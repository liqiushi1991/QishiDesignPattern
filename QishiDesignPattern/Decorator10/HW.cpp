#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Flower
{
    virtual string str() = 0;
};

struct Rose : Flower
{
    Rose(){}
    string str() override {
        // todo
        return "A rose";
    }
};

struct RedFlower : Flower
{
    string color = "red";
    Flower& fl;
    RedFlower(Flower& fl) : fl(fl){}
    string str() override{
        ostringstream oss;
        oss << fl.str();
        if (fl.str().find("that is") == string::npos)
            oss << " that is " << color;
        else if (fl.str().find(color) == string::npos)
            oss << " and " << color;
        return oss.str();
    }
};

struct BlueFlower : Flower
{
    string color = "blue";
    Flower& fl;
    BlueFlower(Flower& fl) : fl(fl){}
    string str() override{
        ostringstream oss;
        oss << fl.str();
        if (fl.str().find("that is") == string::npos)
            oss << " that is " << color;
        else if (fl.str().find(color) == string::npos)
            oss << " and " << color;
        return oss.str();
    }
};

int main()
{
    Rose rose;
    RedFlower red_rose{rose};
    RedFlower red_red_rose{red_rose};
    BlueFlower blue_red_rose{red_rose};
    
    cout << rose.str();
    cout << red_rose.str();
    cout << red_red_rose.str();
    cout << blue_red_rose.str();
}

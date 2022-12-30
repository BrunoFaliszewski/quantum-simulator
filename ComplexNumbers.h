#include <iostream>

using namespace std;

class CN {
    public:
        double x, y;
        CN(double x_, double y_) : x(x_), y(y_) {};
        void print();
        CN conjugate();
        CN operator+(const CN& other) const;
        CN operator-(const CN& other) const;
        CN operator*(const CN& other) const;
        CN operator/(const CN& other) const;
        bool operator==(const CN& other) const;
        bool operator!=(const CN& other) const;
};

void CN::print() {
    if (x!=0 && y>0) {
        cout << x << "+" << y << "i";
    } else if (x!=0 && y<0) {
        cout << x << y << "i";
    }  else if (x==0 && y!=0) {
        cout << y << "i";
    } else if (y==0) {
        cout << x;
    }
    return;
}

CN CN::conjugate() {
    return CN(x, y*-1.0);
}

CN CN::operator+(const CN& other) const {
    return CN(x + other.x, y + other.y);
}

CN CN::operator-(const CN& other) const {
    return CN(x - other.x, y - other.y);
}

CN CN::operator*(const CN& other) const {
    return CN((x*other.x)-(y*other.y), (x*other.y)+(other.x*y));
}

CN CN::operator/(const CN& other) const {
    return CN(((x*other.x)+(y*other.y))/(other.x*other.x+other.y*other.y), ((y*other.x)-(x*other.y))/(other.x*other.x+other.y*other.y));
}

bool CN::operator==(const CN& other) const {
    return x == other.x && y == other.y;
}

bool CN::operator!=(const CN& other) const {
    return x != other.x || y != other.y;
}
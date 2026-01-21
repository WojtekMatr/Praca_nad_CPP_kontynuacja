#ifndef MY_FUNCTION
#define MY_FUNCTION

void wydrukuj(int i);
struct Punkt {
    double a;
    double b;
    bool operator<(const Punkt& inny) const {
        if (a != inny.a) {
            return a < inny.a;
        }
        return b < inny.b;
    }
};








#endif

#include "LogCon.h"

bool Not(bool a){ // return !a
    if (a){
        return false;
    }
    return true;
}

bool And(bool a, bool b){ // return a && b;
    if (a){
        if (b){
            return true;
        }
    }
    return false;
}

bool Or(bool a, bool b){ // return a || b;
    if (a){
        return true;
    }else if (b){
        return true;
    } 
    return false;
}

bool If(bool a, bool b){ // if (a) {return b;} else {return !b;}
    if (a){
        return b;
    }
    return Not(b);
}

bool Xnor(bool a, bool b){ // return a==b;
    if (a) {
        if (b) {
            return true;
        }
        return false;
    } else if (b) {
        return false;
    }
    return true;
}
bool Xor(bool a, bool b){ // return a!=b;
    if (a) {
        if (b) {
            return false;
        }
        return true;
    } else if (b) {
        return true;
    }
    return false;
}
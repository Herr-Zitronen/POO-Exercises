#include <iostream>
#include <vector>

struct Rectangle{
    int x1, x2, y1, y2;
};

bool existeInterseccion(const Rectangle& A, const Rectangle& B){
    // X: Si x1 de A es menor que x2 de B, y, x2 de A mayor a x1 de B;
    // Y: Si y1 de A es menor que y2 de B, y y2 de A es mayor que y1 de B;
    
    /*
    
    if(A.x1 < B.x2 && A.x2 > B.x1){
        if(A.y1 < B.y2 && A.y2 > B.y1){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

    */

    return (A.x1 < B.x2 && A.x2 > B.x1 && A.y1 < B.y2 && A.y2 > B.y1);
}

int main(){

    return 0;
}
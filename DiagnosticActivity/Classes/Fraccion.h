#include <iostream>

using namespace std;


class Fraccion{
    int numerador;
    int denominador;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce(){
        numerador /= gcd(numerador,denominador);
        denominador /= gcd(numerador,denominador);
    }

    
    public:
    Fraccion(int num = 0, int den = 1){

        numerador = num;
        denominador = den;
        reduce();
    }

    void setNumerador(int num){
        numerador = num;
        reduce();
    }

    void setDenominador(int num){
        if (num != 0 ){
            numerador = num;
            reduce();
        }
        else{
            throw "Denominador no puede ser 0";
        };
    };

    int getNumerador(){
        return numerador;
    }

    int getDenominador(){
        return denominador;
    }


    void sum(Fraccion frac){

        int tempDen = denominador*frac.denominador;
        int tempNum = (numerador*frac.denominador)+(denominador*frac.numerador);
        
        numerador = tempNum;
        denominador = tempDen;

        reduce();
        
    }

    void print(){
        cout << to_string(numerador) + "/" + to_string(denominador) << endl;  
    }


};
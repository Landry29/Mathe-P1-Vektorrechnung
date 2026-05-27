#pragma once 
#include <iostream> 
#include <vector> 
#include <math.h> 


class CMyVektor
{
private:

    int dimension = 0;
    std::vector<double> vektor;

public:

    CMyVektor() {}
    CMyVektor(int dim) : dimension{ dim } {

        for (int i = 0; i < dimension; i++) {
            vektor.push_back(0);
        }
    }

    std::vector<double> get_vector() { return vektor; }

    void vektor_anlegen(int dimension);

    int const get_dimension() { return dimension; }; 

    void set_component(int component, double wert);

    double const get_component(int component) { return vektor[component - 1]; };

    void vektorAusgeben();

    double length();

    CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x));

    CMyVektor grad_verfahren(CMyVektor x, double lam, double (*funktion)(CMyVektor x));
};

CMyVektor operator+(CMyVektor a, CMyVektor b);

CMyVektor operator*(double lambda, CMyVektor a);

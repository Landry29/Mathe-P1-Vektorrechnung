#include "CMyVektor.h" 

void CMyVektor::vektor_anlegen(int dim) {

    dimension = dim;

    for (int i = 0; i < dimension; i++) {
        vektor.push_back(0);
    }
}

void CMyVektor::set_component(int component, double wert) {
    if (component > dimension) {
        std::cout << "Dimension existiert nicht!";
        return;
    }
    vektor[component - 1] = wert;

}
void CMyVektor::vektorAusgeben() {
    std::cout << "(";
    for (int i = 0; i < dimension; i++) {
        if (i == dimension-1) {
            std::cout << " " << vektor[i];
        }

        else {

            std::cout << " "<<vektor[i] << ";";// << std::endl;
        }
    }
    std::cout << ")";
}

double CMyVektor::length() {            // wurzel(x1^2 + xn^2) alle Komponenten des Vektors quadrieren,addieren und wurzel vom ganzen

    double mul = 0;                      

    for (int i = 0; i < dimension; i++) {
        mul += (vektor[i]) * (vektor[i]);
    }

    return (sqrt(mul));

}

CMyVektor operator+(CMyVektor a, CMyVektor b) {

    CMyVektor c;

    c.vektor_anlegen(a.get_dimension());

    for (int i = 0; i < c.get_dimension(); i++) {

        double x = ((a.get_vector())[i]) + ((b.get_vector())[i]);
        c.set_component(i + 1, x);
    }
    return c;
}

CMyVektor operator*(double lambda, CMyVektor a) {

    for (int i = 0; i < a.get_dimension(); i++) {
        double x = ((a.get_vector())[i]) * lambda;
        a.set_component(i + 1, x);
    }
    return a;
}

CMyVektor CMyVektor::gradient(CMyVektor x, double (*funktion)(CMyVektor x)) {
   
    double h = 1e-8;       //pow(10, -8);
    const int dim = x.dimension;
    

    CMyVektor grad, tmp1, tmp2;

    tmp1.vektor_anlegen(dim);
    tmp2.vektor_anlegen(dim);
    grad.vektor_anlegen(dim);
    double fx = funktion(x);


    for (int i = 0; i < dim; i++) {
        tmp1.set_component(i + 1, x.get_component(i + 1));
    }

    for (int i = 0; i < dim; i++) {
        tmp1.set_component(i + 1, (x.get_component(i + 1)) + h); //  auf die jeweilige compotents h addieren  

        tmp2.set_component(i + 1, funktion(tmp1)); // Funktionswert mit dem jewiligen h wert calculieren 

        tmp1.set_component(i + 1, x.get_component(i + 1)); // tmp1 zurücksetzen , um die naechste components mit h addieren zu können
    }

    for (int i = 0; i < dim; i++) {
        grad.set_component(i + 1, ((tmp2.get_component(i + 1)) - fx) / h);
    }

    return grad;
}


CMyVektor CMyVektor::grad_verfahren(CMyVektor x, double lam, double (*funktion)(CMyVektor x)) {
        CMyVektor grad;
    CMyVektor x_neu;

    grad.vektor_anlegen(x.get_dimension());
    x_neu.vektor_anlegen(x.get_dimension());

    double fx = funktion(x);
    double fx_neu = 0;
    double fx_test = 0;

    double lambda = lam;

    double length_grad = 0;

    for (int j = 0; j < 26; j++) {

        grad = grad.gradient(x, funktion);
       
        length_grad = grad.length();

            if (length_grad < 1e-5 ) {               

            std::cout << "Ende wegen ||grad f(x)|| < 10^-5 bei " << std::endl;

            std::cout << "x = ( ";
            for (int i = 0; i  <= x.dimension; i++) {                     // x = (...) Ausgabe

                if (i == x.dimension) {
                    std::cout << ")";
                }

                else {
                    std::cout << x.get_component(i + 1) << "; ";
                }
            }
            
            std::cout << std::endl << "Lambda: " << lambda << std::endl << "f(x): " << fx << std::endl;

            std::cout << "grad f(x) = ( ";
            for (int i = 0; i <= grad.dimension; i++) {                      // grad f(x) = (...) Ausgabe

                if (i == x.dimension) {
                    std::cout << ")";
                }

                else {
                    std::cout << grad.get_component(i + 1) << "; ";
                }
            }
            

            std::cout << std::endl << "||grad f(x)|| = " << length_grad << std::endl;

            return grad;                    // ende da || grad f(x)|| <10^-5
        }
        

        else if (j == 25) {
            std::cout << "Ende wegen Schrittanzahl = 25 bei: " << std::endl;

            std::cout << "x = ( ";
            for (int i = 0; i - 1 < x.dimension; i++) {                 // x = (...) Ausgabe

                if (i == x.dimension) {
                    std::cout << ")";
                }

                else {
                    std::cout << x.get_component(i + 1) << "; ";
                }
            }
            
            std::cout << std::endl << "Lambda: " << lambda << std::endl << "f(x): " << fx << std::endl;

            std::cout << "grad f(x) = ( ";
            for (int i = 0; i - 1 < grad.dimension; i++) {                          // grad f(x) = (...) Ausgabe

                if (i == x.dimension) {
                    std::cout << ")";
                }

                else {
                    std::cout << grad.get_component(i + 1) << "; ";
                }
            }
            

            std::cout << std::endl << "||grad f(x)|| = " << length_grad << std::endl;

            return grad;       // ende da 25 Schritte erreicht
        }
        

        std::cout << "Schritt: " << j << std::endl;

        std::cout << "x = ( ";

        for (int i = 0; i - 1 < x.dimension; i++) {                     // x = (...) Ausgabe

            if (i == x.dimension) {
                std::cout << ")";
            }

            else {
                std::cout << x.get_component(i + 1) << "; ";
            }
        }
        

        std::cout << std::endl << "Lambda = " << lambda << std::endl; // Lambda = ... Ausgabe
        std::cout << "f(x) = " << fx << std::endl; // f(x) = ... Ausgabe

        std::cout << "grad f(x) = ( ";
        for (int i = 0; i - 1 < grad.dimension; i++) {                        // grad f(x) = (...) Ausgabe

            if (i == x.dimension) {
                std::cout << ")";
            }

            else {
                std::cout << grad.get_component(i + 1) << "; ";
            }
        }
        

        std::cout << std::endl << "||grad f(x)|| = " << length_grad << std::endl; // ||grad f(x)|| = ... Ausgabe

        

        for (int i = 0; i < x.dimension; i++) {                           //x_neu = x + (lambda * grad)  für alle components
            x_neu.set_component(i + 1, x.get_component(i + 1) -lambda * grad.get_component(i + 1));
        }

        

        std::cout << std::endl << "x_neu = ( ";
        for (int i = 0; i <= x_neu.dimension; i++) {                  // x_neu = (...) Ausgabe 

            if (i == x_neu.dimension) {
                std::cout << ")";
            }

            else {
                std::cout << x_neu.get_component(i + 1) << "; ";
            }


        }
        

        fx_neu = funktion(x_neu);                  // fx_neu berechnen

        std::cout << std::endl << "f(x_neu) = " << fx_neu << std::endl << std::endl; // fx_neu Ausgabe

        if (fx <fx_neu) {

            lambda = lambda /2;

            std::cout << "Test mit doppelter Schrittweite (lambda = " << lambda << ")";

            CMyVektor x_test;
            x_test.vektor_anlegen(x.dimension);

            for (int i = 0; i < x.dimension; i++) {                            //x_test = x + (lambda * gradient) für alle Komponente
                x_test.set_component(i + 1, x.get_component(i + 1) -lambda * grad.get_component(i + 1));
            }
            

            std::cout << std::endl << "x_test = ( ";
            for (int i = 0;i <= x_test.dimension; i++) {                  // x_test = (...) Ausgabe

                if (i == x_test.dimension) {
                    std::cout << ")";
                }

                else {
                    std::cout << x_test.get_component(i + 1) << "; ";
                }
            }
            

            fx_test = funktion(x_test);

            std::cout << std::endl << "f(x_test) = " << fx_test << std::endl;           // fx_test Ausgabe

            x = x_neu;                   // X ersetzen durch x_neu
            fx = fx_neu;                // fx ersetzen durch fx_neu

            if (fx_test  >fx_neu) {                                                 // Wenn fx_test kleiner ist als fx_neu, lambda alte Wert behalten
                std::cout << "Behalte alte Schrittweite!" << std::endl << std::endl;
                lambda = lambda * 2;
            }
              

            else {                                                                 // Wenn fx_test größer ist als fx_neu, lambda Wert verdoppeln
                std::cout << "Verdoppelte Schrittweite!" << std::endl << std::endl;
                x = x_test;            // X ersetzen durch x_test
                fx = fx_test;           // fx ersetzen durch fx_test
            }
            
        }
        

        else {                        // Wenn fx_neu größer ist als fx

            do {
                lambda = lambda / 2;

                std::cout << "Halbiere Schrittweite(lambda = " << lambda << ")";

                for (int i = 0; i < x.dimension; i++) {                       // x_neu = x + lambda * gradient, an jeder Stelle (Komponente)
                    x_neu.set_component(i + 1, x.get_component(i + 1) -lambda * grad.get_component(i + 1));
                }
                

                std::cout << std::endl << "x_neu = ( ";
                for (int i = 0; i <= x_neu.dimension; i++) {                // x_test = (...) Ausgabe

                    if (i == x_neu.dimension) {
                        std::cout << ")";
                    }

                    else {
                        std::cout << x_neu.get_component(i + 1) << "; ";
                    }
                }
                

                fx_neu = funktion(x_neu);

                std::cout << std::endl << "f(x_neu) = " << fx_neu << std::endl << std::endl;
            } while (fx_neu > fx);                           // So lange halbieren, bis fx_neu größer als fx ist
            

            x = x_neu;
            fx = fx_neu;
        }
       

    }
    return grad;
}


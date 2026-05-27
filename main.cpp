#include "CMyVektor.h" 
using namespace std;

double funktion1(CMyVektor x) {
	double x1 = x.get_component(1);
	double x2 = x.get_component(2);
	double x3 = x.get_component(3);

	return (4 * pow(x1, 2) + 5 * x2 * pow(x3, 2) );
}
double funktion_f(CMyVektor x) {
    	double x1 = x.get_component(1);
	double x2 = x.get_component(2);

	return (sin(x1 * x2) + sin(x1) + cos(x2));
}

double funktion_g(CMyVektor x) {
	double x1 = x.get_component(1);
	double x2 = x.get_component(2);
	double x3 = x.get_component(3);

	return (-1 * (2 * pow(x1, 2) - 2 * x1 * x2 + pow(x2, 2) + pow(x3, 2) - 2 * x1 - 4 * x3));

}CMyVektor funktion3(CMyVektor x) {
	double x1 = x.get_component(1);
	double x2 = x.get_component(2);

	CMyVektor tmp;
	tmp.vektor_anlegen(2);
	tmp.set_component(1, pow(x1, 3) * pow(x2, 3) - 2 * x2);
	tmp.set_component(2, x1 - 2);
	return tmp;

}

CMyVektor funktion2(CMyVektor x) {
	double x1 = x.get_component(1);
	double x2 = x.get_component(2);
	double x3 = x.get_component(3);
	double x4 = x.get_component(4);

	CMyVektor tmp;
	tmp.vektor_anlegen(3);
	tmp.set_component(1, x1 * x2 * exp(x3));
	tmp.set_component(2, x2 * x3 * x4);
	tmp.set_component(3, x4);
	return tmp;
}
CMyVektor funktfirstorder(CMyVektor y, double x)
{
	CMyVektor y_wert(2);
	y_wert.set_component(1, (2 * y.get_component(2) - (x * y.get_component(1))));	
	y_wert.set_component(2, (y.get_component(1) * y.get_component(2) - 2*pow(x,3)));
	
	return y_wert;
}

double funk_nte(CMyVektor y, double x)
{
	return((2 * x * y.get_component(2) * y.get_component(3)) + (2 * pow(y.get_component(1), 2) * y.get_component(2)));	
}
int main() {

	CMyVektor vektor1, vektor2, vektor3, vektor4;

	vektor1.vektor_anlegen(3);
	vektor1.set_component(1, 1);
	vektor1.set_component(2, 2);
	vektor1.set_component(3, 3);

	vektor2.vektor_anlegen(3);
	vektor2.set_component(1, 2);
	vektor2.set_component(2, 3);
	vektor2.set_component(3, 4);

	vektor3.vektor_anlegen(3);

	cout << "Vektor1: " << endl;
	for (int i = 0; i < vektor1.get_dimension(); i++) {
		cout << vektor1.get_component(i + 1) << endl;
	}

	cout << endl;

	cout << "Vektor2: " << endl;
	for (int i = 0; i < vektor2.get_dimension(); i++) {
		cout << vektor2.get_component(i + 1) << endl;
	}

	cout << endl;

	double length = vektor1.length();
	cout << length << endl;

	cout << endl;

	vektor3 = vektor1 + vektor2;

	cout << "Vektor3 = Vektor1 + Vektor2: " << endl;
	for (int i = 0; i < vektor3.get_dimension(); i++) {
		cout << vektor3.get_component(i + 1) << endl;
	}

	cout << endl;

	vektor4 = 2 * vektor1;

	cout << "Vektor4 = 2 * Vektor1: " << endl;
	for (int i = 0; i < vektor4.get_dimension(); i++) {
		cout << vektor4.get_component(i + 1) << endl;
	}

	cout << endl;

	CMyVektor vektor5;
	vektor5.vektor_anlegen(3);

	vektor5.set_component(1, 1);
	vektor5.set_component(2, 3);
	vektor5.set_component(3, 2);

	CMyVektor vektor6;
	vektor6 = vektor5.gradient(vektor5, funktion1);

	cout << "Vek6: " << endl;

	for (int i = 0; i < vektor6.get_dimension(); i++) {
		cout << vektor6.get_component(i + 1);
		cout << endl;
	} 

	CMyVektor grad1, vektor7;                       //fonction f
	vektor7.vektor_anlegen(2);
	vektor7.set_component(1, 0.2);
	vektor7.set_component(2, -2.1);

	grad1 = vektor7.grad_verfahren(vektor7, 1.0 ,funktion_f);

	/*CMyVektor grad2, vektor8;                           // fonction g
	vektor8.vektor_anlegen(3);

	grad2 = vektor8.grad_verfahren(vektor8, 0.1, funktion_g);*/
    
    system ("PAUSE");
    return 0;
}
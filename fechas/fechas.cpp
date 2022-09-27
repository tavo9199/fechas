#include <stdlib.h> 
#include <iostream>  
#include <string>  
#include <vector>  
#include <sstream>  

using namespace std;

class Datos {


private:
	int anio, mes, dia;
	string fecha;
public:
	void mostrar_en_pantalla();
	Datos& operator ++();
	void separar();
	Datos(string _fecha)//hacemos un constructor
	{ 
		fecha = _fecha;

	}
	void validar();
};

Datos& Datos::operator ++ () 
{ 
	this->dia++;
	validar();
	return *this;
}

void Datos::separar() {
	int contador=0;
	string T; 
	string datos[3];
	stringstream X(fecha);

	
	while (getline(X, T, '-')) {
		datos[contador] = T;
		contador++;
	}
	dia = stoi(datos[0]);
	mes = stoi(datos[1]);
	anio = stoi(datos[2]);
}
void Datos::mostrar_en_pantalla() {
	cout << dia << " " << mes << " " << anio << endl;

}
void Datos::validar()
{
	

	if (dia > 31 )
	{
		dia = 1;
		mes ++;
	}

	if (mes > 12)
	{
		mes = 1;
		anio++;
	}
	
	/*if (anio > 2100 || anio < 0)
	{
		cout << "O eres un viajero del tiempo o el anio es incorrecto" << endl;
	}
	else
	{
		cout << "El anio ingresado es:" <<anio<< endl;
	}
	if (anio % 4 != 0 || (anio % 100 == 0 && anio % 400 != 0))
	{
		cout << "El anio no es bisiesto" << endl;
	}
	else
	{
		cout << "El anio es bisiesto" << endl;
	}
	if (dia > 28 && mes==02 && anio % 4 != 0 || (anio % 100 == 0 && anio % 400 != 0))
	{
		cout << "el anio no es bisiesto por lo que febrero no puede tener mas de 28 dias" << endl;
	} */
}

int main() {

	string _fecha;
	cout << "-Que fecha tienes el dia de hoy?" << endl << "-Use el siguiente formato" << endl << "22-07-2022" << endl << "-DOS NUMEROS PARA EL DIA, DOS NUMEROS PARA EL MES Y 4 NUMEROS PARA EL ANIO" << endl << "-Recuerda que debe de tener un guion entre el dia mes y anio" << endl;
	cin >> _fecha;
	Datos p1 = Datos(_fecha);
	p1.separar();
	for (int i = 0; i < 3; i++) 
	{
		++p1;
		p1.mostrar_en_pantalla();

	}

	system("pause");
	return 0;
}
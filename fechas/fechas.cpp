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
	void separar();
	Datos(string _fecha)//hacemos un constructor
	{
		fecha = _fecha;

	}
	void mostrar_en_pantalla();
};
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
	mostrar_en_pantalla();
}
void Datos::mostrar_en_pantalla()
{
	

	if (dia > 31)
	{
		cout << "El dia es incorrecto" << endl;
	}
	else
	{
		cout << "El dia es: " << dia << endl;
	}

	if (mes > 12)
	{
		cout << "No exiten mas de 12 meses" << endl;
	}
	else
	{
		cout << "El mes es: " << mes << endl;
	}

	if (anio > 2100 || anio < 0)
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
	
}

int main() {

	string _fecha;
	cout << "-Que fecha tienes el dia de hoy?" << endl << "-Use el siguiente formato" << endl << "22-07-2022" << endl << "-DOS NUMEROS PARA EL DIA, DOS NUMEROS PARA EL MES Y 4 NUMEROS PARA EL ANIO" << endl << "-Recuerda que debe de tener un guion entre el dia mes y anio" << endl;
	cin >> _fecha;
	Datos p1 = Datos(_fecha);
	p1.separar();

	system("pause");
	return 0;
}
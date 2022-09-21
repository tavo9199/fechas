#include <string>
#include <iostream>


using namespace std;

class Date {

private:
	
	string fecha;
public:
	Date( string);

	void leer();
	void mostrar();

};

Date::Date(string _fecha) {

	fecha = _fecha;
}
void Date::leer() {
	cout << "que fecha tienes el dia de hoy?" << endl << "use el siguiente formato" << endl << "22/07/2022" << endl << " DOS NUMEROS PARA EL DIA, DOS NUMEROS PARA EL MES Y 4 NUMEROS PARA EL ANIO" << endl;
	cin.getline(fecha, 100);
	char* ptr;
	ptr = strtok(fecha, " / ");

	while (ptr != NULL)
	{
		cout << ptr << endl;
		ptr = strtok(NULL, " / ");
	}

}
int main()
{
	fecha p1 = fecha("22/07/2022");
	p1.leer();
	return 0;
}

#include <limits>
#include <fstream>
#include <inttypes.h>

#include "Empleado.h"

using namespace std;

void ReadAll() {
	char buffer[MAX_BUFFER];
	char s[2];
	uint16_t r_size;
	Empleado p;
	ifstream f;
	cout << "Nombres  Apellidos  Direccion Ciudad Estado ZipCode" << endl;

	f.open("empleado.txt");

	while (1)
	{
		f.read(s, 2);
		memcpy(&r_size, s, 2);
		f.read(buffer, r_size);
		if (f.eof()) break;

		p.setBBuffer(buffer);
		p.Print();
	}
	f.close();
}

int WriteAll() {
	char c[100];
	c[0] = 0;
	Empleado p;

	ofstream f;
	f.open("empleado.txt",ios::app);
	while (1)
	{
		p.Write();
		f.seekp(0, ios::end);
		f.write(p.in_buffer, p.SIZE);

		cout << "Desea Continuar? (S/N): " << flush; cin.getline(c, 100);
		if (strcmp(c, "N") == 0) break;
	}
	f.close();
	return 1;
}

void Empleado::GetEmpleadoByName(string nombre) {
	char buffer[MAX_BUFFER];
	bool cam = true;
	char s[2];
	uint16_t r_size;
	Empleado p;
	int cont = 0;
	ifstream f;

	f.open("empleado.txt");
	if (!f) {
		cout << "Error al abrir el archivo empleado.txt";
		return;
	}

	while (cam)
	{
		f.read(s, 2);
		memcpy(&r_size, s, 2);
		f.read(buffer, r_size);

		p.setBBuffer(buffer);

		if (nombre == p.nombre) {
			//cout << "aqui\n";

			p.Print();
			break;
		}
		else {
			f.tellg();
			cam = true;
		}

	}
	if (f.eof());

	f.close();
}

void Empleado::EliminarRegistro() {
	ifstream emple;
	emple.open("empleado.txt", ios::in);
	char aux[10];

	ofstream entrada;
	entrada.open("temp.txt", ios::out);
	char marca ='*';
	if (emple.fail()) {
		cout << "Error al abrir el archivo.";
		return;
	}
	else {
		cout << "Introduzca el nombre: ";
		cin >> aux;

		emple >> nombre;
		while (emple.eof()) {
			emple >> Apellido >> direccion >> ciudad >> estado >> zipCode;

			if (strcmp(aux, nombre) == 0) {
				entrada <<marca;
			}
			else {
				entrada <<nombre<< Apellido << direccion << ciudad << estado << zipCode;
			}
			emple >> nombre;
		}
		emple.close();
		entrada.close();

	}
}

int main(int argc, char **argv) {
	Empleado p;

	if (strcmp(argv[1], "1") == 0) ReadAll();
	if (strcmp(argv[1], "2") == 0) WriteAll();
	if (strcmp(argv[1], "3") == 0) p.GetEmpleadoByName("Mario");
	if (strcmp(argv[1], "4") == 0) p.EliminarRegistro();
}

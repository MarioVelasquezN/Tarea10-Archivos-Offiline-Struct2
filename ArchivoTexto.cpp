#include <limits>
#include <fstream>
#include <inttypes.h>

#include "Empleado.h"

using namespace std;
#pragma warning (disable : 4996)
//_CRT_SECURE_NO_WARNINGS

void ReadAll() {
	char buffer[MAX_BUFFER];
	//char s[2];
	//uint16_t r_size;
	Empleado p;
	ifstream f;
	cout << "Nombres  Apellidos  Direccion Ciudad Estado ZipCode" << endl;

	f.open("empleado.txt",ios::in);
	if (f.fail()) {
		cout << "No encontro el alchivo empleado.txt" << endl;
		return;
	}

	while (1)
	{
		//f.read(s, 2);
		//memcpy(&r_size, s, 2);
		f.read(buffer,MAX_BUFFER);
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
		f.write(p.in_buffer,MAX_BUFFER);

		cout << "Desea Continuar? (S/N): " << flush; cin.getline(c, 100);
		if (strcmp(c, "N") == 0) break;
	}
	f.close();
	return 1;
}

void Empleado::GetEmpleadoByName(string nombre) {
	char buffer[MAX_BUFFER];
	bool cam = true;
	//char s[2];
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
		//f.read(s, 2);
		//memcpy(&r_size, s, 2);
		f.read(buffer, MAX_BUFFER);

		p.setBBuffer(buffer);
		cont=f.tellg();
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

int Empleado::buscarEmpleado(const char* name) {
	char buffer[MAX_BUFFER];
	bool cam = true;
	Empleado p;
	int cont = 0;
	ifstream f;

	f.open("empleado.txt");
	if (!f) {
		cout << "Error al abrir el archivo empleado.txt";
		return 0;
	}

	while (!f.eof())
	{
		cont = f.tellg();
		f.read(buffer, MAX_BUFFER);
		p.setBBuffer(buffer);
		
		if (strcmp(name,p.nombre)==0) {
			return cont;
		}
	}
	return 0;

	f.close();
}

void Empleado::EliminarRegistro() {
	//char buffer[MAX_BUFFER];
	fstream ar;
	//Empleado p;
	ar.open("empleado.txt");
	char aux[30];
	if (!ar) {
		cout << "Archivo no encontrado!!";
		return;
	}

	cout << "Introduzca un nombre para eliminar: ";
	cin >> aux;

	if (buscarEmpleado(aux) == -1) {
		cout << "No se encontro nombre";
		return;
	}
	else {
		ar.seekp(buscarEmpleado(aux));
		ar.put('*');
		ar.close();
	}
	
}

void Empleado::Compactar() {
	char buffer[MAX_BUFFER];
	bool cas = true;
	ifstream f;
	ofstream o;
	Empleado p;
	char *c = in_buffer;
	f.open("empleado.txt", ios::in);
	o.open("empleadonew.txt", ios::app);
	if (!f) {
		cout << "Archivo no pudo leerse!!";
		return;
	}

	f.seekg(0, ios::end);
	int sz = f.tellg();
	f.seekg(0, ios::beg);
	while (!f.eof())
	{

		f.read(buffer, MAX_BUFFER);
		if (f.eof()) break;;

		if (buffer[0] != '*')
			o.write(buffer, MAX_BUFFER);


	}
}

int main(/*int argc, char **argv*/) {
	Empleado p;

	/*if (strcmp(argv[1], "1") == 0)*/ //WriteAll(); 
	/*if (strcmp(argv[1], "2") == 0)*/ //ReadAll();
	cout << endl;
	/*if (strcmp(argv[1], "3") == 0)*/ //p.GetEmpleadoByName("daniel");
	cout << endl;
	/*if (strcmp(argv[1], "4") == 0)*/ //p.EliminarRegistro();
	p.Compactar();
}

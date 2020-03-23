#include "Empleado.h"

using namespace std;

void Empleado::Print() {
	cout << nombre << " "
		<< Apellido << " "
		<< direccion << " "
		<< ciudad << " "
		<< estado << " "
		<< zipCode << "\n"
		<<flush;
}

Empleado::Empleado() {
	nombre[0] = 0;
	Apellido[0] = 0;
	direccion[0] = 0;
	ciudad[0] = 0;
	estado[0] = 0;
	zipCode[0] = 0;
	in_buffer[0] = 0;
	SIZE = 0;
}

void Empleado::setBBuffer(const char* buff) {
	memcpy(in_buffer, buff, MAX_BUFFER);
	unPack();
}

void Empleado::unPack() {
	int size = 0;
	char cSize[3];
	cSize[2] = '\0';

	char *c = in_buffer;

	memcpy(cSize, c, 2);
	size = atoi(cSize);
	memcpy(nombre, c += 2, size);
	nombre[size] = 0;

	memcpy(cSize, c += size, 2);
	size = atoi(cSize);
	memcpy(Apellido, c += 2, size);
	Apellido[size] = 0;

	memcpy(cSize, c += size, 2);
	size = atoi(cSize);
	memcpy(direccion, c += 2, size);
	direccion[size] = 0;

	memcpy(cSize, c += size, 2);
	size = atoi(cSize);
	memcpy(ciudad, c += 2, size);
	ciudad[size] = 0;

	memcpy(cSize, c += size, 2);
	size = atoi(cSize);
	memcpy(estado, c += 2, size);
	estado[size] = 0;

	memcpy(cSize, c += size, 2);
	size = atoi(cSize);
	memcpy(zipCode, c += 2, size);
	zipCode[size] = 0;
}

void Empleado::Pack() {
	char str_size[3];

	int l_size = 0;
	str_size[2] = '\0';

	l_size = strlen(nombre);
	strcpy(in_buffer, str_size);
	strcat(in_buffer, nombre);
	strcat(in_buffer, "|");

	l_size = strlen(Apellido);
	strcat(in_buffer, str_size);
	strcat(in_buffer, Apellido);
	strcat(in_buffer, "|");

	l_size = strlen(direccion);
	strcat(in_buffer, str_size);
	strcat(in_buffer, direccion);
	strcat(in_buffer, "|");

	l_size = strlen(ciudad);
	strcat(in_buffer, str_size);
	strcat(in_buffer, ciudad);
	strcat(in_buffer, "|");

	l_size = strlen(estado);
	strcat(in_buffer, str_size);
	strcat(in_buffer, estado);
	strcat(in_buffer, "|");

	l_size = strlen(zipCode);
	strcat(in_buffer, str_size);
	strcat(in_buffer, zipCode);
	strcat(in_buffer, "|");

	SIZE = strlen(in_buffer);
}


void Empleado::Write() {
	cout << "Nombres: " << flush; cin.getline(nombre, sizeof(nombre));
	cout << "Apellidos: " << flush; cin.getline(Apellido, sizeof(Apellido));
	cout << "Direccion: " << flush; cin.getline(direccion, sizeof(direccion));
	cout << "Ciudad: " << flush; cin.getline(ciudad,sizeof(ciudad));
	cout << "Estado: " << flush; cin.getline(estado, sizeof(estado));
	cout << "Zip Code: " << flush; cin.getline(zipCode, sizeof(zipCode));
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	Pack();
}


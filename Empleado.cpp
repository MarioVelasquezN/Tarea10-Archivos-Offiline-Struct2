#include "Empleado.h"
#include <sstream>
#pragma warning (disable : 4996)
using namespace std;


Empleado::Empleado() {
	nombre[0] = 0;
	Apellido[0] = 0;
	direccion[0] = 0;
	ciudad[0] = 0;
	estado[0] = 0;
	zipCode[0] = 0;
	in_buffer[0] = 0;
	//SIZE = 0;
}

void Empleado::Print() {
	cout << nombre << " "
		<< Apellido << " "
		<< direccion << " "
		<< ciudad << " "
		<< estado << " "
		<< zipCode << "\n"
		<<flush;
}


void Empleado::setBBuffer(const char* buff) {
	memcpy(in_buffer, buff, MAX_BUFFER);
	unPack();
}

void Empleado::unPack() {
	//int size = 0;
	char se = '|';
	char temp[30];
	char *c = in_buffer;
	size_t j=0;
	int pos = 0;

	for (size_t i = 0; c[i]!=se ; i++)
	{
		temp[j] = c[i];
		
		j++;
		pos++;
	}
	temp[j] = '\0';
	
	strcpy(nombre, temp);

	j = 0;
	pos=pos + 1;
	for (size_t i =pos ; c[i]!=se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(Apellido, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos;c[i]!=se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(direccion, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(ciudad, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(estado, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(zipCode, temp);


	/*strcpy(buffer, nombre);
	strcpy(buffer, &se);

	strcpy(buffer, Apellido);
	strcpy(buffer, &se);

	strcpy(buffer, direccion);
	strcpy(buffer, &se);

	strcpy(buffer, ciudad);
	strcpy(buffer, &se);

	strcpy(buffer, estado);
	strcpy(buffer, &se);

	strcpy(buffer, zipCode);
	strcpy(buffer, &se);*/

	////memcpy(&se, c += 1, 1);
	//memcpy(nombre, c, 1);
	//nombre[size] = 0;
	//memcpy(&se, c += 1, 1);

	//memcpy(Apellido, c+=1, 1);
	//Apellido[size] = 0;
	//memcpy(&se, c += 1, 1);

	//memcpy(direccion, c += 1, 1);
	//direccion[size] = 0;
	//memcpy(&se, c += 1, 1);

	//memcpy(ciudad, c += 1, 1);
	//ciudad[size] = 0;
	//memcpy(&se, c += 1, 1);

	//memcpy(estado, c += 1, 1);
	//estado[size] = 0;
	//memcpy(&se, c += 1, 1);

	//memcpy(zipCode, c += 1, 1);
	//zipCode[size] = 0;
	//memcpy(&se, c += 1, 1);
}

void Empleado::Pack() {
	//char str_size[3];

	//int l_size = 0;
	//str_size[2] = '\0';

	//l_size = strlen(nombre);
	
	strcat(in_buffer, nombre);
	strcat(in_buffer, "|");

	//l_size = strlen(Apellido);
	
	strcat(in_buffer, Apellido);
	strcat(in_buffer, "|");

	//l_size = strlen(direccion);
	
	strcat(in_buffer, direccion);
	strcat(in_buffer, "|");

	//l_size = strlen(ciudad);
	
	strcat(in_buffer, ciudad);
	strcat(in_buffer, "|");

	//l_size = strlen(estado);
	
	strcat(in_buffer, estado);
	strcat(in_buffer, "|");

	//l_size = strlen(zipCode);
	
	strcat(in_buffer, zipCode);
	strcat(in_buffer, "|");

	SIZE = strlen(in_buffer);

	for (size_t i = SIZE; i < 64; i++)
	{
		in_buffer[i] =' ';
	}
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


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <limits>

#pragma pack(1)
//15*3+20+4
#define MAX_BUFFER 64

using namespace std;

class Empleado {
private:
	void Pack();
	void unPack();
	//int copy2Buffer(char*);
	//int copyFromBuffer(char *, char*);

public:
	int SIZE;
	char in_buffer[MAX_BUFFER];
	char nombre[10];
	char Apellido[10];
	char direccion[15];
	char ciudad[15];
	char estado[10];
	char zipCode[4];

	Empleado();
	//~Empleado();

	void Print();
	void setBBuffer(const char*);
	void Write();
	void GetEmpleadoByName(string);
	void EliminarRegistro();
	void Compactar();
	
};
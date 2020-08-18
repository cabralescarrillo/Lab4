// Programa que lee un archivo CSV para texto y utilzar sus datos en operaciones
// Creado por Luis Cabrles
// Inspirado en: https://www.codespeedy.com/read-data-from-csv-file-in-cpp/
//Inspirado por: Cesar Aceros

#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
float suma=0;
float promedio;
void parseCSV()
{
	ifstream data("PromedioCSV.csv");
	string line;
	vector<vector<string>> parsedCSV;
	int contadordefila=0;          //En esta linea y la siguiete se definen contadores para las filas y columnas
	int contadordecolumna=0;       // esto permite desplazarse por la matriz que se forma con las filas y columans de los datos 

	while(getline(data,line))        
	{
		stringstream linestream(line); //en esta de linea de comado se lee la linea correspondiente en el CSV
		string celda;
		vector<string> parsedfila;
		contadordecolumna=0;    //este while es mas grande que el siguiente aqui se reinicia el contador de columna 

		while(getline(linestream,celda,','))
		{
			parsedfila.push_back(celda);   // con este comando push_back se lee y define la celda de texto que se encuentra ubicada con el contador de dolumans 
			contadordecolumna++;   //en este while el contador de columanas va iterando hasta que no hay mas datos
	
		}
        
		contadordefila++;  //cuando el contador de columnas termina su trabajo sale de lwhile anterior y lo que hace este es que suma uno mas a la fila, pasando a la siguiete linea de datos del CSV
		parsedCSV.push_back(parsedfila);
	}
	for(int i=0; i<contadordefila;i++){             //luego de que los push back definan los datos, este for se encarga de escribirlos en el termnal uno por uno siguiendo la "cordenas" que se definieron anteriormente 
		for (int j=0; j< contadordecolumna ; j++){
			cout << parsedCSV[i][j] <<"-";
		}
		cout <<'\n';
	}
	cout <<'\n';
	
	for(int i=0; i<contadordefila;i++){       //con este for se mueve por la cade de datos 
		stringstream nota(parsedCSV[i][2]); // con esta función podemos almacenar los datos en el string nota
		int x = 0;   
         nota >> x;  //como nota es un string no puede ser poerado directamento con las variable de tipo float, aqui introducimos la información en x que ya habiamos definido 
         suma=x+suma;  // se realiza una suma interativa dentro de for cada vez que cambia de fila
	}
	int n=0;
	n=parsedCSV.size(); //para tener el dato del numero de estudiantes mas facil y accesible, generamos otra variable para almacenar este dato de parsedCSV.size
	promedio=suma/n; //aplicamos la operación del promedio artmetico 
	cout<< "El promedio de las notas es: " << promedio; //imprimimos el valor del promedio 
	
	
}
int main()
{
	parseCSV();
	
	return 0;
	
}
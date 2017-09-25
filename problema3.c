#include <stdio.h>

// Estructura para almacenar los datos de un empleado
typedef struct {
  int ocupacion, sexo;
  float salario;
  char nombre[10];
} datos;  // Definimos el tipo "datos"

// Función principal que llama a las demás funciones
int main() {
  void leerArchivo();   // Declaración de la función leerArchivo
  leerArchivo();   // Llamado de la función leerArchivo
  return 0;
}

// Función encargada de leer datos del archivo y pasarlos a la función ordenarEmpleados
void leerArchivo() {
  datos empleado; // Variable de tipo datos para un empleado
  datos empleados500[10]; // ARRAY de empleados mayor que 500
  FILE * archivo; // Buffer de tipo FILE
  void ordenarEmpleados(int size, datos empleados[10]);  // Ordena a empleados500
  void mostrarEmpleados(int size, datos empleados[10]);  // Muestra en pantalla a empleados500
  int mayor500(float salario), i;  // Deternima si un salario es mayor a 500.00
  // Abre el archivo como solo lectura
  archivo = fopen("empleados_actualizados.txt", "r");
  i = 0; // Contador de la cantidad de empleados500
  // Lee datos del archivo y determina cuales son los
  // empleados con salario mayor a 500 y los asigna
  // a una posición en empleados500
  while (!feof(archivo)) {
    fscanf(archivo, "%d %d %f %s\n", &empleado.ocupacion,\
                                     &empleado.sexo,\
                                     &empleado.salario,\
                                     empleado.nombre);
    if (mayor500(empleado.salario)) {
      empleados500[i] = empleado;
      i++;
    }
  }
  // Llama a la funcion ordenarEmpleados
  ordenarEmpleados(i, empleados500);
  // Llama a la funcion mostrarEmpleados
  mostrarEmpleados(i, empleados500);
  // Cierra el buffer del archivi
  fclose(archivo);
}

// Función para ordenar el ARRAY de empleados con
// salario mayor a 500
void ordenarEmpleados(int size, datos empleados[10]) {
  int i;
  datos auxiliar;
  // Se utilizó un método de ordenación simple
  // utilizando una varieble auxiliar
  for(i=0; i<size-1; i++) {
    if (empleados[i].salario > empleados[i+1].salario) {
      auxiliar = empleados[i+1];
      empleados[i+1] = empleados[i];
      empleados[i] = auxiliar;
    }
  }
}

// Función para mostrar los empleados
void mostrarEmpleados(int size, datos empleados[10]) {
  int i;
  printf("Ocupación\tSexo\tSalario\tNombre\n");
  for(i=0; i<size; i++) {
    // Se utilizan numeros para alinear la salida en patalla
    printf("%9d %10d %10.2f %s\n", empleados[i].ocupacion,\
                                    empleados[i].sexo,\
                                    empleados[i].salario,\
                                    empleados[i].nombre);
  }
}

// Función para determinar si un salario es mayor a B/. 500.00
int mayor500(float salario) {
  if (salario > 500.00) {
    return 1;
  } else {
    return 0;
  }
}
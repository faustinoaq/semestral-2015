#include <stdio.h>  // Libería estandar de entrada y salida

// Estructura para almacenar los datos de un empleado
typedef struct {
  int ocupacion, sexo;
  float salario;
  char nombre[10];
} datos;  // Definimos el tipo "datos"

// Función principal que llama a las demás funciones
int main() {
  void leerArchivo();  // Declaración de la función leerArchivo
  leerArchivo();  // Llamado de la función leerArchivo
  return 0;
  // Retornamos 0 si no hubo ningún error
  // Ver: http://stackoverflow.com/questions/21494929/why-return-0-from-main-in-a-c-program
}

// Función encargada de leer datos del archivo y pasarlos a la función actualizarDatos
void leerArchivo() {
  datos empleado;  // Variable de tipo datos para un empleado
  FILE * archivo;  // Buffer de tipo FILE
  void actualizarDatos(datos empleado);   // Declaración de la función actualizarDatos
  archivo = fopen("empleados.txt", "r");  // Leemos los empleados
  if (archivo != NULL) {
    // Verificamos que el archivo se haya abierto correctamente y
    // lo leemos hasta el final.
    while (!feof(archivo)) {
      fscanf(archivo, "%d %d %f %s\n", &empleado.ocupacion,\
                                       &empleado.sexo,\
                                       &empleado.salario,\
                                       empleado.nombre);
      // Los datos del empleado se pasan a la función actualizarDatos
      actualizarDatos(empleado);
    }
    // Se cierra Buffer después que se termina de leer el archivo
    fclose(archivo);
  } else {
    printf("Error al leer el archivo\n");
  }
}

// Función para calcular el nuevo salario de un empleado
// Recibe como parametro los datos del empleado
float nuevoSalario(datos empleado) {
  
  if (empleado.sexo == 1 &&\
      empleado.ocupacion == 1 &&\
      empleado.salario < 300.00) {
  // Comprueba que el empleado sea un aseador masculido con salario menor a 300.00

    empleado.salario += empleado.salario * 0.1;  // 10% de aumento al salario actual
    return empleado.salario;

  } else if (empleado.sexo == 0 &&\
             empleado.ocupacion == 2 &&\
             empleado.salario > 300.00 &&\
             empleado.salario < 500.00) {
  // Se comprueba que el empleado sea una secretaria con salario entre 300.00 y 500.00

    empleado.salario += 62.30;  // Se le aumentan B/. 62.30
    return empleado.salario;
    
  } else if (empleado.ocupacion == 3) {
  // Se comprueba que la ocupación sea jefe de taller
    
    if (empleado.sexo == 0) {
    // Se comprueba que el empleado sea una mujer
      empleado.salario += 45.30;  // Se le aumenta 45.30 al salario
    } else {
    // Se comprueba que el empleado sea un hombre
      empleado.salario += 33.00;  // Se le aumenta 33.00 al salario
    }
    return empleado.salario;
    
  } else {
    return 0;
  }  
}

// Función para actualizar datos en un nuevo archivo
// Recibe como parametro los datos del empleado
void actualizarDatos(datos empleado) {
  float actualizado;  // Salario actualizado
  float nuevoSalario(datos empleado);  // Función para calcular el nuevo salario
  FILE * nuevoArchivo;  // Buffer del nuevo archivo
  // Abre el archivo como escritura sin sobreescribir
  nuevoArchivo = fopen("empleados_actualizados.txt", "a+");
  if (nuevoArchivo != NULL) {
    // Verifica que el archivo se haya abierto correctamente
    actualizado = nuevoSalario(empleado);
    // Verifica que el salario se haya actualizado
    if (actualizado) {
      empleado.salario = actualizado;
    }
    // Guarda los nuevos datos en un nuevo archivo
    fprintf(nuevoArchivo, "%d %d %.2f %s\n", empleado.ocupacion,\
                                             empleado.sexo,\
                                             empleado.salario,\
                                             empleado.nombre);
    // Cierra el buffer una vez guardado los datos
    fclose(nuevoArchivo);
  } else {
    printf("Error al leer el archivo\n");
  }
}



#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

  //Obtenemos identificador IPC, que creara la zona de memoria compartida
  //Convertimos un path del sistema en un identificador IPC
  //usamos la llamada ftok
  //el primer parametro es la ruta, el segundo es un numero aleatorio que conozcan
  //los procesos que quieran compartir el mismo segmento de memoria compartida
  int ipcID = ftok("/tmp", 123);

  //Creamos el segmento de memoria compartida con la llamada shmget
  //El primer parametro es la clave obtenida con el ftok
  //El segundo parametro es el tamaño de memoria compartida
  //El tercer parametro son lso flags del modo de uso (IPC_CREAT crea un nuevo segmento)
  int sharedMemoryID = shmget(ipcID, sizeof(int) * 10, 0777 | IPC_CREAT);

  //Unimos los datos al segmento de memoria compartida con la llamada shmat
  int *buffer;
  buffer = shmat(sharedMemoryID, 0, 0);
}

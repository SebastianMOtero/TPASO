 Obtener un array de semáforos. La función int semget (key_t, int, int) nos permite obtener un array de semáforos.
 Se le pasa como primer parámetro la clave obtenida en el paso anterior, el segundo parámetro es el número de semáforos que queremos y el tercer parámetro son flags. 


 int main() {
   int semaforo = semget(me falta,1,IPC_CREAT|0700)

   Uno de los procesos debe inicializar el semáforo. La función a utilizar es int semctl (int, int, int, int).
   El primer parámetro es el identificador del array de semáforos obtenido anteriormente,
   el segundo parámetro es el índice del semáforo que queremos inicializar dentro del array de semáforos obtenido.
   Si sólo hemos pedido uno, el segundo parámetro será 0.
   El tercer parámetro indica qué queremos hacer con el semáforo. En función de su valor, los siguientes parámetros serán una cosa u otra.
   En nuestro ejemplo, que queremos inicializar el semáforo, el valor del tercer parámetro es SETVAL.
El cuarto parámetro, aunque está definido como un entero, en realidad admite una unión bastante liada.
Si no queremos complicarnos la vida, bastará pasar como cuarto parámetro un 1 si queremos el semáforo en "verde" o un 0 si lo queremos en "rojo".
En el código de ejemplo sem1.c y sem2.c se utiliza la unión, pero el resultado es el mismo.

   semctl(semaforo,0,SETVAL,1)

 }

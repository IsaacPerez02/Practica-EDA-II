



# **ESTRUCTURAS DE DATOS Y ALGORITMOS II, 2022-2023**


## *Información sobre TÍTULO DE PROYECTO*









Max Mirosa Beuter, Isaac Pérez Anguiano, Adrian Montes Muñoz

u215076, u214402, u213939

8/06/2023









## *PLANTILLA DE MEMORIA DE PROYECTO [Máximo 5000 palabras en total]*
## *LISTA DE CONTENIDOS* [Incluir todas las secciones que se detallan a continuación]
### *INTRODUCCIÓN [Aprox.  250 palabras]*
En este proyecto se nos ha propuesto el desafío de crear en lenguaje de código C una red social, con una lista de objetivos mínimos que cumplir, los cuales tienen relación con aquello presentado en clase de teoría, como por ejemplo la implementación de pilas, colas, listas, etc. Nuestro grupo hizo un brain storm para tener una gran cantidad de ideas que poder implementar para diseñar la red social que se nos propone. Después de comentarlo decidimos hacer una red social que fuese una mezcla entre lo mejor que tienen algunas de las aplicaciones que se usan en la actualidad. Nuestra red social estaría enfocada a la comunicación entre personas que trabajan en un mismo proyecto o para conocer a gente para realizar un proyecto, siendo una especie de herramienta de comunicación al estilo de discord, pero con implementaciones de otras redes sociales como por ejemplo twitter, ya que se le da la posibilidad de crear publicaciones a los diferentes usuarios y compartirlas con su círculo social, ya sea de amigos o trabajo. Durante el proyecto hemos estado trabajando con ayuda de las diapositivas de teoría que se pueden encontrar en el aula global para la implementación de algunos objetivos planteados en el proyecto y también ayuda de páginas tales como StackOverflow, GitHub o Chat GPT donde hemos podido encontrar una estructura principal de código como base para modelar a nuestro gusto y así poder adaptarlo de forma correcta a nuestro trabajo.
###  *OBJETIVOS DEL PROYECTO [Aprox. 2500 palabras]*
### *Objetivos obligatorios alcanzados* 

#### **Primer objetivo:**

El primer objetivo fue implementar una lista, esto lo hicimos con nuestro archivo C y header llamado user_list, donde tenemos un double linked list creada mediante la estructura creada en el header en la línea 13. En esta estructura, prev és un nodo anterior de la lista de usuarios y next, es un nodo siguiente de la lista de usuarios. En nuestro archivo C incluimos el header user.h, para así tener acceso a todos los datos de los diferentes usuarios. Al ser una doble linked list, avanzamos o retrocedemos mediante el uso de los nodos (prev y next). Primeramente inicializamos a todos los usuarios que se encuentran en el archivo de texto users.txt y a cada uno de ellos le asignamos un espacio en la lista para guardar su información de usuario. Para ello nuestro archivo tipo C dispone de unas funciones como **crear usuario**(first_user_created o add_user_created), **cargar estos usuarios**(loading_users), save_all_users sirve para que cuando cerremos el programa, este guarde todos los usuarios que ya estaban introducidos anteriormente y los nuevos que han sido agregados durante la ejecución del programa. Creemos que en esta lista podríamos aprovechar más algunos datos de la estructura de usuarios, pero aun así creemos para el objetivo que tenemos propuesto, aun asi intuimos que esta implementado de forma correcta.

#### **Segundo objetivo:**

Como segundo objetivo, creamos una pila en el bloque de código y header llamado request_queue, en este bloque han sido implementados 2 objetivos, los cuales han sido el segundo (la pila) y el tercero (la cola), a diferencia de la cola, este stack funciona de forma que el programa escogerá entre la lista de usuarios tres al azar y los meterá dentro del stack y el usuario escogerá si quiere enviar o no las solicitudes.

#### **Tercer objetivo:**

El tercer objetivo fue crear una cola para, este objetivo ha sido implementado en el archivo tipo C y header de request_queue, la estructura de la cola ha sido implementada en una struct al principio del header, donde encontramos la siguientes variables en la estructura para que la cola tenga un funcionamiento correcto. En primer lugar encontramos el **code_user** que nos sirve para identificar a qué usuario nos dirigimos, **code_request** sirve para saber los códigos de los usuarios que le han enviado solicitud al usuario en cuestión y por último tenemos los parámetros para la funcionalidad de la cola, el head, el tail y el size. Al principio de todo, inicializamos todas las peticiones de los diferentes usuarios y en función de si la cola está vacía o tiene solicitudes, en el main pediremos que acepte o deniegue. En el apartado de manejar la red social como administrador, tendremos la opción de ver las diferentes solicitudes de cada usuario usando su código de usuario y usando la visión como usuario, estos tendrán la oportunidad de ver únicamente sus solicitudes y aceptarlas o denegarlas a su criterio. Durante el proceso de creación y estructuración de la cola hemos tenido problemas a la hora de recorrer usuarios, al principio nunca cogia el ultimo usuario y el problema residia en que comprobamos el nodo siguiente si era NULL, cuando teníamos que comprobar si únicamente el nodo actual era NULL, no el siguiente. Creemos que la cola está suficientemente bien implementada aun así creemos que la podríamos aprovechar más mostrando más información acerca del usuario que envía la petición.

#### **segundo objetivo**

Hemos implementado un algoritmo de búsqueda tipo Linear Search, en el bloque de código C user_list, donde buscamos de forma secuencial a diversos usuarios(muchos LinearSearch ). Más en concreto a partir de la línea 196 donde empiezan a salir estos algoritmos de búsqueda.

#### **tercer objetivo**

El algoritmo de ordenamiento ha sido implementado en el diccionario para así poder ordenar que palabras han sido más utilizadas en las diferentes publicaciones de los usuarios, la función recoge un arreglo que es la publicación y con un strcmp va comparando en un bucle las diferentes palabras de la publicación con las palabras que hay en el diccionario, cuando la palabra existe le suma un valor y en caso de que no exista la agrega al diccionario. Dentro del bucle interno, se compara el número de palabras (num_words) del elemento actual (dict->words[j]) con el número de palabras del elemento mínimo encontrado hasta el momento (dict->words[min]). Si el número de palabras del elemento actual es menor, se actualiza la variable min con el índice del elemento actual. Esto se hace para encontrar el elemento con el menor número de palabras restantes en el diccionario. Después de completar el bucle interno, se ha encontrado el elemento con el menor número de palabras restantes en el diccionario. Ahora se procede a intercambiar los valores del elemento actual (dict->words[i]) con el elemento mínimo encontrado (dict->words[min]) utilizando variables auxiliares. Primero se almacena el número de palabras del elemento actual en count_word_aux y se copia la palabra del elemento actual en aux_word utilizando strcpy. Luego se copian el número de palabras y la palabra del elemento mínimo en el elemento actual. Finalmente, se copian el número de palabras y la palabra almacenados en count_word_aux y aux_word respectivamente en el elemento mínimo.

#### **cuarto objetivo**

El diccionario está implementado en tanto el header y archivo C llamados dictionary_topic. Primero de todo, hemos implementado 2 estructuras, la primera contiene el tamaño del diccionario, las palabras que hay y la lista de palabras. En la segunda estructura encontramos la palabra junto al número de veces que ha aparecido en la Timeline. Gracias a las diferentes funciones que tenemos en el archivo C, estas nos permitirán leer las diferentes publicaciones que se han hecho en la Timeline para así poder escanearlas y añadirlas al diccionario, en caso de que estas ya existan se les sumará 1 al valor que ya tenían, todas las palabras se declaran con un valor 1. Además para evitar problemas a la hora de saber qué palabras se usan más, observamos que como es razonable aquello que más se usa son artículos o preposiciones, por lo que en la función de añadir al diccionario, solo se añadirán aquellas palabras que tengan una longitud mayor a 3, de esta forma no tendremos en el top 10, únicamente preposiciones, artículos, etc.


### *Objetivos deseables alcanzados*

#### **Primer objetivo (implementar función de lectura y guardado de datos):**

Hemos implementado este objetivo en el apartado de listado de usuarios (user_list), en este archivo de tipo C, recogemos los datos en el archivo C users.c para que ellos introduzcan los datos de nombre, id, edad, ubicación, etc. e introducimos estos datos en un archivo de texto llamado users.txt, donde cada línea de texto es la información de un usuario separada por un espacio en el siguiente orden: Nombre de usuario, Nombre, código de usuario, contraseña, edad, email, ubicación y gustos. Estos datos los almacenamos en este archivo de texto y cada vez que abrimos el programa, se inicializan todos los datos en la estructura y una vez cerrado el programa, se guardan esos datos en el archivo de texto. Estos procesos se ejecutan en el apartado de user_list.c y otros bloques de código pero estos no almacenan datos de usuario sino que almacenan por ejemplo información acerca de las solicitudes, aunque también es una implementación de lectura y guardado de datos.

#### **Segundo objetivo (capa estetica):**

Hemos corregido capas estéticas para que no sea solo texto en consola, hemos hecho esta mejora a nivel estético añadiendo diferentes tipos de caracteres especiales como asteriscos para mejorar la claridad de algunos apartados, hemos tenido que quitar los acentos y las ñ del documento ya que Clion no tiene la capacidad de imprimir estos caracteres de forma correcta y hace que a nivel estético empeore.

#### **Tercer objetivo (printar grapho):**

Este objetivo está cumplido en el archivo C friends_graph.

#### **Cuarto objetivo (calcular el tiempo de ejecución):**

Hemos incluido la librería time.h en el main y en la línea 32, hemos declarado el tiempo y lo hemos puesto a 0. En la línea 46 iniciamos el reloj y cargamos todos los archivos en el programa y en la 63 paramos el reloj para ver cuánto tiempo ha tardado en ejecutarse desde la línea 46 a la 63. En la línea 64 le damos a la variable clock time el valor del tiempo que ha tardado para pintarla en la siguiente línea. También tenemos un cálculo de tiempo en la línea 98 a la 226 y entre medio de la 212 a la 214 para calcular el tiempo que tarda en mostrar la TimeLine del usuario, esta de la línea 212 a la 214, tiene varias listas en la función y puntero y por esa razón a pesar de ser una única línea de código, tarda más de lo esperado en ejecutarse.
### *Objetivos exploratorios adquiridos*

Esta subsección debe describir qué objetivos exploratorios se han implementado en el proyecto siguiendo la estructura y los elementos presentados anteriormente.

#### **primer objetivo(diferenciarse de únicamente consola):**

Para no hacer monótono el código impreso por consola y que sea diferente, hemos añadido al código algunos prints que hacen ver el código por apartados imprimiendo por ejemplo asteriscos, de esta forma da una visión a la impresión por consola de que esta todo mas limpio y no da esa sensación de monotonía. 

#### **segundo objetivo(funciones de lectura):**

Como ya está explicado en el primer objetivo deseable, en user_lists hay funciones que nos permiten almacenar la información de los usuarios para tenerlos como una base de datos y así poder cargar la información en las estructuras al iniciar el programa. 
### *SOLUCIÓN [Aprox. 1500 palabras]*
### *Arquitectura del sistema [Aprox. 750 palabras]*

El sistema está estructurado en diferentes bloques que sirven para las diversas funcionalidades de la red social, dentro de nuestro programa encontramos los siguientes headers y archivos de tipo C: 

#### **Main.c**
El main es el núcleo donde convergen el resto de bloques de código del programa, consta de un menú hecho a base de prints en el cual escogeremos las opciones a las cuales queremos acceder y mediante las opciones que escogemos, se utilizarán unas u otras funciones de los otros bloques.

#### **Defines.h**
Aquí encontramos todos los defines que se utilizan en el resto de bloques de código, para que de esta forma estén todos los **defines** de forma global y no necesitemos o bien incluir una gran cantidad de headers en otros archivos C o repetir los defines en otros headers.

#### **User.c/ User.h**
En el header encontraremos la estructura de datos principal, la cual contiene toda la información disponible acerca de los usuarios que crean su cuenta en la red social. Encontramos también las funciones declaradas que se encuentran en el tipo C, el cual contiene todas las funciones que permiten al usuario crear su cuenta en la red social, desde ingresar su nombre hasta seleccionar sus gustos y la verificación de que los datos introducidos sean correctos.

#### **user_list.c/ user_list.h**
En este header, tenemos creada una double linked list, en este archivo tipo C y header, nos servirá para una vez el usuario esté creado, este usuario sea añadido a la lista de usuarios, en este documento crearemos un código que se le asignará al usuario, de esta forma podremos ordenar a los usuarios de forma más efectiva entre las listas. En este bloque de código, almacenamos la información del usuario en un archivo externo de texto (users.txt), este archivo se actualizará una vez se cierre el programa de forma que cuando inicializamos el programa, este archivo cargará la estructura de datos y cuando cerremos el programa, la estructura descargara su contenido en este documento de texto.

#### **request_queue.c/ request_queue.h**
Este bloque se encarga principalmente de las solicitudes de amistad que recibe el usuario, la estructura de esta es una cola donde se van almacenando las diferentes solicitudes que le llegan al usuario, dentro de este archivo tipo C, encontraremos funciones que sirven para ver el estado de la cola, introducir solicitudes en ella, borrarlas, etc. Al iniciar el programa los datos se inicializan gracias a las funciones de este bloque de código con el archivo de texto request.txt y cuando cerremos el programa, las requests se almacenarán en el mismo documento.

#### **request_stack.c/ request_stack.h**
Al igual que en request_queue, se inicializa la información que necesitará estos bloques de código para realizar sus funciones de forma correcta, para así poder gestionar las diferentes peticiones que le llegan al usuario. A diferencia de el request_queue donde nos llegan las solicitudes que otros usuarios nos han enviado, en el stack se nos ofrecerán aleatoriamente 3 usuarios de la red social para decidir si les queremos mandar o no solicitud.

#### **friends_graph.c / firends_graph.h**
En el header de este bloque de código está estructurado con una linkedlist, principalmente encontramos una estructura que contiene 3 parámetros, el código del usuario, el número de amigos y el código de los diferentes amigos que tiene el usuario. 

#### **publitacion_users.c/ publitacion_users.h**
En estos dos documentos encontramos las funciones necesarias para que los usuarios sean capaces de crear publicaciones y para poder mostrar o imprimir todas la publicaciones por consola. 

#### **dictionary_topic.c/ dictionary_topic.h**
En este bloque encontramos el diccionario, donde mediante diferentes funciones que hay en el archivo C, seremos capaces de inicializar el diccionario y gracias a las funciones que están implementadas en el main, podremos generar la tabla para ver cuales son las palabras más utilizadas en las publicaciones.

#### **users.txt, request.txt, friends.txt, publications.txt**
Estos archivos de texto sirven como bases de datos, ya que guardamos información de diferentes fuentes para así inicializar esa información en las diferentes estructuras una vez iniciamos el programa.

[LINK DEL DIAGRAMA DE ESTRUCTURA] (https://postimg.cc/r0zc5Crh)

### *Gestión de errores [Aprox. 250 palabras]*

En todos los errores que hemos tenido durante el proceso de creación de esta red social, han sido solucionados con la contribución del grupo para entender donde se hallaba el error, cuando lo hemos necesitado hemos acudido a alguna página externa del tipo StackOverFlow para ver cómo funcionaban algunos apartados que nos costaba entender o incluso preguntando a Chat GPT, aun así principalmente nos hemos apoyado en las diapositivas de teoría que encontramos en el aula global, de esta forma teníamos una estructura inicial suficiente como para construir a partir de ella y modelar a nuestro gusto.


### *Diseño del modelo de datos [Aprox. 250 palabras]*

Nuestro modelo de datos estaba dividido principalmente en una sección que se basa en los datos del propio usuario, de esta gran base de datos aparecen bases relacionadas con los datos del usuario, como por ejemplo los amigos que tiene, sus publicaciones o las peticiones de amistad que tiene pendientes. La rama principal del modelo de datos reside en el archivo llamado user.txt, donde en cada línea de texto que avanzamos encontramos la información de un usuario distinto, esta línea contiene el nombre de usuario, el nombre, la edad, el código de usuario, la contraseña, el email, ubicación y sus gustos. Después salen ramas diferentes, las cuales están todas relacionadas con el código de usuario. De la rama principal, se divide en 3 las cuales son **friends.txt**, que contiene el código de usuario con un punto al final, el número de amigos del usuario y seguido de una coma y un espacio, los códigos de los amigos del usuario. También tenemos una rama dedicada a las peticiones que tiene el usuario en **requests.txt**, donde primeramente encontramos el código del usuario seguido de un punto y el número de peticiones pendientes y el código de aquel que solicita. Por último está **publications.txt**, la cual contiene el código de usuario seguido de un punto y un char que es la publicación del usuario del cual es el código del principio. [LINK DEL DIAGRAMA] (https://postimg.cc/Z0ZJpMds)
### *Descripción y procesamiento del conjunto de datos [Aprox. 250 words]*

Principalmente los datos utilizados para este proyecto, son introducidos por nosotros de forma o bien aleatoria o datos propios, y son almacenados en las diferentes estructuras que hay en los headers del código. Una vez el programa se cierra, nuestro código se encarga de que todos aquellos datos que han sido almacenados en la estructuras del código, sean escritos en archivos de texto externos, de esta forma cuando volvamos a ejecutar el programa, el usuario no tendrá que volver a introducir todos los datos, sino que al iniciar el programa este inicializa todos los datos que tiene almacenados en sus archivos de texto. Así utilizamos documentos .txt para almacenar los datos, ya que al no ser un proyecto extremadamente ambicioso, no es necesario el uso de bases de datos más eficientes o con mayor potencial como podrían ser sistemas del estilo de MySQL.
### *REFERENCIAS*
Esta sección debe incluir las referencias utilizadas en el informe. Estas referencias incluyen cualquier sitio web, material de lectura, publicaciones o libros utilizados como inspiración.

Durante este proyecto en diferentes apartados, hemos hecho algunas partes del código con ayuda de la IA Chat GPT, el cual en según qué bloques nos ha ayudado a dar una estructura principal al código para así nosotros poder adaptarlo a nuestras necesidades y dando nuestro aporte en base a cómo queríamos que funcionase la red social.

Hemos usado también las diapositivas de teoría de EDA 2 del Aula Global para ayudar a estructurar algunos de los objetivos como por ejemplo las linked, diccionarios, pilas, colas, etc.


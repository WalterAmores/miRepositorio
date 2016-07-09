/*Creación y operaciones de un árbol binario de busqueda*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
 int nummat; /*Número de matricula*/
 char *nombre; /*Nombre del alumno*/
 struct nodo *izdo, *dcho;
};
struct nodo2{
 int nummat; /*Número de matricula*/
 char *nombre; /*Nombre del alumno*/
 //struct nodo *izdo, *dcho;
};
typedef struct nodo2 Nodo2;
typedef struct nodo Nodo;
/*Prototipo de las funciones*/
Nodo *crearNodo(int id, char *n);
Nodo *buscar(Nodo *raiz,int matricula);
void insertar(Nodo **raiz,int matricula, char *nom);
void eliminar(Nodo **r,int matricula);
void reemplazar(Nodo **act);
int buscar2(Nodo *raiz,char* nombre);

int main(){
    Nodo2 prueba={1,"Calamardo"};
    Nodo *nuevo = NULL;
    Nodo *encontrado=NULL;
    printf("\n\n\nÁrbol binario de busqueda\n\n\n");
    printf("\nInsertando elementos \n");

    insertar(&nuevo,4,"Walter");
    insertar(&nuevo,2,"Giovana");
    insertar(&nuevo,3,"Patricio\0");
    insertar(&nuevo,8,"Bob");
    insertar(&nuevo,1,"Arenita");
    insertar(&nuevo,10,"Calamardo\0");

    printf("\nBuscando elemento con matricula 3\n\n");
    encontrado=buscar(nuevo,3);

    printf("\nDatos del elemento encontrado:\n");
    printf("\nNombre: %s",encontrado->nombre);
    printf("\nMatricula: %d",encontrado->nummat);

    printf("\n\nEliminando elemento con matricula 3\n\n");
    eliminar(&nuevo,10);

    printf("\nBuscando elemento \n\n");
    encontrado=buscar(nuevo,10);
    if(encontrado!=NULL){
        printf("\nDatos del elemento encontrado:\n");
        printf("\nNombre: %s",encontrado->nombre);
        printf("\nMatricula: %d",encontrado->nummat);
    }


      printf("\nBuscando cadena \n\n");
        printf(" El resultado es: %d \n",buscar2(nuevo,prueba.nombre));


    printf("\n\n");

    return 0;
} /*Fin del main*/

Nodo *crearNodo(int id, char* n){
 Nodo *t;
 t = malloc(sizeof(Nodo));
 t->nummat = id;
 //strcpy(t->nombre,n);
 t->nombre=n;
 t->izdo = t->dcho = NULL;
 return t;
}/*Fin de crearNodo*/

Nodo *buscar(Nodo *raiz,int matricula){
 int encontrado=0; /*Bandera*/
 /*Comenzamos la busqueda */
 while(!encontrado && raiz!=NULL){
    if(matricula==raiz->nummat)
        encontrado=1;
    else if(matricula<raiz->nummat)
        raiz=raiz->izdo;
    else if(matricula>raiz->nummat)
        raiz=raiz->dcho;
 } /*Fin del while*/
 return raiz;
} /*Fin de buscar*/

void insertar(Nodo **raiz,int matricula, char *nom){
 if(!(*raiz))
    *raiz=crearNodo(matricula,nom);
 else if(matricula < (*raiz)->nummat)
    insertar(&((*raiz)->izdo),matricula,nom);
 else
    insertar(&((*raiz)->dcho),matricula,nom);
} /*Fin de insertar*/

void eliminar(Nodo **r,int matricula){
    if(!(*r))
        printf("\n!!Nodo no encontrado\n");
    else if(matricula<(*r)->nummat)
        eliminar(&((*r)->izdo),matricula);
    else if(matricula>(*r)->nummat)
        eliminar(&((*r)->dcho),matricula);
    else{ /*Nodo encontrado*/
        Nodo *q;
        q=(*r); /*Puntero al noro a suprimir*/
        if(q->izdo==NULL)
            (*r)=q->dcho;
        else if(q->dcho==NULL)
            (*r)=q->izdo;
        else{
            reemplazar(&q); /*Tiene rama izquierda y derecha*/
        } /*Fin else*/
        free(q);
    } /*Fin else*/
} /*Fin eliminar*/

void reemplazar(Nodo **act){
    Nodo *a,*p;
    p=*act;
    a=(*act)->izdo;
    while(a->dcho){ /*Rama de menores*/
        p=a;
        a=a->dcho;
    } /*Fin del while*/
    (*act)->nummat=a->nummat;
    if(p==(*act))
        p->izdo=a->izdo;
    else
        p->dcho=a->izdo;
    (*act)=a;
} /*Fin reemplazar*/

int buscar2(Nodo *raiz,char* nombre){
int encontrado=0;

if(nombre=="Calamardo")
    encontrado=1;

return encontrado;

}



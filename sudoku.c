#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}



bool repite(Node *n, int num, int fila, int colum){
  int arreglo[10]= {0};
  
  //comprobacion por fila
  for(int i=0; i<9; i++){
    //if(n->sudo[fila][i]==num && i!=colum) return true;
    /*if(n->sudo[fila][i]==num){
      arreglo[num]+=1;
      if(arreglo[num]>1) return true;
    }*/
    arreglo[n->sudo[fila][i]]+=1;
    if(arreglo[num]>1) return true;
  }
  //comprobacion por columna
  for(int i=0; i<9; i++){
    if(n->sudo[i][colum]==num && i!=fila) return true;
    
  }
  
  return false;
}

int is_valid(Node* n){
  return 1;
  for(int j=0; j<9 ; j++){
    for(int k =0; k<9; k++){
      int num = n->sudo[j][k];
      if(repite(n, num,j,k)== true) return 0;
    }
  }
  return 1;
}
bool buscarenmatriz(Node *nodo, int*j, int *k){
  for(int n=0; n<9; n++){
    for(int m=0; m<9; m++){
      if(nodo->sudo[n][m] == 0){
        *j = n;
        *k = m;
        return true;
      } 
    }
  }
  return false;
}

List* get_adj_nodes(Node* n){
    List* list=createList();
    if(n== NULL) return NULL;
    for(int i=1 ; i<=9 ; i++){
      Node *aux = createNode();
      int j=0,k=0;
      bool hayceros = buscarenmatriz(n,&j,&k);
      if(hayceros == false) break;
      aux = copy(n);
      aux->sudo[j][k] =i;
      pushBack(list, aux);
    }
  
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
#include <stdio.h>

struct candidatos{
int matricula;
float nota;
};

struct candidatos lista[100];

int main(void) {
   void inicializar();
inicializar();
for(int i = 0; i<100;i++){
printf("matericula %d nota %.2f",lista[1].matricula,lista[1].nota);
printf("\n");
}

  return 0;
}
void inicializar(){
  for(int i=1;i<100;i++){
    lista[i].matricula = -1;
    lista[i].matricula = 0;

  }
}


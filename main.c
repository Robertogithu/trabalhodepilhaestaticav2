#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 10

typedef struct{
        char titulo [50];
        int valor;
        float peso;
        
}DOCUMENTO;

typedef struct{
  DOCUMENTO documentos[TAMANHO_MAXIMO];
  DOCUMENTO* topo;
}PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
int push(PILHA* pilha, DOCUMENTO documento);
void pop(PILHA* pilha);
int length(PILHA* pilha);

int main() {
         PILHA minhaPilha;

         inicializarPilha(&minhaPilha);

         DOCUMENTO D1;
         strcpy (D1.titulo, "Texto1");
         D1.valor = 5;
         D1.peso = 3.5;

         DOCUMENTO D2;
         strcpy (D2.titulo, "Texto1");
         D2.valor = 8;
         D2.peso = 4.9;

         DOCUMENTO D3;
         strcpy (D3.titulo, "Texto1");
         D3.valor = 9;
         D3.peso = 99.99;



         push(&minhaPilha, D1);
         push(&minhaPilha, D2);
         push(&minhaPilha, D3);

        // imprimirPilha(&minhaPilha);

         pop(&minhaPilha);

        // imprimirPilha(&minhaPilha);

         limpaPilha(&minhaPilha);

         imprimirPilha(&minhaPilha);

}

void pop(PILHA* pilha){
        if (length(pilha)>0){
           pilha ->topo -= 1;
        }

}

int push(PILHA* pilha, DOCUMENTO documento){
         if(length(pilha) < TAMANHO_MAXIMO){
                  pilha-> documentos[length(pilha)] = documento;
                  pilha->topo= &pilha->documentos[length(pilha)];

                  return 1;

         }

  return 0;
}
void inicializarPilha(PILHA* pilha){
        pilha->topo = NULL;
}
void limpaPilha(PILHA* pilha){
        pilha->topo = NULL;
}


int length(PILHA* pilha){
  DOCUMENTO* topo = pilha->topo;
  int i = 0;
  if(topo == NULL) return i;
  DOCUMENTO* tmpDocumento = &pilha->documentos[i];
while (topo >= tmpDocumento){
i++;
tmpDocumento = &pilha->documentos[i];
}
return i;
}


void imprimirPilha(PILHA* pilha){
int i = 0;
  DOCUMENTO* topo = pilha->topo;
  while(i < length(pilha)){
    DOCUMENTO documento = pilha->documentos[i];
    printf("Documento: %d\n", i + 1);
    printf("Título: %s\n", pilha->documentos[i].titulo);
    printf("Valor: %d\n", pilha->documentos[i].valor);
    printf("Peso: %.2fkg\n", pilha->documentos[i].peso);
    i++;
    printf("\n\n");        
   
    }

}
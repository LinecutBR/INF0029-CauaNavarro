#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int* vetorPrincipal[TAM];
int tam[TAM];
int ocupado[TAM]= {0,0,0,0,0,0,0,0,0,0};

void bubbleSort(int vetor[], int size) {
    int i, j, aux;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao-1]!=NULL){
    return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    // se posição é um valor válido {entre 1 e 10}
   else if (posicao < 1 || posicao > 10)
   {
    return POSICAO_INVALIDA;
   }
    // o tamanho nao pode ser menor que 1
   else if(tamanho < 1)
   {
    return TAMANHO_INVALIDO;
   }
  vetorPrincipal[posicao-1]=malloc(tamanho*sizeof(int));
  tam[posicao-1]=tamanho;
    // o tamanho ser muito grande
    if(!vetorPrincipal[posicao-1]){
    return SEM_ESPACO_DE_MEMORIA;
    }

    // deu tudo certo, crie
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if (posicao<1||posicao>10)
        return POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao-1]!=NULL)
        {
            if (tam[posicao-1]>ocupado[posicao-1])
            {
                //insere
                vetorPrincipal[posicao-1][ocupado[posicao-1]] = valor;
                ocupado[posicao-1]++;
                return SUCESSO;
            }
            else
            {
                return SEM_ESPACO;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if (vetorPrincipal[posicao-1]==NULL){
      return SEM_ESTRUTURA_AUXILIAR;
    }
    if (ocupado[posicao-1]==0){
      return ESTRUTURA_AUXILIAR_VAZIA;
    }
    if (posicao<1||posicao>10){
        return POSICAO_INVALIDA;
    }
    ocupado[posicao-1]--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int temp = -1;
  
  if (vetorPrincipal[posicao-1]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }
  if (ocupado[posicao-1]==0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  if (posicao<1||posicao>10)
      return POSICAO_INVALIDA;

  for(int i=0;i<ocupado[posicao-1];i++){
    if(vetorPrincipal[posicao-1][i]==valor){
      temp=i;
      break;  
    }
  }
  if(temp!=-1){
    for(int i=temp;i<ocupado[posicao-1];i++){
      vetorPrincipal[posicao-1][i]=vetorPrincipal[posicao-1][i+1];
  }
    ocupado[posicao-1]--;
    return SUCESSO;
  }
  else
    return NUMERO_INEXISTENTE;
}
// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }
    else
        return SUCESSO;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  if (vetorPrincipal[posicao-1]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (posicao<1||posicao>10){
    return POSICAO_INVALIDA;
  }
  
  for(int i=0;i<ocupado[posicao-1];i++){
    vetorAux[i]=vetorPrincipal[posicao-1][i];
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  if (vetorPrincipal[posicao-1]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }

  else if (posicao<1||posicao>10){
    return POSICAO_INVALIDA;
  }
  else{
  for(int i=0;i<ocupado[posicao-1];i++){
    vetorAux[i]=vetorPrincipal[posicao-1][i];
  }
  bubbleSort (vetorAux,ocupado[posicao-1]);
  return SUCESSO;
  }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    
    int estruturas = 0, contador=0;
    
    for(int i=0;i<TAM;i++){
      if(vetorPrincipal[i]!=NULL&& tam[i]>0 &&ocupado[i]>0){
        for(int j=0;j<ocupado[i];j++){
          vetorAux[contador]=vetorPrincipal[i][j];
          contador++;
        }
        estruturas++;
      }
    }
  if(estruturas==0){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  else{
    return SUCESSO;
  }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

  int estruturas = 0, contador=0;

  for(int i=0;i<TAM;i++){
    if(vetorPrincipal[i]!=NULL&& tam[i]>0 &&ocupado[i]>0){
      for(int j=0;j<ocupado[i];j++){
        vetorAux[contador]=vetorPrincipal[i][j];
        contador++;
      }
      estruturas++;
    }
  }
  if(estruturas==0){
  return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  else{
    bubbleSort(vetorAux,contador);
    return SUCESSO;
  }
  
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

  novoTamanho=novoTamanho+tam[posicao-1];
  if (vetorPrincipal[posicao-1]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (posicao<1||posicao>10){
    return POSICAO_INVALIDA;
  }
  if(novoTamanho<1){
    return NOVO_TAMANHO_INVALIDO;
  }
  vetorPrincipal[posicao-1]=malloc(novoTamanho*sizeof(int));
  tam[posicao-1]=novoTamanho;
  
    if(!vetorPrincipal[posicao-1]){
    return SEM_ESPACO_DE_MEMORIA;
    }

  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

  if (vetorPrincipal[posicao-1]==NULL){
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (posicao<1||posicao>10){
    return POSICAO_INVALIDA;
  }
  if(ocupado[posicao-1]==0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  return ocupado[posicao-1];
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
  int tamTotal = 0;
  for (int i=0;i<TAM;i++){
    tamTotal = tamTotal + tam[i];
  }
  if(tamTotal==0){
    return NULL;
  }
  else{
    No *head= (No*) malloc (sizeof(No));
    head->prox = NULL;

    int vetorTotal[tamTotal];
    getDadosDeTodasEstruturasAuxiliares(vetorTotal);

    for(int i=0;i<tamTotal;i++){
      No* novoElemento = malloc(sizeof(No));
      novoElemento->conteudo = vetorTotal[i];
      novoElemento->prox = NULL;
      if(head->prox==NULL){
        head->prox=novoElemento;
      }
      else{
        No* atual=head;
        while(atual->prox!=NULL){
          atual = atual->prox;
        }
        atual->prox=novoElemento;
      }
    }
    return head;
  }

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No* current = inicio;
  int i = 0;
  while(current!=NULL){
    vetorAux[i]=current->conteudo;
    current=current->prox;
    i++;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No* current = *inicio;

  while(current->prox != NULL){
    No* aux = (No*)malloc (sizeof(No));
    aux = current->prox;
    free(current);
    current = aux;
  }

  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i = 0;	i < TAM ;	i++){
    vetorPrincipal[i]=	NULL;
    tam[i]=0;
    ocupado[i]=0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for(int i = 0;	i < TAM ;	i++){
    free(vetorPrincipal[i]);
  }
}
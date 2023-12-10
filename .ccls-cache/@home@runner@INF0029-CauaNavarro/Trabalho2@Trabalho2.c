#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct EstruturaPrincipal{
  int tamanho;
  int qtdtemp; // isso aqui serve para ir incrementando o valor e saber se jÃ¡ chegou ao tamanho.
  int *vetorAux;
} structPrincipal;

structPrincipal vetorPrincipal[TAM];

void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
/*
Objetivo: criar estrutura auxiliar na posiÃ§Ã£o 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - jÃ¡ tem estrutura na posiÃ§Ã£o
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaÃ§o de memÃ³ria
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
  // se posiÃ§Ã£o Ã© um valor vÃ¡lido {entre 1 e 10}
  if(posicao < 1	|| posicao >	TAM ){
    return POSICAO_INVALIDA;
    //retorno = POSICAO_INVALIDA;
  }
  if(tamanho < 1){ // o tamanho nao pode ser menor que 1
    //retorno = TAMANHO_INVALIDO;
    return TAMANHO_INVALIDO;
  }
  if(	vetorPrincipal[posicao	-1].vetorAux !=	NULL){
    return JA_TEM_ESTRUTURA_AUXILIAR;
    // a posicao pode jÃ¡ existir estrutura auxiliar
    //retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  }
  vetorPrincipal[posicao	-1].vetorAux	=	malloc (tamanho * sizeof(int));
  vetorPrincipal[posicao	-1].tamanho	=	tamanho;
  if (!vetorPrincipal[posicao	-1].vetorAux){
    // o tamanho ser muito grande
    return SEM_ESPACO_DE_MEMORIA;
    //retorno = SEM_ESPACO_DE_MEMORIA;	
  }
  // deu tudo certo, crie
  return SUCESSO;// isso aqui recebe o tamanho? pois essa variÃ¡vel nÃ£o Ã© ponteiro, porÃ©m o vetor de struct Ã© um ponteiro.
  //retorno = SUCESSO;
}

/*
Objetivo: inserir nÃºmero 'valor' em estrutura auxiliar da posiÃ§Ã£o 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - nÃ£o tem espaÃ§o
    SEM_ESTRUTURA_AUXILIAR - NÃ£o tem estrutura auxiliar
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  int retorno = 0;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;
  //quando a posiÃ§Ã£o Ã© invÃ¡lida?
  if (posicao < 1 || posicao > 10)
    retorno	= POSICAO_INVALIDA;
  else
  {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao-1].vetorAux	!= NULL)
    {
      if (vetorPrincipal[posicao-1].tamanho	> vetorPrincipal[posicao-1].qtdtemp)// verificar se tem espaÃ§o!
      {
        vetorPrincipal[posicao	-1].vetorAux	[vetorPrincipal[posicao	-1].qtdtemp]	= valor;
         vetorPrincipal[posicao	-1].qtdtemp++;
        //insere
        retorno = SUCESSO;
      }
      else
      {
        retorno = SEM_ESPACO;
      }
    }
    else
    {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. ApÃ³s excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta Ã© uma exclusÃ£o lÃ³gica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - NÃ£o tem estrutura auxiliar
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{	
  if(	posicao	<	1 || posicao	> TAM	)
    return  POSICAO_INVALIDA;
  if(vetorPrincipal[posicao	-1].vetorAux	==	NULL)
    return	SEM_ESTRUTURA_AUXILIAR;
  else{
    if(vetorPrincipal[posicao	-1].qtdtemp	==	0){
      return ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
      vetorPrincipal[posicao	-1].qtdtemp--;
      return SUCESSO;
    }
  }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posiÃ§Ã£o 'posicao'.
Caso seja excluido, os nÃºmeros posteriores devem ser movidos para as posiÃ§Ãµes anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta Ã© uma exclusÃ£o lÃ³gica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posiÃ§Ã£o 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - NÃ£o tem estrutura auxiliar
    NUMERO_INEXISTENTE - NÃºmero nÃ£o existe
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  if(posicao	<	1 || posicao	> TAM	)
    return  POSICAO_INVALIDA;
  if(vetorPrincipal[posicao	-1].vetorAux	==	NULL)
    return	SEM_ESTRUTURA_AUXILIAR;
  else{
    if(vetorPrincipal[posicao	-1].qtdtemp	==	0){
      return ESTRUTURA_AUXILIAR_VAZIA;
    }else{
      int existe	=	0;
      for(int i=0;	i	<	(vetorPrincipal[posicao	-1].qtdtemp)	;	i++){
        if (vetorPrincipal[posicao - 1].vetorAux[i] == valor) {
          existe = 1;
          for (int k = i, j = k + 1; k < vetorPrincipal[posicao - 1].qtdtemp - 1; k++, j++) {
            int aux = vetorPrincipal[posicao - 1].vetorAux[k];
            vetorPrincipal[posicao - 1].vetorAux[k] = vetorPrincipal[posicao - 1].vetorAux[j];
            vetorPrincipal[posicao - 1].vetorAux[j] = aux;
         }
          vetorPrincipal[posicao - 1].qtdtemp--;
        }

      }
      if(existe	==	1)
        return SUCESSO;
      else
        return NUMERO_INEXISTENTE;
    }
  }
}

// se posiÃ§Ã£o Ã© um valor vÃ¡lido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
      retorno = POSICAO_INVALIDA;
    }
    else
      retorno = SUCESSO;
    return retorno;
}
/*
Objetivo: retorna os nÃºmeros da estrutura auxiliar da posiÃ§Ã£o 'posicao (1..10)'.
os nÃºmeros devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posiÃ§Ã£o 'posicao'
    SEM_ESTRUTURA_AUXILIAR - NÃ£o tem estrutura auxiliar
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno;
  int posVet = 0;

  if (posicao < 1 || posicao > 10) {
    return POSICAO_INVALIDA;
  } else if (vetorPrincipal[posicao-1].vetorAux == NULL && vetorPrincipal[posicao-1].tamanho == 0) {
    return SEM_ESTRUTURA_AUXILIAR;
  } else {
    if (vetorPrincipal[posicao-1].qtdtemp == 0) {
      return ESTRUTURA_AUXILIAR_VAZIA;
    } else {
      for (int i = 0; i < vetorPrincipal[posicao-1].qtdtemp; i++) {
        vetorAux[posVet] = vetorPrincipal[posicao-1].vetorAux[i];
        posVet++;
      }
      return SUCESSO;
    }
  }

  return retorno;
}

/*
  Objetivo: retorna os nÃºmeros ordenados da estrutura auxiliar da posiÃ§Ã£o 'posicao (1..10)'.
  os nÃºmeros devem ser armazenados em vetorAux
  Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posiÃ§Ã£o 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - NÃ£o tem estrutura auxiliar
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
  int posVet=0;
  if(posicao < 1 || posicao >10)
    return POSICAO_INVALIDA;
  if(ehPosicaoValida(posicao) == SUCESSO) {
    if(vetorPrincipal[posicao-1].vetorAux != NULL && vetorPrincipal[posicao-1].tamanho	> 0) {
      if(vetorPrincipal[posicao-1].qtdtemp > 0) {
        for(int i = 0; i< vetorPrincipal[posicao-1].qtdtemp; i++) {
          vetorAux[posVet] = vetorPrincipal[posicao-1].vetorAux[i];
          posVet++;
        }
        bubbleSort(vetorAux,vetorPrincipal[posicao-1].qtdtemp);
        return SUCESSO;
      } else
          retorno = ESTRUTURA_AUXILIAR_VAZIA;

    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;

  } else
      retorno = POSICAO_INVALIDA;

  return retorno;
}


/*
Objetivo: retorna os nÃºmeros de todas as estruturas auxiliares.
os nÃºmeros devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posiÃ§Ã£o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estÃ£o vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int contVetorAux	=	0;
    int sucesso	=	0;
    for(int i=0;	i	<	TAM; i++){
      if(vetorPrincipal[i].vetorAux	!= NULL &&  vetorPrincipal[i].tamanho >0 && vetorPrincipal[i].qtdtemp > 0){
        for(int j=0;	j	<	vetorPrincipal[i].qtdtemp	;j++){
          vetorAux[contVetorAux]	=	vetorPrincipal[i].vetorAux[j];
          contVetorAux++;
        }
        sucesso++;
      }
    }
    if (sucesso	==	0){
      retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{
      retorno = SUCESSO;
    }
    return retorno;
}
/*
Objetivo: retorna os nÃºmeros ordenados de todas as estruturas auxiliares.
os nÃºmeros devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posiÃ§Ã£o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estÃ£o vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int retorno	=	TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  int contVetorAux	=	0;
  int sucesso	=	0;
  for(int i=0;	i	<	TAM; i++){
    if(vetorPrincipal[i].vetorAux	!= NULL &&  vetorPrincipal[i].tamanho >0 && vetorPrincipal[i].qtdtemp > 0){
      for(int j=0;	j	<	vetorPrincipal[i].qtdtemp	;j++){
        vetorAux[contVetorAux]	=	vetorPrincipal[i].vetorAux[j];
        contVetorAux++;
      }
      sucesso++;
    }
  }
  bubbleSort(vetorAux,contVetorAux);
  if (sucesso	==	0){
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }else{
    retorno = SUCESSO;
  }
  return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posiÃ§Ã£o 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual;
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - NÃ£o tem estrutura auxiliar
    POSICAO_INVALIDA - PosiÃ§Ã£o invÃ¡lida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho nÃ£o pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocaÃ§Ã£o do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

  novoTamanho = novoTamanho + vetorPrincipal[posicao-1].qtdtemp;

  if (posicao < 1 || posicao > 10) {
    return POSICAO_INVALIDA;
  } else if (novoTamanho < 1) {
    return  NOVO_TAMANHO_INVALIDO;
  } else if (vetorPrincipal[posicao-1].vetorAux == NULL &&	vetorPrincipal[posicao-1].qtdtemp == 0 &&  vetorPrincipal[posicao-1].tamanho == 0) {
    return SEM_ESTRUTURA_AUXILIAR;
  } else {
    vetorPrincipal[posicao-1].tamanho = novoTamanho;
    vetorPrincipal[posicao -1].vetorAux = realloc(vetorPrincipal[posicao-1].vetorAux, vetorPrincipal[posicao-1].tamanho * sizeof(int));
    if (!vetorPrincipal[posicao -1].vetorAux)
      return SEM_ESPACO_DE_MEMORIA;
    if (vetorPrincipal[posicao-1].qtdtemp > vetorPrincipal[posicao-1].tamanho ) {
      vetorPrincipal[posicao-1].qtdtemp = vetorPrincipal[posicao-1].tamanho;
    }
  return SUCESSO;
  }


}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posiÃ§Ã£o 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posiÃ§Ã£o invÃ¡lida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um nÃºmero int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  if(posicao < 1	||	posicao > 10){
    return POSICAO_INVALIDA;
  }else if(vetorPrincipal[posicao-1].qtdtemp == 0 && vetorPrincipal[posicao-1].vetorAux == NULL){
    return  SEM_ESTRUTURA_AUXILIAR;
  }else if(vetorPrincipal[posicao-1].qtdtemp	==	0){
    return  ESTRUTURA_AUXILIAR_VAZIA;
  }else{
    return vetorPrincipal[posicao-1].qtdtemp;
  }
}

/*
Objetivo: montar a lista encadeada com cabeÃ§ote com todos os nÃºmeros presentes em todas as estruturas.
Retorno (No*)
    NULL, caso nÃ£o tenha nenhum nÃºmero nas listas
    No*, ponteiro para o inÃ­cio da lista com cabeÃ§ote
*/

No *montarListaEncadeadaComCabecote()
{
  int totalElementosAux = 0;
  for(int i=0; i	< TAM ;i++){
    totalElementosAux	+=	vetorPrincipal[i].qtdtemp;
  }
  //printf("totalElementosAux:%d\n ", totalElementosAux);
  if (totalElementosAux ==	0){
    return NULL;
  }else {
    No *inicio = (No*)	malloc (sizeof(No)); //alocando memoria dinamicamente p/ inicio
    inicio->prox = NULL; // fzd o proximo do inicio apontar pra NULL

    int vetor[totalElementosAux]; // criando um vetor com os espaÃ§os que estÃ£o sendo usados na estrutura estÃ¡tica 	
    getDadosDeTodasEstruturasAuxiliares(vetor); // colocando todos os dados nesse vetor
    //printf("vetor[0]:%d\n", vetor[9]);
  for(int i = 0	; i	<	totalElementosAux	; i++)
    {
      No* novo = malloc(sizeof(No));
      novo->conteudo = vetor[i]; // fazendo com que o conteudo receba o vetor na exata posiÃ§Ã£o
      novo->prox = NULL; // fazendo com que o novo aponte para NULL 
      if(inicio->prox == NULL){
        inicio->prox = novo; // se for o primeiro elemento da lista ele apenas vai apontar pro novo
      }else{
        No* atual = inicio;
        while(atual->prox != NULL) // faÃ§a enquanto o proximo do atual seja o ultimo da LE
          atual = atual->prox;
        atual->prox = novo; // ultimo da LE aponta pro novo
      }
    }
  return inicio;
  }
}

/*
Objetivo: retorna os nÃºmeros da lista encadeada com cabeÃ§ote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No* atual = inicio->prox;
  int i = 0;
  while(atual->prox != NULL){
    vetorAux[i] = atual->conteudo;
    atual = atual->prox;
    i++;
  }
  vetorAux[i] = atual->conteudo;
}

/*
Objetivo: Destruir a lista encadeada com cabeÃ§ote a partir de inÃ­cio.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/

void destruirListaEncadeadaComCabecote(No **inicio)
{
  No* atual = *inicio;

  while(atual->prox != NULL){
    No* tmp = (No*)malloc (sizeof(No));
    tmp = atual->prox;
    free(atual);
    atual = tmp;
  }

  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
  for(int i = 0;	i < TAM ;	i++){
    vetorPrincipal[i].vetorAux	=	NULL;
    vetorPrincipal[i].tamanho	=	0;
    vetorPrincipal[i].qtdtemp	=	0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaÃ§os de memÃ³ria das estruturas auxiliares.
*/

void finalizar()
{
  for(int i = 0;	i < TAM ;	i++){
    free(vetorPrincipal[i].vetorAux);
  }
}
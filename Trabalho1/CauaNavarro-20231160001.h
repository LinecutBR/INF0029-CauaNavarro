// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Cauã Navarro Fernandes dos Anjos
//  email: caua.navarro27@gmail.com
//  Matrícula: 20231160001
//  Semestre: 2023.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef CauaNavarro20231160001
#define CauaNavarro20231160001

typedef struct diasmesesanos {
  int qtdDias;
  int qtdMeses;
  int qtdAnos;
  int retorno;
} DiasMesesAnos;

int q1(char str[]);
DiasMesesAnos q2 (char dataInicio [], char dataFim[]);
int q3(char str[],char letter, int caseSensitive);
int q4(char strTexto[250], char strBusca[50], int posicoes[30]);
int q5 (int num);
int q6 (int num, int numBusca);

#endif
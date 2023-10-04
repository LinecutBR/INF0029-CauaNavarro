#include <stdio.h>
#include "CauaNavarro-20231160001.h"
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 100

int q1 (char str[]){
  int diaMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, dia, mes, ano;
  int tamChar;
  tamChar = strlen(str);
  dia = mes = ano = 0;
  sscanf(str,"%d/%d/%d",& dia, & mes, & ano);
  if(ano>=0&&ano<=9999){
    if(mes>=1&&mes<=12){
      if(mes==2){
        if((ano%4==0)||(ano%100==0&&ano%400==0)){
          if(dia>=1&&dia<=29){
            return 1;
          }
          else{
            return 0;
          }
        }
          else{
            if(dia>=1&&dia<=28){
              return 1;
            }
            else{
              return 0;
            }
        }
    }
    else{
    if(dia>=1&&dia<=diaMes[mes]){
      return 1;
    }
    else{
      return 0;
    }
  }
  }
  else{
    return 0;
  }
  
}
else{
  return 0;
}
}


DiasMesesAnos q2 (char dataInicio [], char dataFim[]){
  int diaIni, mesIni, anoIni, diaFim, mesFim, anoFim;
  int diaMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  sscanf(dataInicio,"%d/%d/%d",& diaIni, & mesIni, & anoIni);
  sscanf(dataFim,"%d/%d/%d",& diaFim, & mesFim, & anoFim);
  DiasMesesAnos result;
  if(q1(dataInicio)==0){
    result.qtdAnos=0;
    result.qtdDias=0;
    result.qtdMeses=0;
    result.retorno=2;
    return result;
  }
  else if(q1(dataFim)==0){
    result.qtdAnos=0;
    result.qtdDias=0;
    result.qtdMeses=0;
    result.retorno=3;
    return result;
  }
    
  else if((diaIni+mesIni*100+anoIni*1000)>(diaFim+mesFim*100+anoFim*1000)){
    result.qtdAnos=0;
    result.qtdDias=0;
    result.qtdMeses=0;
    result.retorno=4;
    return result;
  }

  else{
    result.retorno=1;
    if(diaIni==diaFim){
      result.qtdDias = 0;
      if(mesIni>mesFim){
        result.qtdMeses = (12 - mesIni) + mesFim;
        result.qtdAnos = anoFim - anoIni - 1;
      }
      else{
        result.qtdMeses = mesFim-mesIni;
        result.qtdAnos = anoFim - anoIni;
      }
    }
  
    else{
      if(mesIni==2){
        if(diaIni>diaFim){
          if((anoFim%4==0)||(anoFim%100==0&&anoFim%400==0)){
            result.qtdDias = (29 - diaIni) + diaFim;
          }
          else{
            result.qtdDias = (diaMes[mesIni-1] - diaIni) + diaFim;
          }
          if(mesIni>mesFim){
          result.qtdMeses = (12 - mesIni) + mesFim - 1;
          result.qtdAnos = anoFim - anoIni - 1;
         }
         else{
          result.qtdMeses = mesFim-mesIni - 1;
          result.qtdAnos = anoFim - anoIni;
         }
        }
        else{
          result.qtdDias = diaFim-diaIni;
          if(mesIni>mesFim){
          result.qtdMeses = (12 - mesIni) + mesFim;
          result.qtdAnos = anoFim - anoIni - 1;
        }
        else{
          result.qtdMeses = mesFim-mesIni;
          result.qtdAnos = anoFim - anoIni;
        }
        }
      }
      else
        if(diaIni>diaFim){
          result.qtdDias = (diaMes[mesIni-1] - diaIni) + diaFim;
          if(mesIni>mesFim){
          result.qtdMeses = (12 - mesIni) + mesFim - 1;
          result.qtdAnos = anoFim - anoIni - 1;
         }
         else{
          result.qtdMeses = mesFim-mesIni - 1;
          result.qtdAnos = anoFim - anoIni;
         }
      }

      else{
          result.qtdDias = diaFim-diaIni;
        if(mesIni>mesFim){
          result.qtdMeses = (12 - mesIni) + mesFim;
          result.qtdAnos = anoFim - anoIni - 1;
        }
        else{
          result.qtdMeses = mesFim-mesIni;
          result.qtdAnos = anoFim - anoIni;
        }
      }
    }
    }
  return result;
}

int q3(char str[],char letter, int caseSensitive){
  char copia[TAM_MAX], copiaLetter;
  int tam = strlen(str), qtd=0;
  strcpy(copia,str);
  copiaLetter=letter;
  if(caseSensitive==0){
    if(letter>='A'&&letter<='Z')
      copiaLetter+=32;
    for(int x=0;x<tam;x++){
      if(copia[x]>='A'&&copia[x]<='Z')
        copia[x]+=32;
    }
  }
    for(int x;x<tam;x++){
      if (copia[x]==copiaLetter)
        qtd++;
      
    }
  
  return qtd;
}


int q4(char strTexto[250],char strBusca[50],int posicoes[30]){
  int tamString=0, tamBusca=0, auxFim=0,auxIni=0,verif=0,auxBusca=0,position=0,qtdAcertos=0;
  tamString=strlen(strTexto);
  tamBusca=strlen(strBusca);
  for(int x=0;x<tamString;x++){
    auxFim=auxIni=verif=auxBusca=0;
    if(strTexto[x]==strBusca[auxBusca]){
      auxIni=x;
      auxFim=x+1;
      verif++;
      auxBusca++;
      while((auxFim-auxIni)<tamBusca){
        if(strTexto[auxFim]==strBusca[auxBusca])
          verif++;
        auxFim++;
        auxBusca++;
      }
      if(verif==tamBusca){
        posicoes[position]=auxIni+1;
        position++;
        posicoes[position]=auxFim;
        position++;
        qtdAcertos++;
        x+=tamBusca-1;
      }
    } 
  }
  return qtdAcertos;
}


int q5 (int num){
  int aux=num, divisor=1,resto=10, casaD=0,x,algarism[TAM_MAX],numResult=0,multiplier=1;
  while (aux!=0){
    aux/=10;
    casaD++;
  }

  for(x=0;x<casaD;x++){
    algarism[x]=(num/divisor)%resto;
    divisor*=10;
  }

  for(x=casaD-1;x>=0;x--){
    numResult+=algarism[x]*multiplier;
    multiplier*=10;
  }
  return numResult;
}


int q6 (int num, int numBusca){

  int  qtdAcerto=0, aux, casaDNum=0,casaDBus=0, base[TAM_MAX], busca[TAM_MAX],x, divisor=1, resto=10,auxBus=0,verif=0;

  aux = num;
  while (aux!=0){
    aux/=10;
    casaDNum++;
  }

  aux = numBusca;
  while (aux!=0){
    aux/=10;
    casaDBus++;
  }
  for(x=0;x<casaDNum;x++){
    base[x]=(num/divisor)%resto;
    divisor*=10;
  }
  
  divisor = 1;
  
  for(x=0;x<casaDBus;x++){
    busca[x]=(numBusca/divisor)%resto;
    divisor*=10;
  }

  for(x=0;x<casaDNum;x++){
    auxBus=0;
    if(base[x]==busca[auxBus]){
      auxBus++;
      while((x+auxBus)-x<casaDBus && base[x+auxBus]==busca[auxBus]){
        auxBus++;
      }
    }
    if(auxBus==casaDBus){
      qtdAcerto++;
      x+=auxBus-1;
    }
  }
  return qtdAcerto;
}
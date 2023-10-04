#include <stdio.h>

int main(void) {
  int idade[10], x, sum=0, mediaid;
  
  for(x=0;x<10;x++){
    scanf("%d",&idade[x]);
    sum=sum+idade[x];
  }
  
  mediaid = sum/10;

  for(x=0;x<10;x++){
    if(idade[x] > mediaid)
      printf("%d ", idade[x]);
  }
  return 0;
}
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int sorteio(int numSort[],int i)
{
  //irá sortear as 5 palavras usadas no jogo
  numSort[i]=rand()%49;
  for(int c=0;c<i;c++)
  {
    if(numSort[i]==numSort[c])
    {
      i--;//se o número se repetir irá tentar de novo
    }
  }
  return i;
}
void esconderpal(char palOcult[][20],char palSort[][20],int i,int tam[])
{
  //vai passar o numero de letras da palavra
  tam[i]=strlen(palSort[i]);
  int c;
  for(c=0;c<tam[i];c++)
  {
    //representa a palavra a ser adivinhada
    palOcult[i][c]='_';
  }
  palOcult[i][c]='\0';
}
//Calcula a pontuação
int pontuacao(int tam[], char palSort[][20], char palOcult[][20],int cont,char letra,int *pts,int *chances)
{
  int j=0;
  for(int i=0;i<tam[cont];i++)
  {
    if(palSort[cont][i]==letra)
    {
      *pts=*pts+1;
      palOcult[cont][i]=letra;
      j=1;
    }
    else if(!j && i+1==tam[cont])
    {
      *chances=*chances-1;
    }
  }
  return 0;
}
int novoJogo(int *pts,int *chances,int *cont,int tam[],int *pal, int *g,int *p,int *l)
{
  *g=0;
  *p=0;
  if(*pts==tam[*cont])
  {
    *cont=*cont+1;
    *pts=0;
    *chances=6;
    *pal=*pal+1;
    *g=1;
    *l=0;
  }
  if(*chances==0)
  {
    *cont=*cont+1;
    *pts=0;
    *chances=6;
    *p=1;
    *l=0;
  }
  return 0;
}
int texto(int cont,int chances,char palOcult[][20],char palSort[][20],char letra,int usou,int n,int g,int p)
{
  //Limpa a tela toda vez que entra no loop
  system("cls");
  printf("\033[4;25HJogo da forca\n\n");
  printf("\033[6;26HPalavra %d/%d.\n\n",cont+1,n);
  printf("\033[9;15HTente descobrir qual é a palavra.");
  if(usou)
  {
    printf("\033[11;15HVocê já usou essa letra.");
  }
  else if(p)
  {
    printf("\033[11;15HVocê perdeu a rodada.");
  }
  else if(g)
  {
    printf("\033[11;15HVocê ganhou a rodada.");
  }
  if(chances<6)
  {
    printf("\033[11;50Ho");
  }
  if(chances<5)
  {
    printf("\033[12;51H)");
  }
  if(chances<4)
  {
    printf("\033[12;50H|");
  }
  if(chances<3)
  {
    printf("\033[12;49H(");
  }
  //esse if acaba nem aparecendo na tela
  if(chances<2)
  {
    printf("\033[13;49H/");
  }
  else if(chances<1)
  {
    printf("\033[13;51H%c",92);
  }
  printf("\033[13;15HA %dº palavra é: %s",cont+1,palOcult[cont]);
  printf("\033[15;15HDigite uma letra: ");
  return 0;
}
int repetiuLet(char letUsadas[30],int l,int letra,int *usou,int gan,int per)
{
  letUsadas[l]=letra;
  *usou=0;
  for(int i=0;i<l;i++)
  {
    if(gan || per)
    {
      letUsadas[i]=' ';
    }
    if(letUsadas[l]==letUsadas[i])
    {
      *usou = 1;
    }
  }
  l=l+1;
  return 0;
}
int
main ()
{
    setlocale(LC_ALL, "portuguese");
  char vet[50][20]={"cavalo","lagarto","camelo","cachorro","gato","galinha","minhoca","lesma","elefante","borboleta","cadeira","mesa","estante","televisao","escrivaninha","computador","chuveiro","comoda","computador","monitor","fruta","laranja","banana","pitanga","acerola","tanjerina","mamao","abacate","morango","tomate","bonito","feio","talentoso","inutil","fedorento","cheiroso","esperto","idiota","cafajeste","paquerador","batata","repolho","manjericao","coentro","mandioca","beterraba","cenoura","polvilho","palavra","easteregg"};
  int numSort[5],tam[5],cont=0,chances=6,n=5,pts=0,palAcert=0,l=0,usou=0,ga=0,pe=0;
  char palSort[50][20],palOcult[50][20],letra,letUsadas[30];
  //O código começa daqui pra baixo
  srand(time(NULL));
  for(int i=0;i<n;i++)
  {
    //função de sortear as palavras
    i=sorteio(numSort,i);
    strcpy(palSort[i],vet[numSort[i]]);
    //vai passar as palvaras sorteadas na biblioteca
    esconderpal(palOcult,palSort,i,tam);
  }

  //aqui é o laço das cinco palavras sorteadas
  //cont representa a linha da matriz onde se encontra a palavra
  while(cont<n)
  {
    texto(cont,chances,palOcult,palSort,letra,usou,n,ga,pe);
    scanf(" %c",&letra);
    repetiuLet(letUsadas,l,letra,&usou,ga,pe);
    if(!usou)
    {
      pontuacao(tam,palSort,palOcult,cont,letra,&pts,&chances);
    }
    l=l+1;
    novoJogo(&pts,&chances,&cont,tam,&palAcert,&ga,&pe,&l);
  }
  system("cls");
  printf("\033[11;15HO jogo acabou, você acertou %d das %d palavras.",palAcert,n);
  return (0);
}

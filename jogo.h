int sorteio(int numSort[], int i);
void esconderpal(char palOcult[][20],char palSort[][20],int i,int tam[]);
int pontuacao(int tam[], char palSort[][20], char palOcult[][20],int cont,char letra,int *pts,int *chances);
int novoJogo(int *pts,int *chances,int *cont,int tam[],int *pal, int *g,int *p,int *l);
int texto(int cont,int chances,char palOcult[][20],char palSort[][20],char letra,int usou,int n,int g,int p);
int repetiuLet(char letUsadas[30],int l,int letra,int *usou,int gan,int per);

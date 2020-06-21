#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORDLEN 256


/*int counter()
{
    FILE *file;
    if(file=fopen())

    while(fscanf(file,"%255s",word)>0) {
    nChars+=strlen(word);
    nWords++;
}
}*/
int SortFileWords(const char* inFileName, const char* outFileName)
{
  char word[MAXWORDLEN];
  int nChars=0;
  int nWords=0;
  char* pTextData;
  char** ppWords;
  int temp;
 

  
  //otwieranie pliku
  FILE *infile;
  if((infile=fopen(inFileName,"r"))==NULL)
    {
      printf("Blad");
      return 0;
    }
  //liczenie
    /* while(fscanf(infile,"%255s",word)>0) { */
    /* nChars+=strlen(word); */
    /* nWords++; */
    /* } */
    /* nChars+=8; // what the fuck? */

  //liczenie na prawde
  char ch;
  while ((ch = fgetc(infile)) != EOF)
    {
      nChars++;
      /* Check words */
      if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
	nWords++;
    }
  



    
    
    printf ("Wyrazy %d\n",nWords);
    printf ("Znaki %d\n",nChars);
    //alokacja
    pTextData=(char*)malloc((nChars+nWords)*sizeof(char));
    ppWords=(char**)calloc(nWords,sizeof(char*));
    //uzupe³nianie
    fclose(infile);
    infile=fopen(inFileName,"rt");
    for(int i=0;i<nChars+nWords;i++)
    {
        pTextData[i]=fgetc(infile);
        pTextData[i]=tolower(pTextData[i]);
        if(pTextData[i]==' '||pTextData[i]=='\n'||pTextData[i]=='\t')
        {
            pTextData[i]='\0';
        }
        printf ("%c",pTextData[i]);
    }
    //dodawania wskaŸników na s³owa
    ppWords[0]=&pTextData[0]; //przekazywales chary zamiast wzkaznikow
    printf ("%c",ppWords[0]);
    int a=1;
    for(int i=1;i<nChars+nWords-1;i++)
    {
        if(pTextData[i]=='\0')
        {
            ppWords[a]=&pTextData[i+1];
            printf ("%c",ppWords[a]);
            a++;
        }
    }

    //sortowanie wsyep
    //sortowanie

    char * temp2;

    /* for(int i=0;i<nWords;i++) */
    /*   { */
    /* 	printf("%p\n",ppWords[i]); */
    /*   } */

    printf("\n"); 
   for(int i = 0; i<nWords; i++)
      {
	printf("%p ", ppWords[i]);
	printf("%s\n", ppWords[i]);
      }
    printf("\n");
    //sortowanie
    for(int i=0;i<nWords;i++)
    {
      int k=i;
      temp2=ppWords[i];
      
      for(int n=i+1; n<nWords; n++)
	{
	  if(strcmp(ppWords[n],temp2)<0)
	    {
	      k=n;
	      temp2=ppWords[n];
	    }
	}
      ppWords[k]=ppWords[i];
      ppWords[i]=temp2;
    }

    //zapisywanie do pliku
    fclose(infile);
    FILE* outfile;
    outfile=fopen(outFileName,"w");

    for(int i = 0; i<nWords; i++)
      {
	/* fprintf("%p ", ppWords[i]); */
	fprintf(outfile,"%s\n", ppWords[i]);
      }
    printf("\n");

    printf("%s",pTextData);

}
int main()
{
    SortFileWords("dane.txt","sorted.txt");
    return 0;
}

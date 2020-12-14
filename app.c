#include <stdio.h>
#include <stdlib.h>
int main()
{
  int menu;
  FILE *fp;
  char broj[5];
  int uslov;
  int uslov2;
  while(3)
    {
      printf("1. Upisi u FIFO bafer\n");
      printf("2. Procitaj iz FIFO bafera\n");
      printf("3. Izadji\n");
      scanf("%d", &menu);

      switch(menu)
	{
	case 1:
	  {
	    uslov = 2;
	    uslov2 = 2;
	  printf("Upis:\n");
	  fp = fopen("/dev/fifo","w");

	  if(fp == NULL){
	    printf("Problem pri otvaranju /dev/fifo\n");
	    return -1;
	  }
	  while(uslov2)
	    {
	      printf("Uneti broj: ");
	      scanf("%s", broj);
	      if(uslov)
		{
		  fprintf(fp,"0x%s", broj);
		  uslov = 0;

		}
	      else
		{
		  if(broj[0] == 'Q')
		    uslov2 = 0;
		  else
		    fprintf(fp,";0x%s", broj);
		}
	    }
	  fputs("\n", fp);
	  if(fclose(fp))
	    {
	      printf("Greska pri zatvaranju datoteke\n");
	      return -1;
	    }
	    break;
	  }
	case 2:
	  {
	    char *vrednost;
	    size_t br_bita = 5;
	    fp = fopen("/dev/fifo" , "r");
	    if(fp == NULL) {
	      puts("Problem pri otvaranju /dev/fifo");
	      return -1;
	    }
	    vrednost = (char *) malloc(br_bita);
	    getline(&vrednost, &br_bita, fp);
	    printf("Ispis: %s\n", vrednost);
	    free(vrednost);

	    if(fclose(fp)){
	      puts("Problem pri zatvaranju /dev/fifo");
	      return -1;
	    }
	    break;
	  }
	case 3:
	  {
	  printf("Aj cao\n");
	  return 0;
	  break;
	  }
	}
    }
  return 0;
}

      
    
    

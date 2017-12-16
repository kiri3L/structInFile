#include <stdio.h>
#include <stdlib.h>
/*#include  <io.h>*/

struct IntFloatString
{
	int i;
	float f;
	char s[256];
}IFS;

int main(int argc,char *argv[])
{
	if (2 > argc) 
	{
		printf("Error, no file name.");
		exit(1);
	}
	FILE *fp;
    if ((fp = fopen(argv[1],"rb")) == NULL)
	{ 
	  printf("Error, file was not opened.");
      exit(2);	  
    }
	while(feof(fp) == 0)
	{
	/*	fread(&d, sizeof(int), 1,fp);
		fread(&f, sizeof(float), 1,fp);
		fread(&s, sizeof(char)*256, 1,fp);*/
		fread(&IFS, sizeof(struct IntFloatString), 1,fp);
	/*	printf("\n\t int = %d\n\t float = %f\n\t char[256] = %s\n",d,f,s);*/
	    printf("\n\t int = %d\n\t float = %f\n\t char[256] = %s\n",IFS.i,IFS.f,IFS.s);
	
	}
	fclose(fp);
	return 0;
}

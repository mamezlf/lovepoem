#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int FindSongNum(FILE *fp)
{
  int c;
  int line = 0;
  fp = fopen("input.txt", "r");
  char buf[SIZE];
  if ((fp = fopen("input.txt", "r")) == NULL)
  {
    printf("failed to open the txt file fp.\n");
    return -1;
  }

  while (fgets(buf, SIZE, fp) != NULL)
  {
    line++;
  }

  fclose(fp);
  printf("\nSongNum=%d\n", line);
  return line;
}

int main(void)
{
  int i;

  FILE *in;
  in = fopen("input.txt", "r");
  if (in == NULL)
  {
    printf("cannot open file input\n");
    exit(1);
  }

  FILE *out;
  out = fopen("output.txt", "w");
  if (out == NULL)
  {
    printf("cannot open file output\n");
    exit(1);
  }

  FILE *fp;
  int num;
  num=FindSongNum(fp);

  char buf[256];
  for ( i = 0; i < num&&fgets(buf, sizeof(buf), in); i++)
  {
    fprintf(out,"<li>%s</li>\n",buf);
  }
  
  fclose(in);
  fclose(out);
  
  return 0;
}
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
  num = FindSongNum(fp);

  char href[SIZE];
  int date;

  char iframe[SIZE];

  printf("youtube link: ");
  scanf("%s", href);
  printf("date: ");
  scanf("%d", &date);
  fprintf(out, "\n<div class=\"prefix\" id=\"%d\">", date);
  fprintf(out, "<h4> <a href=\"%s\" title= \"RPD%d\" target= \"_blank\">\n", href, date);

  // printf("iframe: ");
  // fflush(stdin);
  // scanf("%[^\n]", &iframe);

  fprintf(out,"<!--title here--></a></h4>\n");
  // fprintf(out,"<!--title here--></a></h4>\n%s", iframe);

  int datetmp;
  datetmp=date;

  int y, m, d;
  d = datetmp % 100;
  datetmp /= 100;
  m = datetmp % 100;
  y = datetmp / 100;
  fprintf(out, "<time datetime=\"20%02d-%02d-%02d\"></time>\n</div>\n", y, m, d);

  fprintf(out, "\n<ul style=\"list-style: none\"class=\"tslist\" id=\"RPD%d\">",date);

  char buf[256];
  for (i = 0; i < num && fgets(buf, sizeof(buf), in); i++)
  {
    fprintf(out, "<li>%s</li>\n", buf);
  }

  fprintf(out, "<br />\n</ul>\n<br />\n<!-- RPD%d -->\n",date);

  fclose(in);
  fclose(out);

  return 0;
}
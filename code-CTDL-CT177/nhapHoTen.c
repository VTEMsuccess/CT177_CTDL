#include <stdio.h>
#include <string.h>

void tachten(char s[], char ten[], char lot[]) {
  int i, j, n;
  n = strlen(s);
  for (i = n - 1; i > 0; i--)
    if (s[i] == ' ')
      break;
  for (j = 0; j < i; j++)
    lot[j] = s[j];
    lot[i] = '\0';
  for (j = i + 1; j < n; j++)
    ten[j - i - 1] = s[j];
  ten[n - i - 1] = '\0';
}
void main(void) {
  char s[30], ten[20], lot[20];
  printf(" nhap ho va ten \n");
  gets(s);
  tachten(s, ten, lot);
  printf(" \n ho va chu lot: \n");
  puts(lot);
  printf(" ten: \n");
  puts(ten);
  getch();
}

/*
int main(){
	char c[20];
	printf("moi ban nhap vao ho & ten: ");
	gets(c);
	puts(c);
	return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE* input = fopen("./Files/input.txt","r");
  FILE* output = fopen("./Files/output.txt","w");
  
  int c;
  c= fgetc(input);
  while(c!=EOF){
    fputc(c,output);
    c=fgetc(input);
  }
  printf("%d\n", c);

  fclose(input);
  fclose(output);
}

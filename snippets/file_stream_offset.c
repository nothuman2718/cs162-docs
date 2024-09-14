#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE* input = fopen("./Files/input.txt", "r");
  FILE* output = fopen("./Files/output.txt", "w");

  // Check if the files were successfully opened
  if (input == NULL || output == NULL) {
    perror("Error opening file");
    return 1;
  }

  char buffer[BUFFER_SIZE];
  size_t length;

  // fread should be used like this: fread(buffer, sizeof(char), BUFFER_SIZE, input)
  length = fread(buffer, sizeof(char), BUFFER_SIZE, input);
  while (length > 0) {
    // fwrite should be used like this: fwrite(buffer, sizeof(char), length, output)
    fwrite(buffer, sizeof(char), length, output);
    length = fread(buffer, sizeof(char), BUFFER_SIZE, input);
  }

  printf("%zu\n", length);  // %zu for size_t

  fclose(input);
  fclose(output);

  return 0;
}


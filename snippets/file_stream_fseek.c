#include <stdio.h>

int main() {
    FILE *file = fopen("./Files/input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Move 5 bytes before the end of the file
    fseek(file, -5, SEEK_END);

    // Read one character from this new position
    char ch = fgetc(file);
    printf("Character 5 bytes before end: %c\n", ch);

    fclose(file);
    return 0;
}

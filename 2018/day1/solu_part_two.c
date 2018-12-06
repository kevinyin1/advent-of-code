#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("inputPartTwo.txt", "r");
  int frequency = 0;
  int index = 1;
  int *data = malloc(sizeof(int));
  data[index - 1] = frequency;
  while(1) {
    if (feof(file)) {
      fseek(file, 0, SEEK_SET); 
    }
    char sign = '\0';
    int num = 0;
    if (fscanf(file, "%c%d\n", &sign, &num) < 2) {
      fclose(file);
      file = NULL;
      if (data != NULL) {
        free(data);
      }
    }
    if (sign == '-') {
      frequency -= num;
    }
    else {
      frequency += num;
    }
    for (int i = 0; i < index; i++) {
      if (data[i] == frequency) {
        printf("%d\n", frequency);
        fclose(file);
        file = NULL;
        free(data);
        return -1;
      }
    }
    data = realloc(data, sizeof(int) * (++index));
    data[index - 1] = frequency;
  }
}

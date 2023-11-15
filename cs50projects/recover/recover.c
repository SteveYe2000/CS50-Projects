#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define block 512

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *file = argv[1];
    FILE *raw_file = fopen(file, "r");
    if (raw_file == NULL) {
        printf("Unable to open %s\n", file);
        return 1;
    }

    bool found = false;
    int counter = 0;
    uint8_t buffer[block];
    char name[8];
    FILE *ptr = NULL;

    while (fread(buffer, block, 1, raw_file) == 1) {
        if ( buffer[0] == 0xff &&
             buffer[1] == 0xd8 &&
             buffer[2] == 0xff &&
           ( buffer[3] & 0xf0) == 0xe0 ) {

            if (found) {
                fclose(ptr);
            }
            else {
                found = true;
            }

        sprintf(name, "%03d.jpg", counter);
        ptr = fopen(name, "w");
        if (ptr == NULL) {
            fclose(raw_file);
            printf("Unable to create %s\n", name);
            return 2;
        }
        counter += 1;
        }

    if(found) {
        fwrite(buffer, block, 1, ptr);
    }
    }

    fclose(raw_file);
    if (found) {
        fclose(ptr);
    }
    return 0;
}

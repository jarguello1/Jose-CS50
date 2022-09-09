#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//todo
// Open memory card
// Look for beginning of a JPEG
// Open a new JPEG file
// Write 512 bytes until a new jpeg is found

typedef uint8_t BYTE;

//number of bytes in a memory block
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    else
    {
        //open card.raw
        FILE *card = fopen(argv[1], "r");

        if (card == NULL)
        {
            printf("Error: cannot open %s\n", argv[1]);
            return 2;
        }


        BYTE bytes[512];
        int counter = 0;
        FILE *jpeg_pointer = NULL;
        char filename[8];

        while (fread(bytes, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
        {
            // Read first four bytes to make sure its a JPEG
            if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
            {
                if (counter != 0)
                {
                    fclose(jpeg_pointer);
                }

                //create and name jpeg file
                sprintf(filename, "%03i.jpg", counter);
                jpeg_pointer = fopen(filename, "w");
                counter++;
            }

            if (counter != 0)
            {
                fwrite(&bytes, 1, BLOCK_SIZE, jpeg_pointer);
            }
        }

        fclose(card);
        fclose(jpeg_pointer);
        return 0;
    }
}

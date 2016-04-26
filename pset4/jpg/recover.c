/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdint.h>
 
//counter of our output JPGs
int output_jpg_count = 0;

char title[8];
FILE* outptr = NULL;

int main(int argc, char* argv[])
{
    // Open memory card file
    char* infile = "card.raw";
    FILE* inptr = fopen(infile, "r");
    
    //Check that file is good
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
    
    //create a buffer to hold each block 
    uint8_t buffer[&length];
    
    //keep read blocks while there are blocks to read
    while (fread(buffer, sizeof(uint8_t), 512, inptr))
    {
        // Check if we've found the start of JPG
        if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]==0xe0 || buffer[3]==0xe1))
        {
            // Check if a file was already open; if so close before opening a new one
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            
            sprintf(title, "%.3d.jpg", output_jpg_count);
            output_jpg_count++;
            
            outptr = fopen(title, "a");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", title);
                return 3;
            }
        }
        
        // Check to see if outptr if null. If it is we've not yet found a valid start to a JPG in raw file, so we should skip
        if (outptr != NULL)
        {
            fwrite(buffer,512,1,outptr);
        }
    }
    
    fclose(inptr);
    fclose(outptr);

    return 0;
}

/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy increase factor original file new larger file\n");
        return 1;
    }
    
    int increase_factor = atoi(argv[1]);
    if (increase_factor<1 || increase_factor>100)
    {
        printf("Valid range for resize is 1 to 100 only.\n");
        return 1;
    }
    
    

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf_org;
    fread(&bf_org, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi_org;
    fread(&bi_org, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf_org.bfType != 0x4d42 || bf_org.bfOffBits != 54 || bi_org.biSize != 40 || 
        bi_org.biBitCount != 24 || bi_org.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //Create BITMAPHEADER for new file
    BITMAPFILEHEADER bf_new;
    //Create BITMAPHINFO for new file
    BITMAPINFOHEADER bi_new;  
    
    //Set output file file header to be same as input file
    bf_new = bf_org;
    //Set output file info header to be same as input file
    bi_new = bi_org;

    // Calculate new width
    bi_new.biWidth = bi_org.biWidth * increase_factor;
    // Calculate new height
    bi_new.biHeight = -(abs(bi_org.biHeight) * increase_factor);
    
    // determine padding for scanlines
    int padding_org =  (4 - (bi_org.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_new =  (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;    
    
    
    // Set output file image sizes
    bi_new.biSizeImage = ((bi_new.biWidth * sizeof(RGBTRIPLE))+padding_new) * abs(bi_new.biHeight);
    bf_new.bfSize =  bi_new.biSizeImage+54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi_org.biHeight); i < biHeight; i++)
    {
    
        //write increase_factor number rows per original row
        for (int rows = 0; rows < increase_factor; rows++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi_org.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int k = 0; k < (increase_factor); k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            
            }
            
            if (rows<(increase_factor-1))
            {
                fseek(inptr, -bi_org.biWidth*sizeof(RGBTRIPLE), SEEK_CUR);
            }
            else
            {
                fseek(inptr, padding_org, SEEK_CUR);
            }
            
            
            //Add padding if needed for new file
            for (int l = 0; l < padding_new; l++)
            {
                fputc(0x00, outptr);
            }
            
        
        } 

    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
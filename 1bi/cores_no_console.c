#include <stdio.h>

int imagem[10][10] = {
    {0xFF0000FF, 0xE61919FF, 0xCC3333FF, 0xB34C4CFF, 0x996666FF, 0x808080FF, 0x669999FF, 0x4CB3B3FF, 0x33CCCCFF, 0x19E6E6FF},
    {0xFF1900FF, 0xE63319FF, 0xCC4C33FF, 0xB3664CFF, 0x998066FF, 0x809980FF, 0x66B399FF, 0x4CCCB3FF, 0x33E6CCFF, 0x19FFE6FF},
    {0xFF3300FF, 0xE64C19FF, 0xCC6633FF, 0xB3804CFF, 0x999966FF, 0x80B380FF, 0x66CC99FF, 0x4CE6B3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF4C00FF, 0xE66619FF, 0xCC8033FF, 0xB3994CFF, 0x99B366FF, 0x80CC80FF, 0x66E699FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF6600FF, 0xE68019FF, 0xCC9933FF, 0xB3B34CFF, 0x99CC66FF, 0x80E680FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF8000FF, 0xE69919FF, 0xCCB333FF, 0xB3CC4CFF, 0x99E666FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF9900FF, 0xE6B319FF, 0xCCCC33FF, 0xB3E64CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFB300FF, 0xE6CC19FF, 0xCCE633FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFCC00FF, 0xE6E619FF, 0xCCFF33FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFE600FF, 0xE6FF19FF, 0xCCFF33FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF}
};

typedef struct canais Canais;
typedef union pixel Pixel;

struct canais {
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        unsigned char r, g, b, a;
    #else // Little-endian
        unsigned char a, b, g, r;
    #endif  
};
//  a  b  g  r -> Big Endian
//  r  b  g  a -> Little Endian
// [ ][ ][ ][ ] -> Inteiro
//  3  2  1  0
union pixel {
    int cor;
    Canais canais;
};


void limpar_tela() {
    printf("\033[2J"); // Limpa a tela
    printf("\033[H");  // Move cursor para a posição inicial
}
void desenha_pixel_em_xy(int x, int y, Pixel *pixel) {
    // Move cursor para (x, y)
    printf("\033[%d;%dH", y + 1, x * 2 + 1); 
    // Define a cor de fundo com os valores de cor RGB.
    printf("\033[48;2;%d;%d;%dm  \033[0;00m",
    pixel->canais.r, pixel->canais.g, pixel->canais.b);
}


int main()
{
    Pixel pixels[3][3] = {
        {{.cor = 0x0000FFFF}, {.cor = 0x0000FFFF}, {.cor = 0x0000FFFF}},
        {{.cor = 0x0000FFFF}, {.cor = 0xFF0000FF}, {.cor = 0x0000FFFF}},
        {{.cor = 0x0000FFFF}, {.cor = 0x0000FFFF}, {.cor = 0x0000FFFF}}
    };
    // LINHA 10
    desenha_pixel_em_xy(10,10, &pixels[0][0]);
    desenha_pixel_em_xy(11,10, &pixels[0][1]);
    desenha_pixel_em_xy(12,10, &pixels[0][2]);
    
     // LINHA 11
    desenha_pixel_em_xy(10,11, &pixels[1][0]);
    desenha_pixel_em_xy(11,11, &pixels[1][1]);
    desenha_pixel_em_xy(12,11, &pixels[1][2]);
    
     // LINHA 12
    desenha_pixel_em_xy(10,12, &pixels[2][0]);
    desenha_pixel_em_xy(11,12, &pixels[2][1]);
    desenha_pixel_em_xy(12,12, &pixels[2][2]);
    
    

    return 0;
}
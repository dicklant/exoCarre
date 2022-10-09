#include <stdio.h>

void printRectangle(int l, int h, char c)
{
    for (int ligne = 0; ligne < l; ligne++)
    {
        for (int colonne = 0; colonne < h; colonne++)
            if (ligne == 0 || ligne == l - 1 || colonne == 0 || colonne == h - 1)
                putchar(c);
            else
                putchar(' ');

        putchar('\n');
    }
}

void printspaces(int nbSpaces) {
    for(int i = 0; i<nbSpaces; i++)
        putchar('.');
}

void printStars(int nbStars) {
    for (int i = 0; i < nbStars; i++)
        putchar('*');
}

void star(unsigned int size) {
    int space = size == 1 ? 1 : 2 * (size - 1) - 1;
    int max_barre = 2*size + 1; 
    int max_colonne = max_barre * 2 + space;

    // impression du haut
    for(int h=0; h<size; h++) {
        printspaces(max_colonne/2-h);
        if(h==0) printStars(1);
        else
        {
            printStars(1);
            printspaces(2*(h)-1);
            printStars(1);
        }
        putchar('\n');
    }

    // impression trait haut
    printStars(max_barre);
    printspaces(space);
    printStars(max_barre);
    putchar('\n');

    // impression du V horizontal Haut
    for(int ligne=1; ligne<size; ligne++) {
        printspaces(ligne);
        printStars(1);
        printspaces(max_colonne - ((ligne*2)+2));
        printStars(1);
        putchar('\n');
    }

    // impression trait milieu
    printspaces(size);
    printStars(1);
    printspaces(max_colonne -(size*2 + 2));
    printStars(1);
    putchar('\n');

    // impression du V horizontal bas
    for (int ligne = size-1; ligne >0; ligne--)
    {
        printspaces(ligne);
        printStars(1);
        printspaces(max_colonne - ((ligne * 2) + 2));
        printStars(1);
        putchar('\n');
    }

    // impression trait bas
    printStars(max_barre);
    printspaces(space);
    printStars(max_barre);
    putchar('\n');

    // impression du bas
    for (int h = size-1; h >=0; h--)
    {
        printspaces(max_colonne / 2 - h);
        if (h == 0)
            printStars(1);
        else
        {
            printStars(1);
            printspaces(2 * (h)-1);
            printStars(1);
        }
        putchar('\n');
    }
}



int main()
{
    //printRectangle(10, 6, '*');

    star(8);
}
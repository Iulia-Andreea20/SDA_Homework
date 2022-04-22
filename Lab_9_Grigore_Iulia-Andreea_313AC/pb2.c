 #include<stdio.h>

void hanoi(int disks, char source, char dest, char aux)
{
    if (disks == 1) 
        printf("Muta discul 1 de pe tija %c, pe tija %c\n", source, dest);
    else
    {
        hanoi(disks-1 , source, aux, dest);
        printf("Muta discul %d de pe tija %c, pe tija %c\n",disks , source, dest);
        hanoi(disks-1, aux, dest, source);
    }

}
int main ()
{
    char source = 'A',dest = 'B',aux = 'C';
    int disks = 4;
    
    hanoi(disks, source, dest, aux);


    return 0;
}
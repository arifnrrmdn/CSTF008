#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define ulpj 10000 //konstanta (upah lembur per jam)
//deklarasi fungsi
void input_data_karyawan(void);
float upah_perjam(void);
float upah_perminggu(void);
//deklarasi variabel
char nama[15],gol;
int jumlah_jam_kerja;

main()
{
    system("cls");
    puts("program upah mingguan karyawan PT.MAKMUR");
    puts("----------------------------------------");
    input_data_karyawan();

    //tampilkan upah mingguan karyawan 
    printf("Upah mingguan atas nama %s sebesar Rp %.2f",nama,upah_perminggu());
    getch();
    return 0;
}

//definisi fungsi
void input_data_karyawan(void){
    printf("nama karyawan       = "); gets(nama);
    printf("golongan            = "); gol=getche();
    printf("\nJumlah jam kerja  = "); scanf("%d",&jumlah_jam_kerja);
}

float upah_perjam(void){
    float upah_perjam;
    switch(toupper(gol)){
        case 'A': upah_perjam=20000; break;
        case 'B': upah_perjam=30000; break;
        case 'C': upah_perjam=40000; break;
        case 'D': upah_perjam=50000; break;
    }
    return(upah_perjam);
}

float upah_perminggu(void){
    if(jumlah_jam_kerja>48){
        return(48*upah_perjam() + (jumlah_jam_kerja-40)*ulpj);
    }else{
        return(jumlah_jam_kerja*upah_perjam());
    }
}

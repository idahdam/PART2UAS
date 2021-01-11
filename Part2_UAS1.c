/*
	Muhammad Hadi - 1906355623
	Part 2 bagian 1 - Array bentuk float
	Saya menangkap sebanyak-banyaknya itu tinggal diganti defined variablenya, pak 
*/
#define MAX_ORANG 1000
#define PANJANG_STRING 1000

#include <stdio.h>
#include <string.h>

int main(){
	
	char namaSiswa[MAX_ORANG][PANJANG_STRING], tempString[PANJANG_STRING];
	float maxNilaiSiswa[MAX_ORANG], sortingNilai[MAX_ORANG], sum, temp;
	int maxSiswa[MAX_ORANG];
	int jumlah, i, j;
	
	printf("Program akan menghitung nilai rata-rata max %d siswa\n", MAX_ORANG);
	printf("input berapa jumlah siswa: "), scanf("%d", &jumlah);
	
	//error input
	while(jumlah < 1 || jumlah > MAX_ORANG){
		printf("input di luar range, input kembali jumlah siswa: "), scanf("%d", &jumlah);
	}
	
	printf("Anda memasukkan %d jumlah siswa untuk dihitung nilainya.\n\n", jumlah);
	
	//input and count sum
	for(i = 0; i<jumlah; i++){
		printf("Masukkan nama untuk siswa ke-%d: ", i+1), scanf("%s", namaSiswa[i]);
		printf("Untuk nilai siswa ke-%d adalah: ", i+1), scanf("%f", &maxNilaiSiswa[i]);
		sum += maxNilaiSiswa[i];
	}
	
	//average
	sum /= jumlah;
	
	//sorting
	for(i = 0; i<jumlah-1; i++){
		for(j = 0; j<jumlah-1-i; j++){
			if(maxNilaiSiswa[j] > maxNilaiSiswa[j+1]){
				temp = maxNilaiSiswa[j+1];
				maxNilaiSiswa[j+1] = maxNilaiSiswa[j];
				maxNilaiSiswa[j] = temp;
				
				strcpy(tempString, namaSiswa[j+1]);
				strcpy(namaSiswa[j+1], namaSiswa[j]);
				strcpy(namaSiswa[j], tempString);
			}
		}
	}
	
	//print sorting and average
	
	printf("\nSkor dari terendah ke tertinggi...\n");
	for(i = 0; i<jumlah; i++){
		printf("%s - %.2f\n", namaSiswa[i], maxNilaiSiswa[i]);
	}
	printf("\nRata-rata dari nilai %d siswa pada kuis kali ini adalah %.2f\n", jumlah, sum);
	
	return 0;
}

#define MBE 16
#define TBUFSIZ (1024*1024*MBE) // MBE megabyte di dati
#define BLK 5 //numero di volte di riprova per il test per un risultato più accurato
#define NFILE "test.bin"
#define NSTOS 1000000000 //numero per convertire da nanosecondi a secondi
#define BYTOMB (TBUFSIZ/MBE) //numero per convertire da byte a megabyte
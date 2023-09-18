void basic(){

    consoleClear();

    printf("\n\nATTENDERE: Benchmark in corso...");

    consoleUpdate(NULL);

    char *buffer = (char*) calloc(TBUFSIZ, sizeof(char));
    tempo scrittura, lettura;

    //region Scrittura
    scrittura.inizio = armGetSystemTick();
    for (int i = 0; i < BLK; ++i) { //scrivo in memoria BLK volte
        FILE *testfile=fopen(NFILE, "wb");
        fflush(testfile);
        fwrite(buffer, TBUFSIZ, 1, testfile);
        fclose(testfile);
    }
    scrittura.fine = armGetSystemTick();
    //endregion

    //region Lettura
    lettura.inizio = armGetSystemTick();
    for (int i = 0; i < BLK; ++i) {
        FILE *testfile=fopen(NFILE, "rb");
        fflush(testfile);
        fread(buffer, TBUFSIZ, 1, testfile);
        fclose(testfile);
    }
    lettura.fine = armGetSystemTick();
    //endregion

    free(buffer);

    double tscrittura = TBUFSIZ*BLK/armTicksToS(scrittura)/BYTOMB;
    double tlettura = TBUFSIZ*BLK/armTicksToS(lettura)/BYTOMB;
    double tempo = armTicksToS(scrittura);

    if(remove(NFILE)!=0)
        printf("\n\nERRORE: Impossibile eliminare il file di test!");

    printf("\n\n\tScrittura: %.2fMB/s\n\n\tLettura: %.2fMB/s\n\n\tTempo: %.2f secondi", tscrittura, tlettura, tempo);
    printf("\n\nPremi [B] per tornare al menu' principale");

    tornaIndietro('m');

}
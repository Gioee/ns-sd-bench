double armTicksToS(tempo risultato){
    return (double) armTicksToNs(risultato.fine-risultato.inizio)/NSTOS;
}
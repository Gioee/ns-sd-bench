void tornaIndietro(char d){
    while(appletMainLoop()){
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if(kDown == KEY_B){
            switch(d){
                case 'm':
                    menu();
                    break;
                default:
                    break;
            }
            break;
        }

        consoleUpdate(NULL);
    }
}

void menu(){

    consoleClear();

    printf(
            "\n\n\n\t[A] TEST R/W MEMORIA"
            "\n\t[B] ESCI"
            "\n\nPremi un pulsante per continuare.."
    );

    while(appletMainLoop()){
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if(kDown & KEY_A){
            basic();
            break;
        }

        if(kDown == KEY_B)
            break;

        consoleUpdate(NULL);
    }
}
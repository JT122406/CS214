


int main(int argc, char *argv[]){
    int numeric = 0;
    if((argc < 2) || (*argv[1] == '\0')){  //If a command line input is there 
        char* search = argv[1]; //The string to search for and if we are case sensetive
        if (argv[1][0] == '-'  && argv[1][1] == 'n')
            numeric = 1;   
    }

}
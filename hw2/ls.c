#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

char* month(int monthnum) {
    switch (monthnum) {
        case 1:
            return "Jan";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Apr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Aug";
        case 9:
            return "Sep";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dec";
    }
}


int main(int argc, char *argv[]){
    int info;
    if((argc < 2) || (*argv[1] == '\0')){  //Makes sure there is a string to search for
        info = 0;
    } else if (argv[1][0] == '-'  && argv[1][1] == 'l')
    {
        info= 1;
    }
    else
        return 0;


    struct dirent *de;
    DIR *dr = opendir(".");

    //Prints file names
        while ((de = readdir(dr)) != NULL)
        {
            if (de->d_type == DT_REG)
                {
                    struct tm dt;
                    if (info == 1)  //print file info before file name
                    {
                        struct stat buf;
                        stat(de->d_name, &buf);
                        //printf("%u ", buf.st_mode);
                        //printf("%u ", buf.st_uid);
                        //printf("%ld ", buf.st_mtime);
                        printf("%ld ", buf.st_size);
                        //Time info
                        dt = *(gmtime(&buf.st_mtime));

                        printf(" %s %d %d:%d ", month(dt.tm_mon), dt.tm_mday,  dt.tm_hour, dt.tm_min);
                    }
                    printf("%s\n", de->d_name);
                }
        }
            
  
    closedir(dr);    
    return 0;
}
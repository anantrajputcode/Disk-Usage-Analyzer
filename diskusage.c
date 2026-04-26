#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#define _XOPEN_SOURCE 500


typedef struct{
    const char* path;
    size_t size;
} FileEntry;

FileEntry* files;

size_t current_ind;

void init_files(){
    files = (FileEntry* ) calloc(10, sizeof(FileEntry));
    if(files == NULL){
        perror("Files array cannot be allocated.\n");
        exit(-1);
    }
}

int function(const char* path, const struct stat* sb, int typeflag, struct FTW* ftwbuf){
    size_t filesize = sb-> st_size;
    printf("%ld\t%s\n", filesize, path);
    return 0;
}
int main()
{
    printf("Your disk usage is: \n");
    init_files();
    nftw(".", function, 5, 0);
    return 0;
}

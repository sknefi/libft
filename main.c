#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line_bonus.h"

int main(void)
{
    int     fd;
    char    *line;

    printf("starting\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (EXIT_FAILURE);
    }

    // Read and print each line from the file
    while ((line = get_next_line_bonus(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Close the file
    close(fd);
    printf("ending\n");
    return (EXIT_SUCCESS);
}

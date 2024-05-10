#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"

int main(int argc, char *argv[])
{
    sensor *data = NULL;
    char *path = NULL;
    uint32_t len;
    int32_t rez = 0;
    uint8_t m_num = 0;
    // opterr=0;
    while ((rez = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (rez)
        {
        case 'h':
            printf("Usage: .../temp_stat.exe [-f][FILE]\
                    \nor: .../temp_stat.exe [-f][FILE] [-m][MONTH NUMBER]\
                    \nOutput statistics for the entered month or year\n\
                    \nOptions:\
                    \n-h\tThis help text\
                    \n-f\tSpecify folder\
                    \n-m\tSpecify the month number\n");
            printf("Example: %s -f .\\tmp.csv -m 7 \n", argv[0]);
            return 0;
        case 'f':
            //            printf("\nFile path is \"f = %s\".\n", optarg);
            path = optarg;
            break;
        case 'm':
            m_num = (uint8_t)atoi(optarg);
            if ((m_num < 1) || (m_num > 12))
            {
                printf("\nIncorrect month number has been entered. Exit...\n");
                return 1;
            }
            break;
        case '?':
            printf("Unknown argument: %s Try -h for help\n", argv[optind - 1]);
            return 1;
        };
    };
    len = file_read(path, &data);
    if (m_num)
    {
        stat_print_month(m_num, len, data);
        return 0;
    }
    stat_print_year(len, data);
    free(data);
    return 0;
}

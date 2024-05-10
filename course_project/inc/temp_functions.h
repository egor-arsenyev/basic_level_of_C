#include <stdint.h>
#define SIZE 30
#define N 6
#define MIN_TEMP -99
#define MAX_TEMP 99

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
} sensor;

typedef struct
{
    uint16_t y;
    uint8_t m;
    uint32_t rec_num;
    double t_avg;
    int8_t t_min;
    int8_t t_max;
} stat;
#define STAT_DEFAULT       \
    {                      \
        .y = 0,            \
        .m = 0,            \
        .rec_num = 0,      \
        .t_avg = 0,        \
        .t_min = MAX_TEMP, \
        .t_max = MIN_TEMP  \
    }

int file_read(char *file_name, sensor **data);
void file_print(FILE *fp);
int file_size(FILE *fp);
int data_print(int num, sensor *data);
void data_cgangeIJ(sensor *data, int i, int j);
void data_sort_t(sensor *data, int n);
void data_sort_date(sensor *data, int n);
void AddRecord(sensor *data, int number,
               uint16_t year, uint8_t month, uint8_t day,
               uint8_t hour, uint8_t minute, int8_t t);
void accum(stat *per, sensor *data);
double calc_avg(stat *per);
int data_check(sensor *data);
void get_month_stat(int month_num, int len, sensor *data);
void get_year_stat(int len, sensor *data);
void stat_print_month(int month_num, int len, sensor *data);
void stat_print_year(int len, sensor *data);
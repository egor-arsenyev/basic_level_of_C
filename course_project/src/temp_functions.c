#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "temp_functions.h"

int file_read(char *file_name, sensor **pdata)
{
    printf("Openig a file...\n");
    FILE *fp;
    sensor *data;
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("ERROR: no such file or directory. Exit...\n");
        exit(1);
    }

    int64_t fsize = file_size(fp);

    int line_cnt = 1;
    while (!feof(fp))
    {
        if (fgetc(fp) == '\n')
            line_cnt++;
    }
    rewind(fp);

    printf("File size = %lld byte\nNumber of lines = %d\n", fsize, line_cnt);

    *pdata = (sensor *)calloc((size_t)line_cnt, sizeof(sensor));
    data = *pdata;
    if (NULL == data)
    {
        printf("ERROR: memory allocation failure. Exit...\n");
        exit(1);
    }
    int r = 0;
    int i = 0;
    int err_cnt = 0;
    while ((r = fscanf(fp, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                       &data[i].year,
                       &data[i].month,
                       &data[i].day,
                       &data[i].hour,
                       &data[i].minute,
                       &data[i].t)) > 0)
    {
        //        data[i].error = 0;
        if (r < N)
        {
            err_cnt++;
            char s[20];
            r = fscanf(fp, "%[^\n]", s);
            printf("WARNING: incorrect data format in the line %d:\n %s\n", i, s);
        }
        else if (data_check(&data[i]))
        {
            err_cnt++;
            printf(" %d: check the data\n", (i + err_cnt));
            printf("%6hu;%6hhu;%6hhu;%6hhu;%6hhu;%6hhd;\n",
                   data[i].year, data[i].month, data[i].day, data[i].hour,
                   data[i].minute, data[i].t);
        }
        else
            i++;
    }
    printf("\nFile read completed.\nLines read: %d;\
    \nNumber of lines with errors: %d\n\n",
           (i + err_cnt), err_cnt);
    fclose(fp);
    return i;
}

void file_print(FILE *fp)
{
    int c = fgetc(fp);
    while (c != EOF)
    {
        putc(c, stdout);
        c = fgetc(fp);
    }
}

int file_size(FILE *fp)
{
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, prev, SEEK_SET);
    return sz;
}

int data_print(int num, sensor *data)
{
    for (int i = 0; i < num; i++)
    {
        printf("%6hu;%6hhu;%6hhu;%6hhu;%6hhu;%6hhd\n",
               data[i].year, data[i].month, data[i].day, data[i].hour,
               data[i].minute, data[i].t);
    }
    return 0;
}

int data_check(sensor *data)
{
    if ((data->year < 1722) || (data->year > 2024))
    {
        printf("WARNING: incorrect date in the line");
        return 1;
    }
    if ((data->month == 4 || data->month == 6 || data->month == 9 ||
         data->month == 11) &&
        data->day > 30)
    {
        printf("WARNING: incorrect date in the line");
        return 1;
    }
    if (data->month == 2)
    {
        if ((!(data->year / 4) && data->day > 29) || (data->day > 28))
        {
            printf("WARNING: incorrect date in the line");
            return 1;
        }
    }
    if (data->day > 31)
    {
        printf("WARNING: incorrect date in the line");
        return 1;
    }
    if ((data->minute > 60) || (data->hour > 24))
    {
        printf("WARNING: incorrect time in the line");
        return 1;
    }
    if ((data->t > MAX_TEMP) || (data->t < (MIN_TEMP)))
    {
        printf("WARNING: incorrect temperature in the line");
        return 1;
    }
    return 0;
}

void data_cgangeIJ(sensor *data, int i, int j)
{
    sensor temp;
    temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void data_sort_t(sensor *data, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (data[i].t >= data[j].t)
                data_cgangeIJ(data, i, j);
}

unsigned int date_to_int(sensor *data)
{
    return data->year << 16 | data->month << 8 | data->day;
}

void data_sort_date(sensor *data, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (date_to_int(data + i) >= date_to_int(data + j))
                data_cgangeIJ(data, i, j);
}

void AddRecord(sensor *data, int number,
               uint16_t year, uint8_t month, uint8_t day,
               uint8_t hour, uint8_t minute, int8_t t)
{
    data[number].year = year;
    data[number].month = month;
    data[number].day = day;
    data[number].hour = hour;
    data[number].minute = minute;
    data[number].t = t;
}

void accum(stat *per, sensor *data)
{
    per->rec_num++;
    per->t_avg += data->t;
    if (data->t < per->t_min)
        per->t_min = data->t;
    if (data->t > per->t_max)
        per->t_max = data->t;
}

double calc_avg(stat *per)
{
    return per->t_avg / per->rec_num;
}

void get_month_stat(int month_num, int len, sensor *data)
{
    stat month = STAT_DEFAULT;
    int i = 0;
    int cnt = 0;
    for (; i < len; i++)
    {
        if (data[i].month != month_num)
            continue;
        cnt++;
        accum(&month, &data[i]);
        month.y = data[i].year;
        month.m = data[i].month;
    }
    if (month.rec_num == 0)
    {
        printf("Statistics for month number %02d - not available\n", month_num);
        return;
    }
    month.t_avg = calc_avg(&month);

    printf("|   %04hd   |     %02hhd    |  %06d  |   %+06.2f  |    %+03hhd    |    %+03hhd   |\n",
           month.y, month.m, month.rec_num, month.t_avg, month.t_max, month.t_min);
}

void get_year_stat(int len, sensor *data)
{
    stat year = STAT_DEFAULT;

    for (int i = 0; i < len; i++)
    {
        accum(&year, &data[i]);
    }
    year.t_avg = calc_avg(&year);
    printf("Statistics for the year:\n\
            - lines processed - %d;\n\
            - average annual temperature    %+4.2f degrees Celsius;\n\
            - maximum temperature           %02hhd degrees Celsius;\n\
            - minimum temperature           %02hhd degrees Celsius;\n",
           year.rec_num, year.t_avg, year.t_max, year.t_min);
}

void stat_print_month(int month_num, int len, sensor *data)
{
    printf("----------------------------------------------------------------------\n");
    printf("|   YEAR   |   MONTH   | LINE_CNT | AWERAGE_T |   MAX_T   |   MIN_T  |\n");
    printf("----------------------------------------------------------------------\n");
    get_month_stat(month_num, len, data);
    printf("----------------------------------------------------------------------\n");
}
void stat_print_year(int len, sensor *data)
{
    printf("----------------------------------------------------------------------\n");
    printf("|   YEAR   |   MONTH   | LINE_CNT | AWERAGE_T |   MAX_T   |   MIN_T  |\n");
    for (int i = 1; i < 12; i++)
        get_month_stat(i, len, data);
    printf("----------------------------------------------------------------------\n");
    get_year_stat(len, data);
}
/*
int AddInfo(struct sensor *data)
{
    int counter = 0;
    AddRecord(data, counter++, 2021, 9, 16, 9);
    AddRecord(data, counter++, 2022, 9, 2, -9);
    AddRecord(data, counter++, 2021, 1, 7, 8);
    AddRecord(data, counter++, 2021, 9, 5, 1);
    return counter;
}*/

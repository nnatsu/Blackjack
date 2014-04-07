#ifndef _baby_h
#define _baby_h

/* Struct for storing name and associated info */
typedef struct Name Name;

struct Name{
    char name[20];
    int rank;           //For when processing separate files
    int sex;
    int size;
    double percentage;  //For when processing separate files
    
    Name *prev;         //For making master ranking with all files
    Name *next;
};

/* For storing total numbers of m/f names in each file */
typedef struct {
    int male_num;
    int female_num;
} Total;

Name *head;             //For linked list
Name *tail;

int all_m=0, all_f=0;   //Number of all m/f names
int total_num=0;        //Number of different names

char *files[23] = {"1900", "1910", "1920", "1930", "1940", "1950", "1960", "1970",
    "1980", "1990", "2000", "2001", "2002", "2003", "2004", "2005",
    "2006", "2007", "2008", "2009", "2010", "2011", "2012"};

/* Get info from each file */
void read_file(char *filename, Name **arr, Total* total);

/* Calculate percentage of names */
void get_percentage(Name *name, Total *total);


/* Add the same names together from all files */
void get_all_name_size(Name **arr);

/* Compare the sizes of two names */
int compare(Name *a, Name *b);

/* Sort linked list of names by their sizes */
void sort(Name *head);

/* Print each name and its info */
void print(Name *name, FILE *fp);

/* Initialize linked list */
void init_list();

#endif

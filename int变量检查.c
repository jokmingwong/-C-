#include <ctype.h>
#include <stdio.h>

int main() {
    char oper[100];
    gets(oper);
    //Delete space and delete int
    int i = 0, j = 0;
    while (oper[i] != '\0') {
        if (oper[i] == 'i' && oper[i + 1] == 'n' && oper[i + 2] == 't') {
            i = i + 3;
            continue;
        }
        if (isspace(oper[i])) {
            i++;
        } else {
            oper[j] = oper[i];
            i++;
            j++;
        }
    }
    oper[j] = '\0';
    puts(oper);
    i = 0;
    char *variable[20];
    char *value[20];
    int index_value = 0;
    int hasValue = 0;
    while (oper[i] != ';') {
        char name[10];
        char val[10];
        //read a variable name and value
        while (1) {
            if (oper[i] == ',' || oper[i] == ';') {
                name[i] = '\0';
                break;
            }
            name[i] = oper[i];
            if (oper[i] == '=') {
                name[i] = '\0';
                hasValue = 1;
                int q = i + 1;
                int p = 0;
                while (isdigit(oper[q])) {
                    val[p++] = oper[q++];
                }
                val[p] = '\0';
                break;
            }
            i++;
        }
        //Whatever the variable has value,the name must be alive
        if (hasValue) {
            variable[index_value] = name;
            value[index_value] = val;
            hasValue = 0;
        } else {
            variable[index_value] = name;
            value[index_value] = "NULL";
        }
        index_value++;
        i++;
    }
    return 0;
}

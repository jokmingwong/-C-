#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void m_getline(char *dst)
{
    int input = 0;
    int index = 0;
    while ((input = getchar()) != '\n')
    {
        dst[index++] = (char)input;
    }
    dst[index] = '\0';
}

void fill_alpha_and_unique_line(char *line, char *alpha)
{
    char input;
    int unique_index = 0;
    int normal_index = 0;
    while ((input = line[normal_index++]) != '\0')
    {
        if (!alpha[(int)input])
        {
            line[unique_index++] = input;
            alpha[(int)input] = 1;
        }
    }
    line[unique_index] = '\0';
}

void concate_line(char *alpha, char *line)
{
    int i = 32;
    int size = strlen(line);
    for (; i <= 126; ++i)
    {
        if (alpha[i] == 0)
            line[size++] = i;
    }
    line[size] = '\0';
}

typedef struct _node
{
    char value;
    struct _node *prev;
    struct _node *next;
} node;

typedef node *list;

list build_list(char *line)
{
    int i = 1;
    int size = strlen(line);
    list lst = (list)malloc(sizeof(node));
    lst->prev = lst->next = lst;
    lst->value = line[0];

    // puts(line);

    while (i++ < size) // insert nodes
    {
        node *next_node = (list)malloc(sizeof(node));
        next_node->value = line[i - 1];

        next_node->next = lst;
        lst->prev->next = next_node;
        next_node->prev = lst->prev;
        lst->prev = next_node;

        // printf("%c -> %c\n", lst->prev->prev->value, lst->prev->value);
    }
    return lst;
}

// return the new head of list (i.e., next to delete)
list delete_head_and_set_key(list lst, char *keys)
{
    char head_value = lst->value;

    // delete
    list temp = lst;
    lst->prev->next = lst->next;
    lst->next->prev = lst->prev;
    lst = lst->next;
    temp->prev = temp->next = NULL;
    free(temp);

    // now lst is next of deleted element
    int i = 1;
    for (; i < head_value; ++i)
        lst = lst->next;
    keys[(int)head_value] = lst->value;
    return lst;
}

void build_key_pairs(char *line, char *keys)
{
    int size = strlen(line);
    list lst = build_list(line);

    int i = 0;
    for (; i < (size - 1); ++i)
    {
        lst = delete_head_and_set_key(lst, keys);
    }
    keys[(int)lst->value] = line[0];
}

void fill_keys(char *keys)
{
    int i = 0;
    for (; i < 256; ++i)
    {
        if (!keys[i])
            keys[i] = i;
    }
}

int main()
{
    char alpha[256] = {0};
    char line[1000];
    m_getline(line);
    fill_alpha_and_unique_line(line, alpha);
    concate_line(alpha, line);

    // now the line is done

    char keys[256] = {0};
    build_key_pairs(line, keys);
    fill_keys(keys);

    FILE *in = fopen("in.txt", "r");
    FILE *out = fopen("in_crpyt.txt", "w");
    int input;

    // keys[origin] = code
    while ((input = fgetc(in)) != EOF)
        fputc(keys[input], out);

    fclose(in);
    fclose(out);
    return 0;
}

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <get_muls.h>
#include <linked_list.h>

#define MAX_MATCHES 1000000

static void print_void_mul(struct void_type* self, void* void_mul) {
    struct muls mul = *((struct muls*)(void_mul));
    printf("mul(%lu, %lu)", mul.multiplicand, mul.multiplier);
}

static int compare_void_mul(struct void_type* self, void* a, void* b) {
    printf("This isn't used");
}

static struct void_type get_mul_void() {
    struct void_type mv = {
        mv.size = sizeof(struct muls),
        mv.print = print_void_mul,
        mv.compare = compare_void_mul
    };
    return mv;
}

static struct muls get_nums_from_muls(char* input) {
    input += 4;
    char* end_ptr = NULL;
    unsigned long multiplicand = strtoul(input, &end_ptr, 10);
    input = end_ptr + 1;
    unsigned long multiplier = strtoul(input, &end_ptr, 10);
    struct muls mul = {
        .multiplicand = multiplicand,
        .multiplier = multiplier
    };
    return mul;
}

static unsigned long long add_muls(struct linked_list* ll) {
    unsigned long result = 0;
    while(ll->start != NULL) {
        struct muls mul = *((struct muls *)(ll->start->data));
        result += mul.multiplicand * mul.multiplier;
        ll->start = ll->start->next;
    }
    return result;
}

unsigned long long get_muls(char* input)
{
    struct void_type vm = get_mul_void();
    struct linked_list ll = get_linked_list(&vm, NULL);
    regex_t regex;
    int reti;
    char msgbuf[100];
    char *pattern1 = "mul\\([0-9]+,[0-9]+\\)";
    regmatch_t matches[MAX_MATCHES];

    /* Compile regular expression */
    reti = regcomp(&regex, pattern1, REG_EXTENDED);
    if (reti)
    {
        fprintf(stderr, "could not compile\n");
        exit(EXIT_FAILURE);
    }
    printf("Nsubs = %zu\n", regex.re_nsub);

    while (1) {
        reti = regexec(&regex, input, MAX_MATCHES, matches, 0);
        if (!reti)
        {
            for (size_t i = 0; i <= regex.re_nsub; i++)
            {
                char buff[20] = "";
                memcpy(buff, input + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
                input += matches[i].rm_eo;
                struct muls mul = get_nums_from_muls(buff);
                ll.list_add(&ll, &mul);
            }
        }
        else if (reti == REG_NOMATCH)
        {
            puts("No match");
            regfree(&regex);
            break;
        }
        else
        {
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            exit(EXIT_FAILURE);
        }
    }
    regfree(&regex);
    return add_muls(&ll);
}

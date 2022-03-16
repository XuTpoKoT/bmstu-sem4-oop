#ifndef LINKS_H
#define LINKS_H

#include "err.h"

struct link_t
{
    size_t p_ind1;
    size_t p_ind2;
};

struct links_t
{
    size_t count = 0;
    link_t *data = NULL;
};

void links_init(links_t &links);
err_t links_malloc(links_t &links, const int count);
void links_free(links_t &links);
err_t links_read(links_t &links, FILE *f);

#endif // LINKS_H

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
    size_t count;
    link_t *data;
};

void links_init(links_t &links);
err_t links_malloc(links_t &links, const size_t count);
void links_free(links_t &links);
err_t links_read(links_t &links, FILE *f);
err_t links_create(links_t &links, FILE *f);
bool links_are_correct(const links_t &links);

#endif // LINKS_H

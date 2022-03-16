#include "links.h"

err_t links_malloc(links_t &links, const int count)
{
    links.count = count;

    links.data = (link_t*)malloc(sizeof(link_t) * count);
    err_t rc = OK;
    if (links.data == NULL)
        rc = MEMORY_ERR;

    return rc;
}

void links_free(links_t &links)
{
    links.count = 0;
    free(links.data);
}

static void link_init(link_t &link) {
    link.p_ind1 = 0;
    link.p_ind2 = 0;
}

static err_t link_read(link_t &link, FILE *f)
{
    err_t rc = OK;
    if (fscanf(f, "%zu%zu", &link.p_ind1, &link.p_ind2) != 2)
        rc = READ_LINK_ERR;

    return rc;
}

void links_init(links_t &links) {
    for (size_t i = 0; i < links.count; i++) {
        link_init(links.data[i]);
    }
}

err_t links_read(links_t &links, FILE *f)
{
    err_t rc = OK;
    for (size_t i = 0; i < links.count && rc == OK; i++)
        rc = link_read(links.data[i], f);

    return rc;
}

static void link_copy(link_t &dst, const link_t &src) {
    dst.p_ind1 = src.p_ind1;
    dst.p_ind2 = src.p_ind2;
}

err_t links_create_copy(links_t &dst, const links_t &src)
{
    err_t rc = links_malloc(dst, src.count);
    if (rc == OK) {
        for (size_t i = 0; i < dst.count; i++)
            link_copy(dst.data[i], src.data[i]);
    }
    return rc;
}
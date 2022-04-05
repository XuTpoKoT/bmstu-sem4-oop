#include "links.h"

err_t links_malloc(links_t &links, const size_t count)
{
    links.count = count;

    links.data = (link_t*)malloc(sizeof(link_t) * count);
    err_t rc = OK;
    if (links.data == NULL)
        rc = MALLOC_LINKS_ERR;

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
    for (size_t i = 0; rc == OK && i < links.count; i++)
        rc = link_read(links.data[i], f);

    return rc;
}

static err_t read_links_count(size_t &count, FILE *f) {
    err_t rc = OK;
    if (fscanf(f, "%zu", &count) != 1 || count == 0)
        rc = READ_LINKS_COUNT_ERR;
    return rc;
}

err_t links_create(links_t &links, FILE *f) {
    size_t count;
    err_t rc = read_links_count(count, f);

    if (rc == OK) {
        rc = links_malloc(links, count);
        if (rc == OK) {
            rc = links_read(links, f);
            if (rc == READ_POINT_ERR)
                links_free(links);
        }
    }

    if (rc != OK)
        rc =  CREATE_LINKS_ERR;
    return rc;
}

bool links_are_correct(const links_t &links) {
    return links.count != 0;
}


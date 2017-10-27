/*
Author: Choi Changmin
Date: 17.10.19

SYS_QUEUE_SIZE: Max Queue size.
struct sysp_item: Queue Item. it contains file system name, time, writing block number.
*/

#ifndef SYSP
#define SYSP

#include <linux/mutex.h>
#include <linux/types.h>

#define SYS_QUEUE_SIZE 10000

struct sysp_item {
    char* fsname;
    u64 time;
    sector_t block_num;
};

void sysp_enqueue(struct sysp_item);

#endif /*SYSP*/

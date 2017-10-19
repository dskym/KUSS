#ifndef SYSP
#define SYSP

#include <linux/mutex.h>
#include <linux/types.h>

#define SYS_QUEUE_SIZE 1000


struct sysp_item {
    char* fsname;
    u64 time;
    sector_t block_num;
};

/*
extern struct mutex sysp_mutex;
extern int sysp_qstart;
extern int sysp_qend;
extern int sysp_qcount;
extern const int sysp_qsize;
extern struct sysp_item sysp_q;
*/

//void sysp_init();
void sysp_enqueue(struct sysp_item);

#endif /*SYSP*/

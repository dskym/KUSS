/*
Author: Choi Changmin / Kim Seungyoon
Date: 17.10.19

Code for Queue.

sysp_mutex: Mutex variable for not to coincide reading and enqueue
sysp_qstart: Starting index for circular queue
sysp_qend: Ending index for circular queue
sysp_qcount: Num of items of Queue for checking queue empty.
    Increase over SYS_QUEUE_SIZE.
sysp_qsize: Fixed queue size. But maybe useless because of SYS_QUEUE_SIZE
sysp_q: Queue for struct sysp_item.

sysp_enqueue: Enqueue function. Overwrite from index 0 if queue full.
*/

#include <linux/module.h>

#include "sysp.h"

struct mutex sysp_mutex;
EXPORT_SYMBOL(sysp_mutex);

int sysp_qstart = 0;
int sysp_qend = 0;
int sysp_qcount = 0;
const int sysp_qsize = SYS_QUEUE_SIZE;
struct sysp_item sysp_q[SYS_QUEUE_SIZE];
EXPORT_SYMBOL(sysp_qstart);
EXPORT_SYMBOL(sysp_qend);
EXPORT_SYMBOL(sysp_qcount);
EXPORT_SYMBOL(sysp_qsize);
EXPORT_SYMBOL(sysp_q);

void sysp_enqueue(struct sysp_item item){
    if(sysp_qcount == 0){
        mutex_init(&sysp_mutex);
    }
    mutex_lock(&sysp_mutex);

    sysp_q[sysp_qend] = item;
    sysp_qend++;
    sysp_qcount++;

    if(sysp_qend == SYS_QUEUE_SIZE){
        sysp_qend = 0;
    }
    if(sysp_qstart == sysp_qend){
        sysp_qstart++;
    }
    if(sysp_qstart == SYS_QUEUE_SIZE){
        sysp_qstart = 0;
    }

    mutex_unlock(&sysp_mutex);
}
EXPORT_SYMBOL(sysp_enqueue);

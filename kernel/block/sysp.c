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

//void sysp_init(){
//    mutex_init(&sysp_mutex);
//}

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

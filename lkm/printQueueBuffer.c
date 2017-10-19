#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#include "../block/sysp.h"

#define PROC_DIRNAME "SystemProgramming"
#define PROC_FILENAME "Buffer"

static struct proc_dir_entry *proc_dir;
static struct proc_dir_entry *proc_file;

static int buffer_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Proc FileSystem Open.\n");
	printk(KERN_INFO "Queue Buffer Read Start!\n");

	return 0;
}

static ssize_t buffer_read(struct file *file, char __user *user_buffer, size_t count, loff_t *ppos)
{
	extern struct sysp_item sysp_q[SYS_QUEUE_SIZE];
	extern int sysp_qstart;
	extern int sysp_qend;
	extern int sysp_qcount;
	extern const int sysp_qsize;

	int index;

	printk(KERN_ALERT "Queue Buffer Read\n");
	printk(KERN_ALERT "%d\n", count);

	//locking mutex;
    /*
	//read queue;
    for(index = sysp_qstart; (index % sysp_qsize) != sysp_qend; index++) {
        printk(KERN_ALERT "--- fs name : %s, block num : %lu, time : %llu--- \n"
                , sysp_q[index].fsname
                , sysp_q[index].block_num
                , sysp_q[index].time);
    }
    */

	//unlocking mutex;

	return count;
}

static const struct file_operations buffer_fops = {
	.owner = THIS_MODULE,
	.open = buffer_open,
	.read = buffer_read,
};

static int __init print_buffer_module_init(void)
{
	printk(KERN_INFO "Moudle init\n");

	proc_dir = proc_mkdir(PROC_DIRNAME, NULL);
	proc_file = proc_create(PROC_FILENAME, 0600, proc_dir, &buffer_fops);

	return 0;
}

static void __exit print_buffer_module_exit(void)
{
	printk(KERN_INFO "Module exit\n");

    proc_remove(proc_file);
    proc_remove(proc_dir);

	return;
}

module_init(print_buffer_module_init);
module_exit(print_buffer_module_exit);

MODULE_AUTHOR("Kim SeungYoon and Choi ChangMin");
MODULE_DESCRIPTION("Read queue buffer using proc file system.");
MODULE_LICENSE("GPL");
MODULE_VERSION("NEW");

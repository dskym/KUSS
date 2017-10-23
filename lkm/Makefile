obj-m += printQueueBuffer.o

KDIR = /usr/src/linux-4.4
#PWD = /usr/src/linux-4.4/lkm

all :
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean :
	rm -rf *.o *.ko *.mod.* *.symvers *.order

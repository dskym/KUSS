Files

kernel/
    segbuf.c - Modified
    block/
        Makefile - Modified
        blk-core.c - Modified
        sysp.c
        sysp.h
lkm/
    Makefile
    printQueueBuffer.c
    sysp.h


Move to:

kernel/
    segbuf.c -> fs/nilfs2/segbuf.c
    block/
        Makefile -> block/Makefile
        blk-core.c -> block/blk-core.c
        sysp.c -> block/sysp.c
        sysp.h -> block/sysp.h

lkm/ - Any directory may be good. We tested at linux kernel directory.(/linux-4.4/lkm)
    Makefile
    printQueueBuffer.c
    sysp.h

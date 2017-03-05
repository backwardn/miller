#ifndef MLR_ARCH_H
#define MLR_ARCH_H

// ----------------------------------------------------------------
// Miller is single-threaded and the file-locking in getc is simply an unneeded
// performance hit, so we intentionally call getc_unlocked().  But for MSYS2
// (Windows port), there exists no such.
#ifdef MLR_ON_MSYS2
#define mlr_arch_getc(stream) getc(stream)
#else
#define mlr_arch_getc(stream) getc_unlocked(stream)
#endif

#endif // MLR_ARCH_H

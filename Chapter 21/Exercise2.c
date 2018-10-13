
In dirent.h the following function is hidden by a macro, depending on two conditions.

/* Return the file descriptor used by DIRP.  */
extern int dirfd (DIR *__dirp) __THROW __nonnull ((1));

# if defined __OPTIMIZE__ && defined _DIR_dirfd
#  define dirfd(dirp)	_DIR_dirfd (dirp)
# endif

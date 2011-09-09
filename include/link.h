/* We have a local link.h because bionic is lacking this header file */

#ifndef ANDROID
#include_next <link.h>
#else 
#ifndef _LINK_H
#define _LINK_H 1

#include <stdlib.h>
#include <elf.h>

#define ElfW(type)      _ElfW (Elf, 32, type)
#define _ElfW(e,w,t)    _ElfW_1 (e, w, _##t)
#define _ElfW_1(e,w,t)  e##w##t

struct dl_phdr_info
  {
    ElfW(Addr) dlpi_addr;
    const char *dlpi_name;
    const ElfW(Phdr) *dlpi_phdr;
    ElfW(Half) dlpi_phnum;

    /* Note: Following members were introduced after the first
       version of this structure was available.  Check the SIZE
       argument passed to the dl_iterate_phdr callback to determine
       whether or not each later member is available.  */

    /* Incremented when a new object may have been added.  */
    unsigned long long int dlpi_adds;
    /* Incremented when an object may have been removed.  */
    unsigned long long int dlpi_subs;

    /* If there is a PT_TLS segment, its module ID as used in
       TLS relocations, else zero.  */
    size_t dlpi_tls_modid;

    /* The address of the calling thread's instance of this module's
       PT_TLS segment, if it has one and it has been allocated
       in the calling thread, otherwise a null pointer.  */
    void *dlpi_tls_data;
  };
#endif

#endif /* ANDROID */ 


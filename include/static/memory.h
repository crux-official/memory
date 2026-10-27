#ifndef CRUX_STATIC_MEMORY_H
#define CRUX_STATIC_MEMORY_H

#include "kernel_types.h"
#include "memory_api.h"

#ifdef __cplusplus
extern "C" {
#endif

// The static rendering of the memory contract: plain externs, defined by
// the memory driver and linked into the binary. A static consumer pays zero
// indirection and cannot accidentally dispatch - the same shape as the
// platform's static rendering.
extern void *Memory_Alloc(size_t size);
extern void Memory_Free(void *ptr);
extern void *Memory_Calloc(size_t num_elements, size_t size);
extern void *Memory_Realloc(void *ptr, size_t size);
extern void *Memory_Reserve(size_t size);
extern void Memory_Release(void *ptr, size_t size);
extern bool Memory_Commit(void *ptr, size_t size);
extern void Memory_Decommit(void *ptr, size_t size);
extern bool Memory_SupportsVirtual(void);
extern MemoryStats Memory_GetStats(void);

#ifdef __cplusplus
}
#endif

#endif

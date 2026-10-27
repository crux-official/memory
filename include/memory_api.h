#ifndef CRUX_MEMORY_API_H
#define CRUX_MEMORY_API_H

#include "kernel_types.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The memory concern's contract: the one struct of function pointers the
// memory driver fills and serves. The concern is dispatched
// through the engine's registry channel: the driver's served MemoryAPI,
// selected by the concern's stable dispatch id. The driver that fills it is selected per platform by the
// composition's driver table; the 1:1 concern bijection says this interface
// is driven by exactly one driver in every cell that composes it.
//
// The concern's stats record (the concern owns its own types).
typedef struct MemoryStats {
  size_t page_size;
  size_t allocation_granularity;
  size_t total_physical_memory;
  size_t available_physical_memory;
} MemoryStats;

// Every API struct in this project leads with its version.
typedef struct MemoryAPI {
  PackageVersion version;
  void *(*Alloc)(size_t size);
  void (*Free)(void *ptr);
  void *(*Calloc)(size_t num_elements, size_t size);
  void *(*Realloc)(void *ptr, size_t size);
  void *(*Reserve)(size_t size);
  void (*Release)(void *ptr, size_t size);
  bool (*Commit)(void *ptr, size_t size);
  void (*Decommit)(void *ptr, size_t size);
  bool (*SupportsVirtual)(void);
  MemoryStats (*GetStats)(void);
} MemoryAPI;

#ifdef __cplusplus
}
#endif

#endif

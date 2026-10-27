#ifndef CRUX_DYNAMIC_MEMORY_H
#define CRUX_DYNAMIC_MEMORY_H

#include "kernel_types.h"
#include "memory_api.h"
#include "engine.h"
#include "kernel_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// The dynamic rendering of the memory contract: every call dispatches
// through the engine's registry channel - the memory driver's served
// MemoryAPI, selected by the concern's stable dispatch id (DRIVER_MEMORY,
// platform_types.h). crux_engine_api is the module-global pointer defined by
// the install TU the DYNAMIC dialect compiles in and installed by the
// target's Construct (the same pattern as the engine's own dynamic rendering).
static inline void *Memory_Alloc(size_t size) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Alloc(size);
}
static inline void Memory_Free(void *ptr) {
  ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Free(ptr);
}
static inline void *Memory_Calloc(size_t num_elements, size_t size) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Calloc(num_elements, size);
}
static inline void *Memory_Realloc(void *ptr, size_t size) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Realloc(ptr, size);
}
static inline void *Memory_Reserve(size_t size) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Reserve(size);
}
static inline void Memory_Release(void *ptr, size_t size) {
  ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Release(ptr, size);
}
static inline bool Memory_Commit(void *ptr, size_t size) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Commit(ptr, size);
}
static inline void Memory_Decommit(void *ptr, size_t size) {
  ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->Decommit(ptr, size);
}
static inline bool Memory_SupportsVirtual(void) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->SupportsVirtual();
}
static inline MemoryStats Memory_GetStats(void) {
  return ((MemoryAPI *)crux_engine_api->GetExtensionAPI(DRIVER_MEMORY))->GetStats();
}

#ifdef __cplusplus
}
#endif

#endif

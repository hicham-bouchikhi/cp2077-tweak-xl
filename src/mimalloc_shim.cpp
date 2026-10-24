// Compatibility shim: precompiled TiltedCore.lib references `mi_malloc_size`
// as an external symbol; mimalloc v3 only provides it inline.
#include <cstddef>

extern "C" std::size_t mi_usable_size(const void* p);

extern "C" std::size_t mi_malloc_size(const void* p)
{
    return mi_usable_size(p);
}

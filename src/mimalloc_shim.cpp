// Compatibility shim.
//
// TiltedCore.lib (precompiled xmake package) references `mi_malloc_size` as an
// external symbol. mimalloc v3 no longer exports it as a function (it is an
// inline wrapper around `mi_usable_size`), so the link fails with LNK2019.
//
// We do not include <mimalloc.h> on purpose: defining the symbol here avoids a
// redefinition clash if the header declares it inline.

#include <cstddef>

extern "C" std::size_t mi_usable_size(const void* p);

extern "C" std::size_t mi_malloc_size(const void* p)
{
    return mi_usable_size(p);
}

#ifndef INCLUDE_H
#define INCLUDE_H

/*
    Some parameters are used only in specific modes (e.g., linked vs. array-based stacks), 
    causing unused parameter warnings in others. To suppress these warnings, we have several options:

    1. **Cast to Void**: `(void) parameter;` — A simple, portable way to indicate intentional non-use, 
        compatible across all compilers.
    
    2. **Compiler-Specific Attribute**: `__attribute__((unused))` — Works for GCC/Clang but lacks portability.
    
    3. **C++17 Attribute**: `[[maybe_unused]]` — Available in C++17 but not in all C environments.

    I've used the `(void) parameter;` approach for maximum portability. And for readability, we define a macro:
*/
#define UNUSED(x) (void)(x)

#endif // INCLUDE_H
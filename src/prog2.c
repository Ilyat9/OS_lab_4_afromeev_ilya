#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle = NULL;
    int (*GCF)(int, int);
    float (*E)(int);
    
    const char *lib_names[] = {"./lib1.so", "./lib2.so"};
    int current_lib = 0; 

    handle = dlopen(lib_names[current_lib], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }
    
    GCF = dlsym(handle, "GCF");
    E = dlsym(handle, "E");
    
    if (!GCF || !E) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    printf("Program 2. Current lib: %s\n", lib_names[current_lib]);
    printf("Commands: 0 (switch), 1 <A> <B>, 2 <x>\n");

    int command;
    while (scanf("%d", &command) != EOF) {
        if (command == 0) {
            dlclose(handle);
            
            current_lib = 1 - current_lib;
            
            handle = dlopen(lib_names[current_lib], RTLD_LAZY);
            if (!handle) {
                fprintf(stderr, "Error loading lib: %s\n", dlerror());
                return 1;
            }
            
            GCF = dlsym(handle, "GCF");
            E = dlsym(handle, "E");
            
            if (!GCF || !E) {
                fprintf(stderr, "Error finding symbols: %s\n", dlerror());
                return 1;
            }
            
            printf("Switched to %s\n", lib_names[current_lib]);
            
        } else if (command == 1) {
            int a, b;
            if (scanf("%d %d", &a, &b) == 2) {
                printf("GCF(%d, %d) = %d\n", a, b, GCF(a, b));
            }
        } else if (command == 2) {
            int x;
            if (scanf("%d", &x) == 1) {
                printf("E(%d) = %f\n", x, E(x));
            }
        }
    }

    dlclose(handle);
    return 0;
}

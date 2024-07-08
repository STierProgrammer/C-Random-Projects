#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define MEMORY_POOL 1024

typedef struct MemoryBlock {
    size_t size;
    bool isFree;
    struct MemoryBlock* next;
} MemoryBlock;

static char MemoryAddressPool[MEMORY_POOL];

static MemoryBlock* Memory = (MemoryBlock*)MemoryAddressPool;

void InitializeMemory() {
    Memory->size = MEMORY_POOL;
    Memory->isFree = true;
    Memory->next = NULL;
}

void divide(MemoryBlock* currentBlock, size_t size) {
    size_t totalSize = size;

    if (currentBlock->size <= totalSize) {
        currentBlock->isFree = false;
        return;
    }

    MemoryBlock* newBlock = (MemoryBlock*)((char*)currentBlock + totalSize);

    newBlock->size = currentBlock->size - totalSize;
    newBlock->isFree = true;
    newBlock->next = currentBlock->next;

    currentBlock->size = size;
    currentBlock->isFree = false;
    currentBlock->next = newBlock;
}

void* MallocRipoff(size_t size) {
    MemoryBlock* currentBlock = Memory;

    while (currentBlock != NULL) {
        if (currentBlock->isFree && currentBlock->size >= size) {
            divide(currentBlock, size);

            return (void*)((char*)currentBlock + sizeof(MemoryBlock));
        }

        currentBlock = currentBlock->next;
    }

    return NULL;
}



void PrintMemory() {
    MemoryBlock* currentBlock = Memory;

    while (currentBlock != NULL) {
        printf("%p, %zu\n", (void*)currentBlock, currentBlock->size);
        
        currentBlock = currentBlock->next;
    }
}

int main() {
    InitializeMemory();

    int* ptr = (int*)MallocRipoff(1000);

    int* ptr1 = (int*)MallocRipoff(24);
    *ptr1 = 4;

    int* ptr2 = (int*)MallocRipoff(4); // This fails to allocate because the memory is full even though we changed ptr1 to 4 bytes those 20 bytes didn't get freed

    PrintMemory();

    

    return 0;
}

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
    Memory->size = MEMORY_POOL + sizeof(MemoryBlock); 
    Memory->isFree = true; 
    Memory->next = NULL;
}

void divide(MemoryBlock* currentBlock, size_t size) 
{
    size_t totalSize = size + sizeof(MemoryBlock);

    if (currentBlock->size <= totalSize) 
    {
        currentBlock->isFree = false; return;
    }

    MemoryBlock* newBlock = (MemoryBlock*)((char*)currentBlock + totalSize);

    newBlock->size = currentBlock->size - totalSize + sizeof(MemoryBlock);
    newBlock->isFree = true;
    newBlock->next = currentBlock->next;

    currentBlock->size = size;
    currentBlock->isFree = false;
    currentBlock->next = newBlock;
}


void* MallocRipoff(size_t size) 
{
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

void FreeRipoff(void* ptr) 
{
    if (!ptr) return;

    MemoryBlock* currentBlock = (MemoryBlock*)((char*)ptr - sizeof(MemoryBlock));

    currentBlock->isFree = true;

    if (currentBlock->next && currentBlock->next->isFree)
        currentBlock->size += currentBlock->next->size;
        currentBlock->next = currentBlock->next->next;
       
    MemoryBlock* block = Memory;

    while (block && block->next != currentBlock) 
        block = block->next;
    
    if (block && block->isFree) 
        block->size += currentBlock->size;
        block->next = currentBlock->next;
}

void PrintMemory() {
    MemoryBlock* currentBlock = Memory;

    while (currentBlock != NULL) 
        printf("Address: %p, Size: %zu\n", (void*)currentBlock, currentBlock->size);

        currentBlock = currentBlock->next;
}

int main() {
    InitializeMemory();

    int* ptr1 = (int*)MallocRipoff(sizeof(int));
    
    *ptr1 = 4;

    char* ptr2 = (char*)MallocRipoff(sizeof(char));

    PrintMemory();

    FreeRipoff(ptr2);

    PrintMemory();

    return 0;
}

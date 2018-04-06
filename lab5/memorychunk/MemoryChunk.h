//
// Created by sadojaku on 06.04.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>
#include<iostream>
namespace memorychunk
{
    class MemoryChunk {
    public:
        MemoryChunk();
        MemoryChunk(const MemoryChunk & other);
        MemoryChunk(MemoryChunk&& other);
        MemoryChunk& operator= (const MemoryChunk& other);
        MemoryChunk& operator= (MemoryChunk&& other);
        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    private:
        int * memory;
    };
}



#endif //JIMP_EXERCISES_MEMORYCHUNK_H

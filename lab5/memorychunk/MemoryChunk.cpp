//
// Created by sadojaku on 06.04.18.
//
#include <cstddef>
#include "MemoryChunk.h"
using namespace memorychunk;
MemoryChunk::MemoryChunk()
{
    memory = nullptr;
}
MemoryChunk::MemoryChunk(const MemoryChunk& other){
    memory = new int[sizeof(other)/4];
    *memory = *other.memory;
}
MemoryChunk::MemoryChunk(MemoryChunk&& other)
{
    *memory = *other.memory;
    other.memory = nullptr;
}
MemoryChunk & MemoryChunk::operator=(const MemoryChunk& other)
{
    MemoryChunk tmp(other);
    *this = std::move(tmp);
    return *this;
}
MemoryChunk& MemoryChunk::operator=(MemoryChunk&& other)
{
    if(this == &other)
    {
        return *this;
    }
    delete memory;
    *memory = *other.memory;
    other.memory = nullptr;
    return *this;
}
MemoryChunk::MemoryChunk(size_t sz)
{
    memory = new int[sz];
}
int8_t* MemoryChunk::MemoryAt(size_t offset) const
{

}

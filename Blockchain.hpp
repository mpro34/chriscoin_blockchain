#pragma once

#include <cstdint>
#include <vector>
#include "Block.hpp"

using namespace std;

class Blockchain
{
public:
    Blockchain();

    void AddBlock(Block new_block);

private:
    uint32_t mDifficulty;
    vector<Block> mChain;

    Block _GetLastBlock() const;
};
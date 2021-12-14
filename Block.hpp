#pragma once

#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block
{
public:
    string mPrevHash;

    Block(uint32_t index_in, const string &data_in);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t mIndex;
    int64_t mNonce;
    string mData;
    string mHash;
    time_t mTime;

    string _CalculateHash() const;
};
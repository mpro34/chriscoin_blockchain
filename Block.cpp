#include "Block.hpp"
#include "sha256/sha256.h"

Block::Block(uint32_t index_in, const string &data_in) : mIndex(index_in), mData(data_in)
{
    mNonce = -1;
    mTime = time(nullptr);
}

string Block::GetHash()
{
    return mHash;
}

void Block::MineBlock(uint32_t nDifficulty)
{
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    
    string str(cstr);

    do {
        mNonce++;
        mHash = _CalculateHash();
    } while (mHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << mHash << endl;
}

inline string Block::_CalculateHash() const 
{
    stringstream ss;
    // Add all transaction data and then calculate the hash of that data.
    ss << mIndex << mTime << mData << mNonce << mPrevHash;

    return sha256(ss.str());
}
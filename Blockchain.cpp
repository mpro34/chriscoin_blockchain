#include "Blockchain.hpp"

Blockchain::Blockchain()
{
    mChain.emplace_back(Block(0, "Genesis Block"));
    mDifficulty = 0;
}

void Blockchain::AddBlock(Block new_block)
{
    new_block.mPrevHash = _GetLastBlock().GetHash();
    new_block.MineBlock(mDifficulty);
    mChain.push_back(new_block);
}

Block Blockchain::_GetLastBlock() const
{
    return mChain.back();
}
#ifndef HASH_H
#define HASH_H

#include "DataTypes.h"

ull myHash(const Pos &P);

struct PosHash {
    size_t operator()(const Pos &P) const;
};

#endif // HASH_H

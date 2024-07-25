#include "merchanthoard.h"

MerchantHoard::MerchantHoard(int row, int col) : Treasure{row,col} {
    value = 4;
    goldType = "merchanthoard";
}


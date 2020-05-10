#include <string>
#include <vector>
#include <array>

#include "block_t.h"

block_t::block_t(int index, int b, unsigned char *bl) {
    piece_index = index;
    offset = b;
    for(int i = 0; i < sizeof(bl); i++) {

    }
}

int block_t::get_index() {
    return piece_index;
}

int block_t::get_offset() {
    return offset;
}

unsigned char* block_t::get_block() {
    return data;
}
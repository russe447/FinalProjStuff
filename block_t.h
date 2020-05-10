#include <string>
#include <array>
#include <vector>
#include <string.h>
#include <stdlib.h>

#define MAX_BLOCK 16384

using namespace std;

class block_t {

private:
    int piece_index;
    int offset;
    unsigned char* data;

public:
    block_t(int index, int b, unsigned char* bl); // Takes the piece index, the offset of the piece, and the block
    int get_index();
    int get_offset();
    unsigned char* get_block();
};
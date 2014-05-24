#include <cstdlib>
#include "eeprom.h"
void* eeprom_read_block (void *__dst, const void *__src, size_t __n) {
    return memcpy((void*)__dst, (const void*)__src, (int)__n);
}
void* eeprom_write_block (const void *__src,  void *__dst, size_t __n) {
    return memcpy(__dst, __src, __n);
};

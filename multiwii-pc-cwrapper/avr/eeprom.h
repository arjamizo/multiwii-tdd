
#include <cstring>//for size_t
void* eeprom_read_block (void *__dst, const void *__src, size_t __n);
void* eeprom_write_block (const void *__src,  void *__dest, size_t __n);

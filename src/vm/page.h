#ifndef VM_PAGE_H
#define VM_PAGE_H

#include "vm/struct.h"
#include <list.h>
#include <stdbool.h>
#include <stddef.h>
#include "filesys/file.h"

struct page_struct *_new_page(int type, void *, bool, struct file *, off_t,
		uint32_t, uint32_t, off_t);
bool _pin(bool operation, void *pagetemp, bool directFrameAccess);
bool _operation_page(int type, void *address, void * kpage, bool pinned);
void _vm_init(void);
struct page_struct *_stack_grow(void *address, bool pin);
struct page_struct *_find_page(void *address);

unsigned frame_hash(const struct hash_elem *f_, void *aux);
bool frame_less_helper(const struct hash_elem *a_, const struct hash_elem *b_,
		void *aux);

unsigned mmap_hash(const struct hash_elem *mf_, void *aux);
bool mmap_less_helper(const struct hash_elem *a_, const struct hash_elem *b_,
		void *aux);

#endif

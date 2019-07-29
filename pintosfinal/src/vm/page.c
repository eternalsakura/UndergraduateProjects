#include "page.h"

/*Used for hashing*/
unsigned SuppPage_Table_Hash_Func (const struct hash_elem *p_, void *aux UNUSED)
{
const struct SuppPageTable *p = hash_entry (p_, struct SuppPageTable, hash_elem);
return hash_bytes (&p->UserPage_VAddr, sizeof p->UserPage_VAddr);
}


/* Comparison function for hash table */
bool SuppPage_Table_Less (const struct hash_elem *a_, const struct hash_elem *b_,void *aux UNUSED)
{
const struct SuppPageTable *a = hash_entry (a_, struct SuppPageTable, hash_elem);
const struct SuppPageTable *b = hash_entry (b_, struct SuppPageTable, hash_elem);
return a->UserPage_VAddr < b->UserPage_VAddr;
}

struct SuppPageTable *page_lookup (const void *address,struct hash *Hash_Table)
{
struct SuppPageTable p;
struct hash_elem *e;
p.UserPage_VAddr = address;
e = hash_find (Hash_Table, &p.hash_elem);
return e != NULL ? hash_entry (e, struct SuppPageTable, hash_elem) : NULL;
}

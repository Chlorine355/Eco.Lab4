/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoMemoryAllocator1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов IEcoMemoryAllocator1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "CEcoMemoryManager1Lab.h"

MemBlock * firstNotAllocated(MemBlock * start, size_t count) {
    MemBlock *ptr = start;
    int i;
    for (i = 0; i < count; i++) {
        if (ptr->allocated == 0) {
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

void set_mem_block(MemBlock *block, char_t *start, size_t size, MemBlock *prev, MemBlock *next) {
    block->allocated = 1;
    block->start_ptr = start;
    block->end_ptr = start + size;
    block->prev = prev;
    block->next = next;
}

void * alloc_block(
        size_t size,
        MemBlock **last_ptr,
        MemBlock **list_start_ptr,
        MemBlock *reserved,
        size_t block_count,
        char *heap_start,
        const char *heap_end
) {
    MemBlock *list_start = *list_start_ptr;
    MemBlock *current = *last_ptr; // must be not null if list is not empty
    MemBlock *new_block;
    char new_start = 0;

    if (list_start == NULL) { // list is empty
        if (heap_end - heap_start > size) { // can allocate
            new_block = firstNotAllocated(reserved, block_count);
            if (new_block == NULL) {
                return NULL;
            }
            set_mem_block(new_block, heap_start, size, NULL, NULL);

            *list_start_ptr = new_block;
            *last_ptr = new_block;
            return new_block->start_ptr;
        }
        return NULL;
    }

    while (new_start == 0 || current != *last_ptr) {
        if (current->next != NULL) { // insertion in the middle
            if (current->next->start_ptr - current->end_ptr > size) { // can allocate between already allocated
                new_block = firstNotAllocated(reserved, block_count);
                if (new_block == NULL) {
                    return NULL;
                }
                set_mem_block(new_block, current->end_ptr, size, current, current->next);
                current->next->prev = new_block;
                current->next = new_block;

                *last_ptr = new_block;
                return new_block->start_ptr;
            } else { // need to go to the next block
                current = current->next;
                continue;
            }
        }

        // at the end of the list
        if (heap_end - current->end_ptr > size) { // can allocate at the end of the list
            new_block = firstNotAllocated(reserved, block_count);
            if (new_block == NULL) {
                return NULL;
            }
            set_mem_block(new_block, current->end_ptr, size, current, NULL);
            current->next = new_block;

            *last_ptr = new_block;
            return new_block->start_ptr;
        }

        // need to go to the list start
        new_start = 1;
        current = list_start; // must not be null
        if (current->start_ptr - heap_start > size) { // can allocate before first block
            new_block = firstNotAllocated(reserved, block_count);
            if (new_block == NULL) {
                return NULL;
            }
            set_mem_block(new_block, heap_start, size, NULL, current);
            current->prev = new_block;

            *last_ptr = new_block;
            *list_start_ptr = new_block;
            return new_block->start_ptr;
        }
    }
    return NULL;
}

void free_mem_block(const char *ptr, MemBlock **list_start_ptr) {
    MemBlock *mem_ptr = *list_start_ptr;
    if (mem_ptr->start_ptr == ptr) { // freeing first block
        mem_ptr->allocated = 0;
        if (mem_ptr->next != NULL) {
            mem_ptr->next->prev = NULL;
            *list_start_ptr = mem_ptr->next;
        } else {
            *list_start_ptr = NULL;
        }
        return;
    }

    while (mem_ptr != NULL) {
        if (mem_ptr->start_ptr == ptr) {
            mem_ptr->allocated = 0;
            if (mem_ptr->next != NULL) {
                mem_ptr->next->prev = mem_ptr->prev;
            }
            if (mem_ptr->prev != NULL) {
                mem_ptr->prev->next = mem_ptr->next;
            }
            break;
        }
        mem_ptr = mem_ptr->next;
    }
}



/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoMemoryAllocator1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_QueryInterface(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));

    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoMemoryManager1) ) {
        *ppv = &pCMe->m_pVTblIMgr;
        pCMe->m_pVTblIMgr->AddRef((IEcoMemoryManager1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoMemoryAllocator1) ) {
        *ppv = &pCMe->m_pVTblIMem;
        pCMe->m_pVTblIMgr->AddRef((IEcoMemoryManager1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoVirtualMemory1) ) {
        *ppv = &pCMe->m_pVTblIVirtual;
        pCMe->m_pVTblIMgr->AddRef((IEcoMemoryManager1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIMgr;
        pCMe->m_pVTblIMgr->AddRef((IEcoMemoryManager1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoMemoryAllocator1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_AddRef(/* in */ IEcoMemoryAllocator1Ptr_t me) {
    CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));

    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoMemoryAllocator1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Release(/* in */ IEcoMemoryAllocator1Ptr_t me) {
    CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoMemoryManager1Lab_623E1838((IEcoMemoryManager1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Alloc
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void* ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Alloc(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ uint32_t size) {
    CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));

	return alloc_block(size, &(pCMe->lastAllocated), &(pCMe->listStart), pCMe->reservedStart, pCMe->reservedBlockCount, pCMe->heapStart, pCMe->heapEnd);
}

/*
 *
 * <сводка>
 *   Функция Free
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Free(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ voidptr_t pv) {
    CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));

	free_mem_block((char_t *) pv, &(pCMe->listStart));
}

/*
 *
 * <сводка>
 *   Функция Realloc
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void* ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Realloc(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ voidptr_t pv, /* in */ uint32_t size) {
    /*CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));*/

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Copy
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void* ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Copy(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ voidptr_t pvDst, /* in */ voidptr_t pvSrc, /* in */ uint32_t size) {
    /*CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));*/

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Fill
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void* ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Fill(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ voidptr_t pvDst, /* in */ char_t Fill, /* in */ uint32_t size) {
    /*CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));*/

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Compare
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoMemoryAllocator1Lab_623E1838_Compare(/* in */ IEcoMemoryAllocator1Ptr_t me, /* in */ voidptr_t pv1, /* in */ voidptr_t pv2, /* in */ uint32_t size) {
    /*CEcoMemoryManager1Lab_623E1838* pCMe = (CEcoMemoryManager1Lab_623E1838*)((uint64_t)me - sizeof(voidptr_t));*/

    return 0;
}
/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSemaphore1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSemaphore1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECO_SEMAPHORE_1_H__
#define __I_ECO_SEMAPHORE_1_H__

#include "IEcoBase1.h"

#define ECO_SEMAPHORE_1_TIME_INTERVAL_INFINITE -1

/* IEcoSemaphore1 IID = {661C3E2E-7494-4555-B8E1-F82B2C2D3979} */
#ifndef __IID_IEcoSemaphore1
static const UGUID IID_IEcoSemaphore1 = {0x01, 0x10, {0x66, 0x1C, 0x3E, 0x2E, 0x74, 0x94, 0x45, 0x55, 0xB8, 0xE1, 0xF8, 0x2B, 0x2C, 0x2D, 0x39, 0x79}};
#endif /* __IID_IEcoSemaphore1 */

typedef struct IEcoSemaphore1* IEcoSemaphore1Ptr_t;

typedef struct IEcoSemaphore1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoSemaphore1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoSemaphore1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoSemaphore1Ptr_t me);

    /* IEcoSemaphore1 */
    int16_t (ECOCALLMETHOD *Init)(/* in */ IEcoSemaphore1Ptr_t me, /* in */ int32_t MaxCount);
    int16_t (ECOCALLMETHOD *InitWithName)(/* in */ IEcoSemaphore1Ptr_t me, /* in */ int32_t MaxCount, /* in */ char_t* Name);
    int16_t (ECOCALLMETHOD *OpenExisting)(/* in */ IEcoSemaphore1Ptr_t me, /* in */ char_t* Name);
    int16_t (ECOCALLMETHOD *Close)(/* in */ IEcoSemaphore1Ptr_t me);
    int32_t (ECOCALLMETHOD *Post)(/* in */ IEcoSemaphore1Ptr_t me);
    bool_t (ECOCALLMETHOD *Wait)(/* in */ IEcoSemaphore1Ptr_t me, /* in */ int32_t Milliseconds);

} IEcoSemaphore1VTbl, *IEcoSemaphore1VTblPtr;

interface IEcoSemaphore1 {
    struct IEcoSemaphore1VTbl *pVTbl;
} IEcoSemaphore1;


#endif /* __I_ECO_SEMAPHORE_1_H__ */

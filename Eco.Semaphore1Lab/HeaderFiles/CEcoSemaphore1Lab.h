/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSemaphore1Lab
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoSemaphore1Lab
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SEMAPHORE_1_LAB_H__
#define __C_ECO_SEMAPHORE_1_LAB_H__

#include "IEcoSemaphore1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoSemaphore1Lab_7CD26E7C {

    /* Таблица функций интерфейса IEcoSemaphore1Lab */
    IEcoSemaphore1VTbl* m_pVTblISem;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */

} CEcoSemaphore1Lab_7CD26E7C, *CEcoSemaphore1Lab_7CD26E7CPtr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoSemaphore1Lab_7CD26E7C(/*in*/ struct IEcoSemaphore1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoSemaphore1Lab_7CD26E7C(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoSemaphore1** ppISem);
/* Удаление */
void ECOCALLMETHOD deleteCEcoSemaphore1Lab_7CD26E7C(/* in */ IEcoSemaphore1* pISem);

#endif /* __C_ECO_SEMAPHORE_1_LAB_H__ */

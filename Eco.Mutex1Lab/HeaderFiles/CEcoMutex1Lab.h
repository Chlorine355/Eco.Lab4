/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoMutex1Lab
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoMutex1Lab
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_MUTEX_1_LAB_H__
#define __C_ECO_MUTEX_1_LAB_H__

#include "IEcoMutex1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoMutex1Lab_90017215 {

    /* Таблица функций интерфейса IEcoMutex1Lab */
    IEcoMutex1VTbl* m_pVTblIMutex;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */


} CEcoMutex1Lab_90017215, *CEcoMutex1Lab_90017215Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoMutex1Lab_90017215(/*in*/ IEcoMutex1Ptr_t me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoMutex1Lab_90017215(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoMutex1Ptr_t* ppIMutex);
/* Удаление */
void ECOCALLMETHOD deleteCEcoMutex1Lab_90017215(/* in */ IEcoMutex1Ptr_t pIMutex);

#endif /* __C_ECO_MUTEX_1_LAB_H__ */

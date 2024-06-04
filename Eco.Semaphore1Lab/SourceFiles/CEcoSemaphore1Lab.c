/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSemaphore1Lab_7CD26E7C
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoSemaphore1Lab_7CD26E7C
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoSemaphore1Lab.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoSemaphore1Lab
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_QueryInterface(/* in */ IEcoSemaphore1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoSemaphore1) ) {
        *ppv = &pCMe->m_pVTblISem;
        pCMe->m_pVTblISem->AddRef((IEcoSemaphore1Ptr_t)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblISem;
        pCMe->m_pVTblISem->AddRef((IEcoSemaphore1Ptr_t)pCMe);
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
 *   Функция AddRef для интерфейса IEcoSemaphore1Lab
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_AddRef(/* in */ IEcoSemaphore1Ptr_t me) {
    CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;

    /* Проверка указателя */
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
 *   Функция Release для интерфейса IEcoSemaphore1Lab
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_Release(/* in */ IEcoSemaphore1Ptr_t me) {
    CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoSemaphore1Lab_7CD26E7C((IEcoSemaphore1Ptr_t)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_Init(/* in */ IEcoSemaphore1Ptr_t me, /* in */ int32_t MaxCount) {
    /*CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;*/

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

    return 0;
}


/*
 *
 * <сводка>
 *   Функция InitWithName
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_InitWithName(/* in */ IEcoSemaphore1Ptr_t me, /* in */ int32_t MaxCount, /* in */ char_t* Name) {
    /*CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;*/

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция OpenExisting
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_OpenExisting(/* in */ IEcoSemaphore1Ptr_t me, /* in */ char_t* Name) {
    /*CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;*/

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Close
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_Close(/* in */ IEcoSemaphore1Ptr_t me) {
    /*CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;*/

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Post
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_Post(/* in */ IEcoSemaphore1Ptr_t me) {
    /*CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;*/

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Wait
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
bool_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7C_Wait(/* in */ IEcoSemaphore1Ptr_t me, /* in */ int32_t Milliseconds) {
    /*CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;*/

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoSemaphore1Lab_7CD26E7C(/*in*/ IEcoSemaphore1Ptr_t me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table IEcoSemaphore1Lab */
IEcoSemaphore1VTbl g_x661C3E2E74944555B8E1F82B2C2D3979VTbl_7CD26E7C = {
    CEcoSemaphore1Lab_7CD26E7C_QueryInterface,
    CEcoSemaphore1Lab_7CD26E7C_AddRef,
    CEcoSemaphore1Lab_7CD26E7C_Release,
    CEcoSemaphore1Lab_7CD26E7C_Init,
    CEcoSemaphore1Lab_7CD26E7C_InitWithName,
    CEcoSemaphore1Lab_7CD26E7C_OpenExisting,
    CEcoSemaphore1Lab_7CD26E7C_Close,
    CEcoSemaphore1Lab_7CD26E7C_Post,
    CEcoSemaphore1Lab_7CD26E7C_Wait
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoSemaphore1Lab_7CD26E7C(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoSemaphore1** ppISem) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoSemaphore1Lab_7CD26E7C* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppISem == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoSemaphore1Lab_7CD26E7C*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoSemaphore1Lab_7CD26E7C));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoSemaphore1Lab */
    pCMe->m_pVTblISem = &g_x661C3E2E74944555B8E1F82B2C2D3979VTbl_7CD26E7C;

    /* Инициализация данных */

    /* Возврат указателя на интерфейс */
    *ppISem = (IEcoSemaphore1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoSemaphore1Lab_7CD26E7C(/* in */ IEcoSemaphore1* pISem) {
    CEcoSemaphore1Lab_7CD26E7C* pCMe = (CEcoSemaphore1Lab_7CD26E7C*)pISem;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pISem != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

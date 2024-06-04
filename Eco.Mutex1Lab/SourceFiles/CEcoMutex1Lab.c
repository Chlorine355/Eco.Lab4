/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoMutex1Lab_90017215
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoMutex1Lab_90017215
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
#include "CEcoMutex1Lab.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoMutex1Lab
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoMutex1Lab_90017215_QueryInterface(/* in */ IEcoMutex1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv) {
    CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoMutex1) ) {
        *ppv = &pCMe->m_pVTblIMutex;
        pCMe->m_pVTblIMutex->AddRef((IEcoMutex1Ptr_t)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIMutex;
        pCMe->m_pVTblIMutex->AddRef((IEcoMutex1Ptr_t)pCMe);
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
 *   Функция AddRef для интерфейса IEcoMutex1Lab
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoMutex1Lab_90017215_AddRef(/* in */ IEcoMutex1Ptr_t me) {
    CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)me;

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
 *   Функция Release для интерфейса IEcoMutex1Lab
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoMutex1Lab_90017215_Release(/* in */ IEcoMutex1Ptr_t me) {
    CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoMutex1Lab_90017215((IEcoMutex1Ptr_t)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Lock
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoMutex1Lab_90017215_Lock(/* in */ IEcoMutex1Ptr_t me) {
    /*CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)me; */

}

/*
 *
 * <сводка>
 *   Функция UnLock
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
void CEcoMutex1Lab_90017215_UnLock(/* in */ IEcoMutex1Ptr_t me) {
    /*CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)me; */

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
int16_t ECOCALLMETHOD initCEcoMutex1Lab_90017215(/*in*/ IEcoMutex1Ptr_t me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (voidptr_t* )&pIBus);

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

/* Create Virtual Table IEcoMutex1Lab */
IEcoMutex1VTbl g_x9B964B0D168142E484388F332D4633F3VTbl_90017215 = {
    CEcoMutex1Lab_90017215_QueryInterface,
    CEcoMutex1Lab_90017215_AddRef,
    CEcoMutex1Lab_90017215_Release,
    CEcoMutex1Lab_90017215_Lock,
    CEcoMutex1Lab_90017215_UnLock
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
int16_t ECOCALLMETHOD createCEcoMutex1Lab_90017215(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoMutex1Ptr_t* ppIMutex) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoMutex1Lab_90017215* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIMutex == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (voidptr_t* )&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (voidptr_t* )&pIBus);

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
    pCMe = (CEcoMutex1Lab_90017215*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoMutex1Lab_90017215));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoMutex1Lab */
    pCMe->m_pVTblIMutex = &g_x9B964B0D168142E484388F332D4633F3VTbl_90017215;

    /* Инициализация данных */

    /* Возврат указателя на интерфейс */
    *ppIMutex = (IEcoMutex1Ptr_t)pCMe;

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
void ECOCALLMETHOD deleteCEcoMutex1Lab_90017215(/* in */ IEcoMutex1Ptr_t pIMutex) {
    CEcoMutex1Lab_90017215* pCMe = (CEcoMutex1Lab_90017215*)pIMutex;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIMutex != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

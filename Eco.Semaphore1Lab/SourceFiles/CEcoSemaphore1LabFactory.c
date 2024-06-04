/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoSemaphore1LabFactory
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию фабрики для компонента
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoSemaphore1Lab.h"
#include "CEcoSemaphore1LabFactory.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция возвращает указатель на интерфейс
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoComponentFactory) ) {
        *ppv = me;
    }
    else {
        *ppv = 0;
        return -1;
    }
    ((IEcoUnknown*)(*ppv))->pVTbl->AddRef((IEcoUnknown*)*ppv);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_AddRef(/* in */ IEcoComponentFactory* me) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;

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
 *   Функция уменьшает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_Release(/* in */ IEcoComponentFactory* me) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoSemaphore1Lab_7CD26E7CFactory(&pCMe->m_VtblICF);
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
 *   Функция инициализирует компонент с параметрами
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_Init(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pIUnkSystem, /* in */ void* pv) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Инициализация компонента */
    result = pCMe->m_pInitInstance(pv, pIUnkSystem);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Alloc
 * </сводка>
 *
 * <описание>
 *   Функция создает компонент
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_Alloc(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pISystem, /* in */ struct IEcoUnknown *pIUnknownOuter, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;
    IEcoUnknown* pIUnk = 0;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Агрегирование при условии если IID это IID_IEcoUnknown */
    if ( ( pIUnknownOuter != 0 ) && !IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        /* не поддерживает агрегирование */
        return -1;
    }

    /* Создание компонента */
    result = pCMe->m_pInstance(pISystem, pIUnknownOuter, (void**)&pIUnk);
    if ( result != 0 || pIUnk == 0) {
        return -1;
    }

    /* Инициализация компонента */
    result = me->pVTbl->Init(me, pISystem, pIUnk);
	
    /* Получение указателя на интерфейс */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, riid, ppv);

    /* Уменьшение ссылки запрошенной Фабрикой компонентов */
    pIUnk->pVTbl->Release(pIUnk);

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Name
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование компонента
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_get_Name(/* in */ struct IEcoComponentFactory* me) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция get_Version
 * </сводка>
 *
 * <описание>
 *   Функция возвращает версию компонента
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_get_Version(/* in */ struct IEcoComponentFactory* me) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Version;
}

/*
 *
 * <сводка>
 *   Функция get_Manufacturer
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование производителя компонента
 * </описание>
 *
 */
char_t* ECOCALLMETHOD CEcoSemaphore1Lab_7CD26E7CFactory_get_Manufacturer(/* in */ struct IEcoComponentFactory* me) {
    CEcoSemaphore1Lab_7CD26E7CFactory* pCMe = (CEcoSemaphore1Lab_7CD26E7CFactory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_x0741985B8FD0476C867CAE177CD26E7CFactoryVTbl = {
    CEcoSemaphore1Lab_7CD26E7CFactory_QueryInterface,
    CEcoSemaphore1Lab_7CD26E7CFactory_AddRef,
    CEcoSemaphore1Lab_7CD26E7CFactory_Release,
    CEcoSemaphore1Lab_7CD26E7CFactory_Alloc,
    CEcoSemaphore1Lab_7CD26E7CFactory_Init,
    CEcoSemaphore1Lab_7CD26E7CFactory_get_Name,
    CEcoSemaphore1Lab_7CD26E7CFactory_get_Version,
    CEcoSemaphore1Lab_7CD26E7CFactory_get_Manufacturer
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция 
 * </описание>
 *
 */
CEcoSemaphore1Lab_7CD26E7CFactory g_x0741985B8FD0476C867CAE177CD26E7CFactory = {
    &g_x0741985B8FD0476C867CAE177CD26E7CFactoryVTbl,
    0,
    (CreateInstance)createCEcoSemaphore1Lab_7CD26E7C,
    (InitInstance)initCEcoSemaphore1Lab_7CD26E7C,
    "EcoSemaphore1Lab\0",
    "1.0.0.0\0",
    "CompanyName\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_x0741985B8FD0476C867CAE177CD26E7CFactory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_0741985B8FD0476C867CAE177CD26E7C = (IEcoComponentFactory*)&g_x0741985B8FD0476C867CAE177CD26E7CFactory;
#endif
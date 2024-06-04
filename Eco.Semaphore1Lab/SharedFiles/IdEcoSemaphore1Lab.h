/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSemaphore1Lab
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSemaphore1Lab
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

#ifndef __ID_ECO_SEMAPHORE_1_LAB_H__
#define __ID_ECO_SEMAPHORE_1_LAB_H__

#include "IEcoBase1.h"
#include "IEcoSemaphore1.h"

/* EcoSemaphore1Lab CID = {0741985B-8FD0-476C-867C-AE177CD26E7C} */
#ifndef __CID_EcoSemaphore1Lab
static const UGUID CID_EcoSemaphore1Lab = {0x01, 0x10, {0x07, 0x41, 0x98, 0x5B, 0x8F, 0xD0, 0x47, 0x6C, 0x86, 0x7C, 0xAE, 0x17, 0x7C, 0xD2, 0x6E, 0x7C} };
#endif /* __CID_EcoSemaphore1Lab */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_0741985B8FD0476C867CAE177CD26E7C;
#endif

#endif /* __ID_ECO_SEMAPHORE_1_LAB_H__ */

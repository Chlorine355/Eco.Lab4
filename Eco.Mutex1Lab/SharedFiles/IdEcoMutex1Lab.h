/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoMutex1Lab
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoMutex1Lab
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

#ifndef __ID_ECO_MUTEX_1_LAB_H__
#define __ID_ECO_MUTEX_1_LAB_H__

#include "IEcoBase1.h"
#include "IEcoMutex1.h"

/* EcoMutex1Lab CID = {2F48BBCB-E488-4CC0-8ECF-C45990017215} */
#ifndef __CID_EcoMutex1Lab
static const UGUID CID_EcoMutex1Lab = {0x01, 0x10, {0x2F, 0x48, 0xBB, 0xCB, 0xE4, 0x88, 0x4C, 0xC0, 0x8E, 0xCF, 0xC4, 0x59, 0x90, 0x01, 0x72, 0x15} };
#endif /* __CID_EcoMutex1Lab */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_2F48BBCBE4884CC08ECFC45990017215;
#endif

#endif /* __ID_ECO_MUTEX_1_LAB_H__ */

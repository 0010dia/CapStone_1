//
// Created by 김종일/서비스클라이언트개발 on 2023/07/21.
//

#ifndef _NCVOICESCRIPT_H
#define _NCVOICESCRIPT_H

#include "sgl_inc.h"
#include "rgdata_inc.h"
#include "rg_def.h"
#include <map>

class NcVoiceScript {
    NOT_COPYABLE(NcVoiceScript);

public:
    Bool setScriptSet(map<E_TTS_LANGUAGE_TYPE, map<int, string>> scriptMap);
    Bool changeLanguage(E_TTS_LANGUAGE_TYPE newLanguage);
    int getScriptCount();

    // NcWavList.h에 정의된 IDG_XXX를 이용하여 접근한다.
    const char* getScriptByIndex(int scriptIndex);

private:
    DECLARE_SINGLETON(NcVoiceScript);

    NcVoiceScript(void);
    ~NcVoiceScript(void);
    int maxScriptCount;
    E_TTS_LANGUAGE_TYPE eLanguage = eKR;
    map<E_TTS_LANGUAGE_TYPE, map<int, string>> mTTSScriptMap;
    map<int, string> mCurrentLanguageScriptMap;
    string searchedScript;

    void useDefaultScript();
};


#endif //_NCVOICESCRIPT_H

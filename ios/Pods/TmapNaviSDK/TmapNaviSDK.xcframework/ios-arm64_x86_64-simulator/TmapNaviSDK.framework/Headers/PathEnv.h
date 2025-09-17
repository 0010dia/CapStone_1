// PathEnv.h

// 작성자 : 정인택
// 작성일 : 2008.02.04
// 설  명 :

#ifndef __PATHENV_H
#define __PATHENV_H

#include "sgl_inc.h"

enum PathEnvCacheType
{
    PET_CACHE_GUIDEDIC_DIR = 0,

    PET_GUIDE_VOICE_DIC,
    PET_GUIDE_VOICE_DIC_DB,
    PET_GUIDE_VOICE_DIC_STMDB,
    PET_GUIDE_VOICE_DIC_HIGHDB,
    PET_GUIDE_VOICE_DIC_TTS
};

enum PathEnvDataType
{
    PET_DATA_USER_DIR = 0,

    PET_ROUTE_TRACK,
    PET_TFS_RD
};

/*
 * @deprecated
 */
enum PathEnvLegacyType
{
    PET_FONTS,
    PET_ConfigDirectory,
    PET_CONFIG_MAP1,
    PET_CONFIG_MAP2,
    PET_CONFIG_MAP3,
    PET_CONFIG_MAP4,
    PET_CONFIG_2D_MAP1,
    PET_CONFIG_2D_MAP2,
    PET_CONFIG_2D_MAP3,
    PET_CONFIG_2D_MAP4,

    PET_RES_POI_A,
    PET_RES_POI_B,
    PET_RES_POI_C,

    PET_FONTS_A,
    PET_FONTS_B,
    PET_FONTS_C,

    PET_BACKUP,
    PET_RoadMap,
    PET_RG_LIA,
    PET_RG_ST_TOLL,

    PET_SDI_MESHINFO,
    PET_SDI_LOCAL_MESHINFO,
    PET_SDI_GUIDEPOINT,
    PET_SDI_LOCAL_GUIDEPOINT,
    PET_SSDI_PART,
    PET_TSDI_PART_IDX,
    PET_TSDI_PART,
    PET_SDI_FULL,

    PET_GUIDE_CONFIG,
    PET_GUIDE_CONFIG_TMP,

    PET_CROSSIMAGEIDX,
    PET_CROSSIMAGEIDX_FULL,
    PET_CROSSIMAGEIDXN,
    PET_CROSSIMAGEIDXN_FULL,
    PET_CROSSIMAGERES,
    PET_CROSSIMAGERES_FULL,
    PET_CROSSIMAGERESN,
    PET_CROSSIMAGERESN_FULL,

    PET_TVAS_Backup_Safe,
};

class CPathEnv
{
    friend class CEnvSet;

    //NOT_INSTANCE(CPathEnv)
    NOT_COPYABLE(CPathEnv)

private:
    CPathEnv();
    ~CPathEnv();

public :
    void SetCachePath(const Char* cachePath);
    void SetDataPath(const Char* dataPath);
    void SetLegacyRootPath(const Char* rootPath);

    const Char* GetCachePath() const { return m_cachePath; }
    const Char* GetDataPath() const { return m_dataPath; }
    const Char* GetLegacyRootPath() const { return m_legacyRootPath; }

private:
    Char m_cachePath[SGL_MAX_PATH];
    Char m_dataPath[SGL_MAX_PATH];
    Char m_legacyRootPath[SGL_MAX_PATH];

public:
    size_t GetPath(Char* dst, size_t dstSize, PathEnvCacheType pathType) const;
    size_t GetPath(Char* dst, size_t dstSize, PathEnvDataType pathType) const;
    size_t GetPath(Char* dst, size_t dstSize, PathEnvLegacyType pathType) const;

    Bool GetPath_MapConfig(Char* lpszPath, size_t nSize, Int32 nConfig);
    Bool GetPath_CrossConfig(Char* lpszPath, size_t nSize, Int32 nConfig);

    const Char* GetVoiceHost() const;
    const Char* GetVoiceDir() const;

    static const Char* StrToken(Char *pstrDst, const Char *pstrSrc, Int32 idx, Char ctoken);

public:
    void SetSTMHostName(const Char* lpszHostName);
    void SetSTMRootURL(const Char* lpszRootURL);
    void SetSTMMapVer(const Char* lpszMapVer);
    void SetSTMModelVer(const Char* lpszModelVer);
    void SetSTMTextureType(const Char* lpszTextureType);
    void SetSTMPortNo(UInt16 nPortNo);

    const Char* GetSTMHostName() const { return m_szSTMHostName; }
    const Char*	GetSTMRootURL() const { return m_szSTMRootURL; }
    const Char*	GetSTMMapVer () const { return m_szSTMMapVer; }
    const Char*	GetSTMModelVer() const { return m_szSTMModelVer; }
    const Char*	GetSTMTextureType() const { return m_szSTMTextureType; }
    UInt16 GetSTMPortNo() const { return m_nSTMPort; }

private:
    Char    m_szSTMHostName[SGL_MAX_PATH];
    Char    m_szSTMRootURL[SGL_MAX_PATH];
    Char    m_szSTMMapVer[SGL_MAX_PATH];
    Char    m_szSTMModelVer[SGL_MAX_PATH];
    Char    m_szSTMTextureType[SGL_MAX_PATH];
    UInt16  m_nSTMPort;

    Char    m_szVoiceHost[SGL_MAX_PATH];
    Char    m_szVoiceDir[SGL_MAX_PATH];
};

#endif // __PATHENV_H

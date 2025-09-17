//
//  SafeDriveInfomation.h
//  RouteGuidance
//
//  Created by 한영창 on 2020. 1. 3..
//

#ifndef SafeDriveInfomation_h
#define SafeDriveInfomation_h

#include "LocalLinkV2.h"
#include "mapmatch_def.h"

class CSafeDriveInfomation
{
public:
    CSafeDriveInfomation();
    virtual ~CSafeDriveInfomation();

public:
    Bool GetSDIInfo(TVS_Data *m_pTvasData, stGatheringData *m_pGatherData, Int32 nRouteIndex, NsMatchingData *pMMData, stDriveInfo *pstInfo, Bool bSimulator);
    Bool GetAndoSDIInfo(NsMatchingData *pMMData, LocalLinkV2* pLocalLinkV2, stDriveInfo *pstInfo, SGL_mutex* m_safeDriveLock);
    void initSdiData(Bool bStartRGService);

protected:
    SdiBlockStepType nSdiBlockStep;

private:
    Int32 SetNextSdi(const TVS_Data *pTvasData, Int32 nRouteIndex, Int32 nIdxFind, Int32 lengthtoend, stDriveInfo *pstInfo);
    void MakeSDIPlusInfo(stSDIInfo *pSDIInfo, NsMatchingData *pMMData, stDriveInfo *pstInfo, Int32 nSDIPlusCnt, Int32 nDist);
    time_t ConvertGPSNmeaDay();
    UInt32 ConvertGPSNmeaMillisecond();
    Int32 PriorityCheck(SDI_Type type);
    void AddSDIShadeAreaDistance(Int32 distanceToEnd);
    Bool SdiTimeOutCheck(TVS_Data *m_pTvasData, stSDIInfo *pSDIInfo);
    Int32 GetSdiTypeGuideDist(stSDIInfo *pSDIInfo, UInt8 uRoadCate);


    Bool needToRefresh;

    Int32 sdiLastAverageSpeed;
    double sdiDistanceSum;
    Int32 sdiRouteIndex;
    Int32 shadeAreaLinkDist;
    Int32 sdiLinkLength;
    Int32 prevShadeAreaDistanceToEnd;
    Int32 lastPassedSdiBlockEndIndex;   // 마지막으로 지난 구간단속 종료지점 index

    bool getSdiInfo(const TVS_Data *pTvasData, Int32 nRouteIndex, stSDIInfo& sdiInfo);
    Int32 getMaxSdiIndex(const TVS_Data *pTvasData, Int32 nRouteIndex, SdiBlockStepType blockSpeedStep);
    void getNextSdiInfo(const TVS_Data *pTvasData, Int32 dbIndex, stSDIInfo& sdiInfo, Bool isContinue);
};

#endif /* SafeDriveInfomation_h */

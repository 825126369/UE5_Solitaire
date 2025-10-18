// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameData.generated.h"

/**
 * 
 */
UCLASS()
class UE5_SOLITAIRE_API UGameData : public USaveGame
{
	GENERATED_BODY()
public:
    FString langName;
    int  nUIStyle = 0;
    int nCoinCount = 0;
    int nNomalModeTotalWinCount = 0;
    int nTotalGameCount = 0;
    int nTotalWinGameCount = 0;
    //TArray<int> tableOpRecord = {};
    //int RecoverGameData = {};

    //data.DailyChallengeData = {}
    //    data.StatisticData = {}
    //    data.ThemeData = {}
    //    data.DailyTaskData = {}
    //    data.CollectPokerTaskData = {}
    //    data.StampData = {}
    //    data.StageRewardData = {}
    //    data.TripData = {}
    //    data.DailyRankData = {}
    int nMagicWandCount = 0; //魔杖数量
    bool bOpenSound = true;
    bool bAutoComplete = true;
    bool bClickToMove = true;
    bool bAutoHint = false;
    bool bFastGame = false;
    int nDrawCount = 1;
    bool bIQMode = false;
    bool bLeftHandMode = false;
    int nMusicIndex = 0;
    int nDifficultLayer = 1; //难度等级 1～10
    int nDifficultLayer_ContinueWinCount = 0;
    int nDifficultLayer_ContinueLoseCount = 0;
    int nGameLevel = 0; //等级
    int mStageReward_WinCount = 0;
    int nIQValue = 100;
};

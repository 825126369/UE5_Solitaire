// Fill out your copyright notice in the Description page of Project Settings.


#include "InitSceneMgr.h"

// Sets default values
AInitSceneMgr::AInitSceneMgr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInitSceneMgr::BeginPlay()
{
	Super::BeginPlay();
    this->LoadUIAsset(FPrimaryAssetId(FName("UIAsset"), FName("DA_MainHUD")));
}

// ÿ֡ Tick����ʱ��������ѯ
void AInitSceneMgr::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (LoadingHandle.IsValid() && LoadingHandle->IsLoadingInProgress())
    {
        float Percent = LoadingHandle->GetProgress();          // 0.0~1.0
        int32 Loaded, Requested;
        LoadingHandle->GetLoadedCount(Loaded, Requested);    // �Ѽ��� / ����
        UE_LOG(LogTemp, Log, TEXT("UI AInitSceneMgr Loading: %.0f %%(%d / %d)"), Percent * 100.f, Loaded, Requested);
    }
}

// ��ʼ����
void AInitSceneMgr::LoadUIAsset(FPrimaryAssetId AssetId)
{
    UAssetManager& AM = UAssetManager::Get();
    LoadingHandle = AM.LoadPrimaryAsset(
        AssetId, 
        TArray<FName>{TEXT("UI")},
        FStreamableDelegate::CreateUObject(this, &AInitSceneMgr::OnAssetLoadCompleted),
        FStreamableManager::DefaultAsyncLoadPriority
    );
}

void AInitSceneMgr::OnAssetLoadCompleted()
{
    UE_LOG(LogTemp, Log, TEXT("=== ���� UI �ʲ�������� ==="));
    LoadingHandle.Reset();
}


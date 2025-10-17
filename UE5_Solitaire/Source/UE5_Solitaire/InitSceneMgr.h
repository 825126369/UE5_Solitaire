// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InitSceneMgr.generated.h"

UCLASS()
class UE5_SOLITAIRE_API AInitSceneMgr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInitSceneMgr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadUIAsset(FPrimaryAssetId AssetId);
	void OnAssetLoadCompleted();
	// 头文件里存句柄
	TSharedPtr<FStreamableHandle> LoadingHandle;
};

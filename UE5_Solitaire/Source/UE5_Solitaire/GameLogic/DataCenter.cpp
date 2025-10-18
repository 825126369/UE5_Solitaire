#include "DataCenter.h"

void DataCenter::Init(InitFinishFunc func = NULL)
{
	this->mInitFinishFunc = func;
	this->LoadData();
}

void DataCenter::LoadData()
{
	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	LoadedDelegate.BindUObject(this, &DataCenter::OnLoadDataComplete);
	UGameplayStatics::AsyncLoadGameFromSlot(DataCenter::DATA_SLOT_NAME, DataCenter::DATA_USER_INDEX, LoadedDelegate);
}

void DataCenter::OnLoadDataComplete(const FString& SlotName, const int32 UserIndex, USaveGame* SaveGameInstance)
{
	if (SaveGameInstance != NULL)
	{
		this->data = Cast<UGameData>(SaveGameInstance);
	}
	else
	{
		this->data = Cast<UGameData>(UGameplayStatics::CreateSaveGameObject(UGameData::StaticClass()));
	}

	if (this->mInitFinishFunc != NULL)
	{
		this->mInitFinishFunc();
	}
}

void DataCenter::SaveData()
{
	FAsyncSaveGameToSlotDelegate SavedDelegate;
	SavedDelegate.BindUObject(this, &DataCenter::OnSaveDataComplete);
	UGameplayStatics::AsyncSaveGameToSlot(this->data, DataCenter::DATA_SLOT_NAME, DataCenter::DATA_USER_INDEX, SavedDelegate);
}

void DataCenter::OnSaveDataComplete(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	if (bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("SaveGameAsync completed successfully."));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("SaveGameAsync failed."));
	}
}

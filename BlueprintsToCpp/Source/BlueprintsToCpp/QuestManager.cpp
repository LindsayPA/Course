// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("quest manager construct"));
}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("quest manager begin play"));
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("quest manager tick"));

}

void AQuestManager::CompleteQuest_Implementation(FName QuestId, bool CompleteWholeQuest)
{
	int32 QuestIndex = GetQuestIndex(QuestId); 
	FQuestInfo Quest = QuestList[QuestIndex]; 
	if (CompleteWholeQuest)
	{
		QuestList[QuestIndex].Progress = Quest.ProgressTotal;
	}
	else
	{
		QuestList[QuestIndex].Progress = FMath::Min(Quest.Progress + 1, Quest.ProgressTotal); 
	}

	//LESSON 16 BROADCASTING
	CompletedQuest.Broadcast(QuestIndex); 
}

FQuestInfo AQuestManager::GetQuest(FName Name) const
{
	return QuestList[GetQuestIndex(Name)];
}

//bool AQuestManager::IsActiveQuest(FName QuestId) const
//{
	//return false;
//}

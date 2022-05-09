// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Creating components in c++ - Particle system
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	SetRootComponent(Root); 
	ParticleSystem->SetupAttachment(Root); 
}




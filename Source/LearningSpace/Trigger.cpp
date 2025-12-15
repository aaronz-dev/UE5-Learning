// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"

UTrigger::UTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTrigger::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tigger is alive"));
	// ...
	OnComponentBeginOverlap.AddDynamic(this, &UTrigger::OnOverlapBegin);
}

void UTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	// Runs once when something enters
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	if (Actors.Num() > 0)
	{
		for (AActor* Actor : Actors)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s is overlapping"), *Actor->GetActorNameOrLabel());
		}
	}
}


// Called every frame
//void UTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//	TArray<AActor*> Actors;
//	GetOverlappingActors(Actors);
//	if (Actors.Num() > 0)
//	{
//		for (AActor* Actor : Actors)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("%s is overlapping"), *Actor->GetActorNameOrLabel());
//		}
//	}
//
//}
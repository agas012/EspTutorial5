// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <random>
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Dice.generated.h"

UCLASS()
class ESPTUTORIAL5_API ADice : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADice();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	std::random_device random_device;
	std::mt19937 engine{ random_device() };

	//random dices range
	std::uniform_int_distribution<int> dice_six;
	std::uniform_int_distribution<int> dice_twelve;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//dice throws functions
	int throw_dice_six();
	int throw_dice_twelve();
	int diceval;
};

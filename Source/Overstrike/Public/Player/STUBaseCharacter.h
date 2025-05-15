// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class USTUHealthComponent;
class UTextRenderComponent;

UCLASS()
class OVERSTRIKE_API ASTUBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASTUBaseCharacter(const FObjectInitializer& ObjInit);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTUHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* HealthTextComponent;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool isRunning() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMovementDirection() const;

private:
	bool wantsToRun = false;
	bool isMovingForward = false;

	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void LookUp(float Amount);
	void TurnAround(float Amount);

	void OnStartRunning();
	void OnStopRunning();
};

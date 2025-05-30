// Overstrike game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUGameHUD.generated.h"
	
UCLASS()
class OVERSTRIKE_API ASTUGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

	virtual void BeginPlay() override;
private:
	void DrawCrossHair();
	
};

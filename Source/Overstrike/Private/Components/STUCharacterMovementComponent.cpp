// Overstrike game. All rights reserved.


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h" 

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
	return Player && Player-> isRunning() ? MaxSpeed * RunModifier: MaxSpeed;
}
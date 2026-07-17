#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "VehiclePawn.generated.h"

UCLASS()
class TECHNICALTEST_API AVehiclePawn : public APawn
{
	GENERATED_BODY()

public:
	AVehiclePawn();

protected:
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* -------------------- COMPONENTS -------------------- */
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	/* -------------------- INPUT ACTIONS -------------------- */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveRightAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* LookAction;
	
	/* -------------------- VEHICLE SETTINGS -------------------- */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float Acceleration = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float MaxSpeed = 3000.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float SteeringAngle = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float SteeringSpeed = 9.f;
	
	/* -------------------- RUNTIME STATE -------------------- */
	UPROPERTY(BlueprintReadOnly)
	float CurrentSpeed = 0.f;
	
	UPROPERTY(BlueprintReadOnly)
	float CurrentSteering = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	float WheelRoll = 0.f;

	float ForwardInput = 0.f;
	float SteeringInput = 0.f;

	
	
	
public:
	/* -------------------- INPUT CALLBACKS -------------------- */
	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
	
	
};

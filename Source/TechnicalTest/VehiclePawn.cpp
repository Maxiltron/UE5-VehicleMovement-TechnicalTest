#include "VehiclePawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"

AVehiclePawn::AVehiclePawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Components
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = Mesh;

    Movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

    SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);
}

void AVehiclePawn::BeginPlay()
{
    Super::BeginPlay();
}

void AVehiclePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    /* -------------------- ACCÉLÉRATION -------------------- */
    CurrentSpeed += ForwardInput * Acceleration * DeltaTime;
    CurrentSpeed = FMath::Clamp(CurrentSpeed, -MaxSpeed, MaxSpeed);

    //* -------------------- FRICTION / FREIN MOTEUR -------------------- */
    CurrentSpeed = FMath::FInterpTo(CurrentSpeed, 0.f, DeltaTime, 0.2f);
    
    if (ForwardInput == 0.f)
    {
        CurrentSpeed = FMath::FInterpTo(CurrentSpeed, 0.f, DeltaTime, 10.f);
    }

    /* -------------------- DIRECTION / VOLANT -------------------- */
    CurrentSteering = FMath::FInterpTo(
        CurrentSteering,
        SteeringInput * SteeringAngle,
        DeltaTime,
        SteeringSpeed
    );
    
    float SpeedFactor = FMath::Abs(CurrentSpeed) / MaxSpeed;
    float RotationAmount = CurrentSteering * SpeedFactor;
    
    // Inverse si marche arrière
    if (CurrentSpeed < 0.f)
    {
        RotationAmount *= -1.f;
    }
    
    AddActorLocalRotation(FRotator(0.f, RotationAmount * DeltaTime, 0.f));
    
    /* -------------------- DÉPLACEMENT -------------------- */
    FVector Forward = GetActorForwardVector();
    FVector MoveDirection = (CurrentSpeed >= 0.f) ? Forward : -Forward;
    
    AddActorWorldOffset(MoveDirection * FMath::Abs(CurrentSpeed) * DeltaTime, true);
}


void AVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Enhanced Input Component
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInput->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AVehiclePawn::MoveForward);
        EnhancedInput->BindAction(MoveForwardAction, ETriggerEvent::Completed, this, &AVehiclePawn::MoveForward);

        EnhancedInput->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AVehiclePawn::MoveRight);
        EnhancedInput->BindAction(MoveRightAction, ETriggerEvent::Completed, this, &AVehiclePawn::MoveRight);

        EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Look);
    }
}

void AVehiclePawn::MoveForward(const FInputActionValue& Value)
{
    ForwardInput = Value.Get<float>();
}

void AVehiclePawn::MoveRight(const FInputActionValue& Value)
{
    SteeringInput = Value.Get<float>();
}

void AVehiclePawn::Look(const FInputActionValue& Value)
{
    const FVector2D AxisValue = Value.Get<FVector2D>();
    
    // Pour une sensi plus faible
    AddControllerYawInput(AxisValue.X  * 0.5f);
    AddControllerPitchInput(AxisValue.Y * 0.5f);
}

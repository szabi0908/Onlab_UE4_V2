// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMain_Character::AMain_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 10.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 20;


	bDead = false;
	Hunger = 100.0f;

}

// Called when the game starts or when spawned
void AMain_Character::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMain_Character::OnBeginOverlap);
	
	if (Player_Hunger_Widget_Class != nullptr)
	{
		Player_Hunger_Widget = CreateWidget(GetWorld(), Player_Hunger_Widget_Class);
		Player_Hunger_Widget->AddToViewport();
	}
}

// Called every frame
void AMain_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Hunger -= DeltaTime * Hunger_Treshold;

	if (Hunger <= 0)
	{
		if (!bDead)
		{
			bDead = true;

			GetMesh()->SetSimulatePhysics(true);
			
			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMain_Character::RestartGame, 3.0f, false);
		}
	}
}

// Called to bind functionality to input
void AMain_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMain_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain_Character::MoveRight);
}



void AMain_Character::MoveForward(float Axis)
{
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);
	}
}

void AMain_Character::MoveRight(float Axis)
{
	if (!bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

void AMain_Character::RestartGame()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);

}

void AMain_Character::UseItem(UItem* Item)
{
	if(Item)
	{
		Item->Use(this);
		Item->OnUse(this); //BP event!!!!!
	}
}


void AMain_Character::OnBeginOverlap(UPrimitiveComponent* HitComp,AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor->ActorHasTag("Recharge"))
	{
		
		//Inventory->AddItem(OtherActor);
		Hunger += 10.0f;

		if (Hunger > 100.0f)
		{
			Hunger = 100;
		}

		OtherActor->Destroy();

	}

}
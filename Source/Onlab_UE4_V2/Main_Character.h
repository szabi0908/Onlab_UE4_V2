// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Gameframework/SpringArmComponent.h"
#include "Blueprint/UserWidget.h"
#include "Onlab_UE4_V2/Items/Item.h"
#include "Onlab_UE4_V2/Items/InventoryComponent.h"
#include "Onlab_UE4_V2/Items/FoodItem.h"
#include "Main_Character.generated.h"

UCLASS()
class ONLAB_UE4_V2_API AMain_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain_Character();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory, meta= (AllowPrivateAcess= "true"))
		class UInventoryComponent* Inventory;

	void MoveForward(float Axis);

	void MoveRight(float Axis);

	bool bDead;

	UPROPERTY(BlueprintReadOnly,  Category="Health")
		float Hunger;

	UPROPERTY(EditAnywhere, Category = "Food")
		UFoodItem* food1;

	

	UFUNCTION(BlueprintCallable, Category = "Items")
		void UseItem(class UItem* Item);

	UPROPERTY(EditAnywhere)
		float Hunger_Treshold;

	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> Player_Hunger_Widget_Class;
		UUserWidget* Player_Hunger_Widget;

	void RestartGame();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealityRoomInput.generated.h"

USTRUCT(BlueprintType)
struct REALITYROOM_API FRealityRoomInput
{
        GENERATED_BODY()

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float MoveForward;

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float MoveRight;

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float LookUp;

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float TurnRight;

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        bool Jump;

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        bool Interact;

        UPROPERTY(BlueprintReadWrite, EditAnywhere)
        float Timestamp;
};